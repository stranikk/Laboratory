// LAB5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class file {
private : 
	string name;
public :
	file (string filename){
	name=filename;
	}
	string get_file(){
	return name;
	}
};
class papka{
	private : 
    int sizeOfArray;
	vector<string> ArrPapka;
public :
	papka (vector <string> ArrP) {
		ArrPapka=ArrP;
	}
	vector<string> get_papka(){
	return ArrPapka;
	}
	string &operator[](int j) //перегрузка []     
	{
		return ArrPapka[j];
	}
	void showData()         //вывод данных массива на экран
	{
		for (int i = 0; i < ArrPapka.size(); i++)
		{
			cout << ArrPapka[i] << " ";
		}
		cout << endl << endl;
	}

};
/*
class direct
{
private : 
    int sizeOfArray;
	vector <string> ArrDirect;
public :
	direct(){
	sizeOfArray=0;
	}
	direct (int size) : sizeOfArray(size), ArrDirect(size) {
		;
		for (int i=0; i< ArrDirect.size(); i++){
			 ArrDirect[i]= "0";
		}
	}
	string &operator[](int j) //перегрузка []     
	{
		return ArrDirect[j];
	}
	void showDirect()         //вывод данных массива на экран
	{
		for (int i = 0; i < sizeOfArray; i++)
		{
			cout << ArrDirect[i];
		}
		cout << endl << endl;
	}
	

};
*/
int main()
{   
	vector<string> Arr;
	papka ArrayPapka1(Arr);
	string a;
	cout << "Enter name of file:  ";
	cin >> a;
	ArrayPapka1.get_papka().push_back(a);
	cout << "Массив ArrayPapka1:  ";
	ArrayPapka1.showData();

	/*
	file a1("one.txt");
	file a2("two.txt");
	file a3("tre.txt");
	file a4("forh.txt");
	file a5("fif.txt");
	papka ArrayPapka1(5);    
	ArrayPapka1[0] = a1.get_file(); //перегруженный []
	ArrayPapka1[1] = a2.get_file();
	ArrayPapka1[2] = a3.get_file();
	ArrayPapka1[3] = a4.get_file();
	ArrayPapka1[4] = a5.get_file();
	cout << "Массив ArrayPapka1:  ";
	ArrayPapka1.showData(); 

	direct ArrayDirect1(2);
	ArrayDirect1[0] = a1.get_file();
	ArrayDirect1.push_back(ArrayPapka1);
	ArrayDirect1.showDirect(); 
	*/
	return 0;
	
}
