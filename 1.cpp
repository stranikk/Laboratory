#include "stdafx.h"
#include <iostream>

using namespace std;
class compx 
{
private:
	int di ,mn; // di - целая , mn - мнимая
public :
	int get_di(){
	return di;
	}
	int get_mn(){
	return mn;
	}
	compx() {};
	compx (int d) {
	di = d;
	mn=0;
	}
	compx (int d, int m) {
	di=d;
	mn=m;
	}
	compx(compx &i) { // конструктор copy
		di=i.di;
		mn=i.mn;
	}
	~compx(){}

	compx & operator=  (compx &i){ // перегрузка присваивания
	di=i.di;
	mn=i.mn;
	return (*this);
	}
	compx compx :: operator * (compx &i)// перегрузка произведения 
	{
	compx tm;
		tm.di=di*i.di;
		tm.mn=di*i.mn;
		return tm;
	}
	compx compx :: operator + (compx &i) // перегрузка сложения
	{
	compx tm;
		tm.di=di+i.di;
		tm.mn=di+i.mn;
		return tm;
	}
};
int main()
{
	compx a(1,10);
	compx b(2,12);
	cout << a.get_di() <<endl;
	cout << a.get_mn() <<endl;
	cout << b.get_di() <<endl;
	cout << b.get_mn() <<endl;
	cout << a.get_mn() + b.get_mn() <<endl;
	cout << a.get_mn() * b.get_mn() <<endl;
	system ("pause");
	return 0;
}

/*
#include "stdafx.h"
#include <iostream>
using namespace std;
class matr {
	//private: 
		int **matrica;
		int n,m;
	public :
		matr(){
		matrica=0;
		m=0; n=0;
		}
		matr(int na,int mb)       
	{
		n = na;
		m = mb;
		int **matrica = new int *[n];
		for (int i = 0; i < n; i++)
		{
			matrica[i] = new int[m];
			for (int j=0; j < m; j++){
			matrica[i][j]=0;
			}
		}
		}
		void showData()         //вывод данных массива на экран
	{
		for (int i = 0; i < n; i++)
		{
			for (int j=0; j<m; j++)
			cout << matrica[i][j] << " | ";
		}
		cout << endl << endl;
	}

		/*
		int proizv (int **aArr , int **bArr) {
		int i,j;
		int **cArr = new int *[i];
		for (i = 0; i < m; i++)
		cArr[i] = new int [j];
		for(i = 0; i < m; i++) {
			for(j = 0; j < m; j++)
			{
			cArr[i][j] = 0;
			for(int k = 0; k <= m + 1; k++)
			cArr[i][j] += (aArr[i][k] * bArr[k][j]);
			}
		}
		return **cArr;
		}
		int summ (int **aArr , int **bArr){
		int i,j;
		int **cArr = new int *[i];
		for (i = 0; i < m; i++)
		cArr[i] = new int [j];
		for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
    cArr[i][j] = aArr[i][j] + bArr[i][j];
		}
		return **cArr;
		}
		
		int& operator ()(size_t i, size_t j)
		{
			return matrica[i][j];
		}
};

int main()
{

	matr ArrayInt(2,2);    //создаем объект класса и записываем в него данные
	ArrayInt(0,0) = 1; //перегруженный []
	ArrayInt(0,1) = 2;
	ArrayInt(1,0) = 3;
	ArrayInt(1,1) = 4;
	cout << "Массив ArrayInt:  ";
	//ArrayInt.showData();

	system("pause");
	return 0;
}
*/
