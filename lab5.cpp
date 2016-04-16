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
	vector <string> ArrPapka;
public :
	papka(){
	sizeOfArray=0;
	}
	papka (int size) : sizeOfArray(size), ArrPapka(size) {
		;
		for (int i=0; i< ArrPapka.size(); i++){
			ArrPapka[i]= "0";
		}
	}
	string &operator[](int j) //перегрузка []     
	{
		return ArrPapka[j];
	}
	void showData()         //вывод данных массива на экран
	{
		for (int i = 0; i < sizeOfArray; i++)
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

	
	return 0;
	
}
