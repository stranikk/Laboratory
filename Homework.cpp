/*
3. Сотрудники, подразделения -- отдел кадров

Подразделения в предприятии имеют иерархическую структуру.

Процессы:

найм, увольнение сотрудника
создание, переформирование, расформирование, перемещение, объединение подразделений
поиск сотрудника, определение структуры его подчиненности
переход сотрудников между подразделениями
работа сотрудника на несколько ставок в различных подразделениях
Необходимо реализовать функции сохранения и восстановления данных.

По каждому сотруднику должна вестись история его перемещений внутри компании в рамках сессии работы программы.
*/
#include <stdlib.h>
#include <string>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Worker; // // Класс сотрудники 
class Division;

class Worker { // Класс сотрудники 
	vector <Worker> workers;
	string name;
	string history;

public:
	Worker()
	{
		name;
		history;
	}

	void addemp() //Добавление нового сотрудника
	{
		Worker E;
		string n;
		cout << "Enter worker name:";
		cin >> n;
		E.name = n;
		E.history = n;
		workers.push_back(E);
	}


	void listemp() //Вывод списка сотрудникова
	{
		cout << "Workers: \n";
		for (int i = 0; i < workers.size(); i++)
		{
			cout << workers[i].name << " " << endl;
		}
	}

	void delemp() //Увольнение сотрудника
	{
		Worker E; 
		string n;
		cout << "Enter worker name:";
		cin >> n;
		for (int i = 0; i < workers.size(); i++)
		{
			if (workers[i].name == n)
			{
				workers.erase(workers.begin() + i);
			}
		}
	}
	/* string getworkers(string n) { // нужен try - catch
		for (int i = 0; i < workers.size(); i++)
		{
			if (workers[i].name == n) {
				return workers[i].name;
			}
		}
	}
	*/
};


class Division {
	friend Worker;
	vector <Division> divisions;
	//vector <Division> workers;
	string name_division;
	//string name_division_worker;
public:
	Division()
	{
		name_division;
	}

	void add_division()
	{
		Division D; 
		string n;
		cout << "Enter name of division:";
		cin >> n;
		D.name_division = n;
		divisions.push_back(D);
		
	}

	void del_division()
	{
		Division D; 
		string n;
		cout << "Enter name of division:";
		cin >> n;
		for (int i = 0; i < divisions.size(); i++)
		{
			if (divisions[i].name_division == n)
			{
				divisions.erase(divisions.begin() + i);
			}
		}
	}

	void list_division()
	{
		cout << "Divisions: \n";
		for (int i = 0; i < divisions.size(); i++)
		{
			cout << divisions[i].name_division << " " << endl;
		}
	}
	/*
	void add_worker_div() {
		string m,n,k;
		cout << "Enter name in to division:";
		cin >> n;
		cout << "Enter name division:";
		cin >> k;
		for (int i = 0; i < divisions.size(); i++) {
			if (divisions[i].name_division == k) {
				workers[i].name_division_worker = ;
			}
		}
	}
	*/
};


int main()
{
	Worker empl;
	Division division;
	int n; 
	string command;
	while (command != "exit")
	{
		cin >> command;

		if (command == "help") {
			cout << "---EMPLOYEE---" << endl;
			cout << "addemp - add new employee" << endl;
			cout << "listemp - list of employers" << endl;
			cout << "delemp - delete employee" << endl;
			cout << "---DIVISION---" << endl;
			cout << "add_division - add new division" << endl;
			cout << "list_division - list of divisions" << endl;
			cout << "del_division - delete division" << endl;
		}
		//------// Команды с сотрудниками
		if (command == "addemp") //Добавление нового сотрудника
			empl.addemp();

		if (command == "listemp") //Вывод списка сотрудникова
			empl.listemp();

		if (command == "delemp") //Увольнение сотрудника
			empl.delemp();

		//------// Команды с зонами и дверями
		if (command == "add_division")  //Добавление новой зоны
			division.add_division();

		if (command == "list_division") // Вывод подразделений
			division.list_division();

		if (command == "del_division") //Удаление подразделения
			division.del_division();
	}
	return 0;
}

