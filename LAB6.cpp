#include <iostream>
#include "ctime"
#include <memory>
#include <algorithm>
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
using namespace std;

template <class T, int m, int n>
class matrix {
private:
	T **mat;
public:
	matrix<T, m, n>();
	matrix(matrix &matr) {
		mat = new T*[m];
		for (int i = 0; i < m; i++)
		{
			mat[i] = new T[n];
			for (int j = 0; j < n; j++) {
				set(i, j, matr.get(i, j));
			}
		}

	}
	~matrix();


	const void operator=(const matrix<T, m, n>& mat);

	template <class U = T, int m2 = n, int n2>
	matrix<T, m, n2> operator*(matrix<U, m2, n2>& mat);   // умножение матриц

	T get(int m, int n); // получение матрицы 

	template <class U = T, int m2 = m, int n2, int n3 = n + n2>

	matrix<U, m2, n3> operator|(matrix<U, m2, n2>& mat); // конкатенация матриц

	void set(int m_in, int n_in, T set); // установка значений матрицы
	void print(); // метод печати матрицы 


	class iterator // Forward-итератор доступа к элементам матрицы
	{ 
		matrix* pmat;
		int position_M, position_N;
	public:
		iterator& operator++() {
			if (position_N == n - 1) {
				position_M++;
				position_N = 0;
			}
			else
			{
				pos_n++;
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
		iterator temp(this, m, 0);
		return temp;
	}
};
template <class T, int m, int n>
matrix<T, m, n>::matrix() { // конструктор без параметров (инициализация матрицы) 
	mat = new T*[m];
	for (int i = 0; i < m; i++)
	{
		mat[i] = new T[n];
	}
}

template <class T, int m, int n> // получение элемента матрицы
T matrix<T, m, n>::get(int m, int n) {
	return mat[m][n];
}

template <class T, int m, int n>
const void matrix<T, m, n>::operator=(const matrix<T, m, n>& mat) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			set(i, j, mat.get(i, j));
		}
	}
}

template <class T, int m, int n>
void matrix<T, m, n>::set(int m_in, int n_in, T set) { // метод установки значений матрицы
	mat[m_in][n_in] = set;
}

template <class T, int m, int n>
template <class U = T, int m2 = n, int n2>
matrix<T, m, n2> matrix<T, m, n>::operator*(matrix<U, m2, n2>& mat) // реализация перегрузки умножения матриц
{
	matrix<T, m, n2> temp; 
	T tempvalue; 
	{
		for (int i = 0; i < m; i++) //m1
			for (int j = 0; j < n2; j++) //n2
			{
				tempvalue = 0;
				for (int k = 0; k < n; k++) //n1
				{
					tempvalue = tempvalue + (get(i, k) * mat.get(k, j));
				}
				temp.set(i, j, tempvalue);
			}
	}
	return temp;
}

template <class T, int m, int n> 
void matrix<T, m, n>::print() { // реализация метода печати матрицы 
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << get(i, j);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

template <class T, int m, int n>
template <class U = T, int m2 = m, int n2, int n3 = n + n2>
matrix<U, m2, n3> matrix<T, m, n>::operator|(matrix<U, m2, n2>& mat) { // конкатенация матриц (выполнение перегрузки) 
	matrix<U, m2, n3> temp;
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < n; j++) {
			temp.set(i, j, get(i, j));
		}
		for (int k = n; k < n + n2; k++) {
			temp.set(i, k, mat.get(i, k - n));
		}
	}
	return temp;
}

template <class T, int m, int n>
matrix<T, m, n>::~matrix() { // подчищение памяти в деструкторе класса 
	for (int i = 0; i < m; i++)
	{
		delete mat[i];
	}
	delete mat;
}

int main()
{
	matrix<int, 2, 1> M1;
	M1.set(0, 0, 1);
	M1.set(1, 0, 3);
	cout << "First matrix: " << endl;
	M1.print();
	cout << endl;
	matrix<int, 1, 2> N;
	N.set(0, 0, 4);
	N.set(0, 1, 3);
	cout << "Second matrix: " << endl;
	N.print();
	cout << endl;
	matrix<int, 2, 2> 
	Q = M1*N;
	cout << "Matrix multiplication: " << endl;
	Q.print();
	cout << endl;
	matrix<int, 2, 1> M2;
	M2.set(0, 0, 11);
	M2.set(1, 0, 31);
	matrix<int, 2, 2> 
	konk = M1 | M2;
	cout << "Concatenation of matrix: " << endl;
	konk.print();
	cout << endl;
	cout << "Access matrix elements via an iterator: " << endl;
	auto it = konk.begin();
	for (; it != konk.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}
