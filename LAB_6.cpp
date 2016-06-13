#include <iostream>
#include <cstdlib>
#include <cmath>
#include<memory>
#include <algorithm>
using namespace std;
/*
class compx
{
private:
	int di, mn; // di - целая , mn - мнимая
public:
	int get_di() {
		return di;
	}
	int get_mn() {
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
	compx(compx &i) { // конструктор copy
		di = i.di;
		mn = i.mn;
	}
	~compx() {}

	compx & operator=  (compx &i) { // перегрузка присваивания
		di = i.di;
		mn = i.mn;
		return (*this);
	}
	compx & operator=  (const compx &i) { // перегрузка присваивания
		di = i.di;
		mn = i.mn;
		return (*this);
	}
	compx operator * (compx &i)// перегрузка произведения 
	{
		compx tm;
		tm.di = di*i.di;
		tm.mn = di*i.mn;
		return tm;
	}
	compx operator + (compx &i) // перегрузка сложения
	{
		compx tm;
		tm.di = di + i.di;
		tm.mn = di + i.mn;
		return tm;
	}
	compx operator + (const compx &i) // перегрузка сложения
	{
		compx tm;
		tm.di = di + i.di;
		tm.mn = di + i.mn;
		return tm;
	}
};
*/
template <typename T>
class matrix {
	T** A;
	int M;
	int N;
public:
	matrix<T>(int m, int n) : A(NULL), M(m), N(n)
	{
		A = new T*[M]; //строки в массиве
		for (int i = 0; i < M; i++)
		{
			A[i] = new T[N]; //  столбцы
			for (int j = 0; j < N; j++)
				A[i][j] = 0;
		}
	}
	T& operator () (int i, int j) // перегрузка оператора обращение к элементу ()
	{
		return A[i][j];
	}

	int m() { return M; };
	int n() { return N; };


	void print()
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
				cout << A[i][j] << " | ";
			cout << endl;
		}
		cout << endl;
	}
	T get(int M, int N) {
		return A[M][N];
	}
	void set(int M, int N, int rez) {
		return A[M][N] = rez;
	}
	~matrix<T>()
	{

	}
	class iterator
	{
	private:
		matrix* pmat;
		int position_M;
		int position_N;
	public:
			iterator& operator++() {
				if (position_N == N - 1) {
					position_M++;
					position_N = 0;
					
				}
				else
					{
						position_N++;
					}
				return *this;
				
			}
			bool operator!=(const iterator& prev_it) {
				return !(position_M == prev_it.position_M && position_N == prev_it.position_N);
				
			}
			iterator(matrix* pmat, int position_M, int position_N) {
				this->pmat = pmat;
				this->position_M = position_M;
				this->position_N = position_N;
				
			}
			T operator*() {
				return pmat->get(position_M, position_N);
				
			}
			T* operator->() {
				return *pmat->get(position_M, position_N);
				
			}
	};
	iterator begin() {
		iterator temp(this, 0, 0);
		return temp;
	}
	iterator end() {
		iterator temp(this, M, 0);
		return temp;
	}
};


template <typename T> matrix<T> operator+(matrix<T>& M1, matrix<T>& M2)//перегрузка сложения матриц
{
	matrix<T> L(M1.m(), M1.n());
	for (int i = 0; i < M1.m(); i++)
	{
		for (int j = 0; j < M1.n(); j++)
		{
			L(i, j) = M2(i, j) + M1(i, j);
		}
	}
	return L;
}
template <typename T>  matrix<T> operator*(matrix<T>& M1, matrix<T>& M2)//перегрузка перемножения матриц
{
	if (M1.n() != M2.m())
		throw "dont true size";
	matrix<T> Q(M1.m(), M1.n());
	for (int i = 0; i < M1.m(); i++)
	{
		for (int j = 0; j < M1.n(); j++)
		{
			for (int t = 0; t < M1.n(); t++)
			{
				Q(i, j) = Q(i, j) + (M1(i, t) * M2(t, j));
			}
		}
	}
	return Q;
}

template <typename T> matrix<T> operator~(matrix<T>& M1)//перегрузка транспонирования матрицы
{
	matrix<T> L(M1.n(), M1.m());
	for (int i = 0; i < M1.m(); i++)
	{
		for (int j = 0; j < M1.n(); j++)
		{
			L(j, i) = M1(i, j);
		}
	}
	return L;
}

// отдельный класс для реализации shared_ptr
class Bar;
class Foo
{
public:
	Foo() 
	{
		cout << "Foo()" << endl; 
	}
	~Foo() 
	{
		cout << "~Foo()" << endl; 
	}
	shared_ptr<Foo> foo;
	
};

class Bar
{
public:
	Bar() 
	{
		cout << "Bar()" << endl;
	}
	~Bar() 
	{
		cout << "~Bar()" << endl; 
	}
	shared_ptr<Bar> bar;
};
int main()
{
	matrix <int> A(3, 2);  
	A(0, 0) = 7;
	A(0, 1) = 5;
	A(1, 0) = 3;
	A(1, 1) = 1;
	A(2, 0) = 6;
	A(2, 1) = 7;

	matrix <int> B(2, 2);
	B(0, 0) = 3;
	B(0, 1) = 1;
	B(1, 0) = 9;
	B(1, 1) = 6;

	matrix <int> X(3, 2);
	X(0, 0) = 3;
	X(0, 1) = 6;
	X(1, 0) = 5;
	X(1, 1) = 1;
	X(2, 0) = 2;
	X(2, 1) = 2;

	cout << "Matrica A: " << endl;
	A.print();
	cout << "Matrica B: " << endl;
	B.print();
	cout << "Matrica X: " << endl;
	X.print();
	matrix <int> C(2, 2);
	C = A + X;//сложение матриц
	cout << "Matrica A+F: " << endl;
	C.print();
	matrix <int> O(2, 2);
	O = A * B;//перемножение матриц
	cout << "Matrica A*B: " << endl;
	O.print();
	matrix <int> E(2, 2);
	E = ~A;//транспонирование матрицы
	cout << "Transponir matr A: " << endl;
	E.print();
	try // исключение
	{
		O = A * X;
		O.print();
	}
	catch (const char * z)
	{
		cout << "iskl for * " << z << endl;
	}
	cout << endl;
	auto it = A.begin();
	cout << "iteration C: " << endl;
	for (; it != A.end(); ++it) {
		cout << *it << endl;
	}
	// main код реализации shared_ptr
	auto foo = make_shared<Foo>();
	foo->~Foo();
	auto bar = make_shared<Bar>();
	bar->~Bar();
	system("pause");
	return 0;
}
