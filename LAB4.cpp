#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

class compx
{
private:
	// это не все комплексные, но неважно
	int di, mn; // di - целая , mn - мнимая
public:
	int get_di() { // const method
		return di;
	}
	int get_mn() { // const method
		return mn;
	}
	compx() {};
	compx(int d) {
		di = d;
		mn = 0;
	}
	compx(int d, int m) {
		di = d;
		mn = m;
	}
	// copy ctor может быть так сгенерирован и компилятором. Зачем писать больше?
	compx(compx &i) { // конструктор copy // const reference
		di = i.di;
		mn = i.mn;
	}
	~compx() {}

	// сгенерирован компилятором
	compx & operator=  (compx &i) { // перегрузка присваивания
		di = i.di;
		mn = i.mn;
		return (*this);
	}

	// алгоритмическая ошибка
	compx compx :: operator * (compx &i)// перегрузка произведения  // const method, const param
	{
		compx tm;
		tm.di = di*i.di;
		tm.mn = di*i.mn;
		return tm;
	}
	compx compx :: operator + (compx &i) // перегрузка сложения // const method, const param
	{
		compx tm;
		tm.di = di + i.di;
		tm.mn = di + i.mn; // тут тоже логическая ошибка
		return tm;
	}
};

class matrix {
	compx** A;
	int M;
	int N;
public:
	matrix(int m, int n) : A(NULL), M(m), N(n)
	{
		A = new compx*[M]; //строки в массиве
		for (int i = 0; i < M; i++)
		{
			A[i] = new compx[N]; //  столбцы
			for (int j = 0; j < N; j++)
				A[i][j] = compx(0, 0);
		}
	}
	compx& operator () (int i, int j) // перегрузка оператора обращение к элементу ()
	{
		return A[i][j];
	}

	friend matrix operator+(matrix& s1, matrix& s2);
	friend matrix operator*(matrix& s1, matrix& s2);
	friend matrix operator~(matrix& s1);

	void print()
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
				cout << A[i][j].get_di() << ", " << A[i][j].get_mn() << " | "; // почему бы не перегрузить вывод для compx?
			cout << endl;
		}
		cout << endl;
	}


	~matrix()
	{
		// здесь надо что-то делать, иначе утечка памяти
	}

};

matrix operator+(matrix& M1, matrix& M2)//перегрузка сложения матриц
{
	matrix L(M1.M, M1.N);
	// что делать, если размеры матриц-операндов разные?
	for (int i = 0; i < M1.M; i++)
	{
		for (int j = 0; j < M1.N; j++)
		{
			L(i, j) = M2(i, j) + M1(i, j);
		}
	}
	return L;
}

matrix operator*(matrix& M1, matrix& M2)//перегрузка перемножения матриц // const reference as param type
{
	if (M1.N != M2.M)
		throw "dont true size"; // лучше выбрасывать объекты типа исключения (специальный класс)
	matrix Q(M1.M, M1.N);

	for (int i = 0; i < M1.M; i++)
	{
		for (int j = 0; j < M1.N; j++)
		{
			for (int t = 0; t < M1.N; t++)
			{
				Q(i, j) = Q(i, j) + (M1(i, t) * M2(t, j));
			}
		}
	}
	return Q;
}

matrix operator~(matrix& M1)//перегрузка транспонирования матрицы
{
	matrix L(M1.N, M1.M);
	for (int i = 0; i < M1.M; i++)
	{
		for (int j = 0; j < M1.N; j++)
		{
			L(j, i) = M1(i, j);
		}
	}
	return L;
}

int main()
{
	compx value1(1, 7);
	compx value2(6, -2);

	matrix A(3, 2);        // До запятой целай часть числа , а потом мнимая
	A(0, 0) = compx(2, 3);
	A(0, 1) = compx(1, 1);
	A(1, 0) = compx(0, 1);
	A(1, 1) = compx(3, 4);
	A(2, 0) = compx(0, 0);
	A(2, 1) = compx(1, 3);

	matrix B(2, 2);
	B(0, 0) = compx(1, 5);
	B(0, 1) = compx(3, 3);
	B(1, 0) = compx(6, 1);
	B(1, 1) = compx(1, 0);

	matrix X(3, 2);
	X(0, 0) = compx(2, 2);
	X(0, 1) = compx(1, 3);
	X(1, 0) = compx(7, 3);
	X(1, 1) = compx(2, 1);
	X(2, 0) = compx(0, 0);
	X(2, 1) = compx(1, 1);

	cout << "Matrica A: " << endl;
	A.print();
	cout << "Matrica B: " << endl;
	B.print();
	cout << "Matrica X: " << endl;
	X.print();
	matrix C(2, 2);
	C = A + X;//сложение матриц
	cout << "Matrica A+F: " << endl;
	C.print();
	matrix O(2, 2);
	O = A * B;//перемножение матриц
	cout << "Matrica A*B: " << endl;
	O.print();
	matrix E(2, 2);
	E = ~A;//транспонирование матрицы
	cout << "Transponir matr A: " << endl;
	E.print();
	try // исключение
	{
		O = A * X;
		O.print();
	}
	catch (char*& z) // лучше весь код main обернуть в try-catch
	{
		cout << "iskl for * " << z << endl;
	}
	cout << endl;

	cout << " di " << value1.get_di() << " mn ";
	cout << value1.get_mn() << endl;
	cout << " di " << value2.get_di() << " mn ";
	cout << value2.get_mn() << endl;

	system("pause");
	return 0;
}
