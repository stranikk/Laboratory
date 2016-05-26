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

1 1
1 0 1 0 0
0 0 
0
1
0 0

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
	string name;
	vector <string> history;

public:
	Worker() : name("")
	{
		
	}
	
	Worker(string n) : name(n)
	{
		history.push_back("Was created as \"" + name + "\"");
	}

	string get_name() {
		return name;
	}
	
	string get_history(int i) {
		return history[i];
	}
	
	int get_history_size() {
		return history.size();
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
	string name_div;
	vector <Worker*> workers;
	//vector <Division> workers;
	//string name_division_worker;
public:
	Division()
	{
	}
	
	Division(string n) : name_div(n)
	{	
	}
	
	string get_div() {
		return name_div;
	}
	
	string set_div(string n) {
		name_div = n;
	}
	
	void add_worker(Worker* w) {
		workers.push_back(w);
	}

	Worker* get_worker(int i) {
		return workers[i];
	}

	void del_worker(int i) {
		workers.erase(workers.begin() + i);
	}
	
	int get_div_size() {
		return workers.size();
	}
};


class Shell {
	vector <Worker> workers;
	vector <Division> divis;
	
	public:
	shell() {	
	}
	shell(const Shell& o) {
		// TO-DO: Construcor 
	}
	
	void addemp() //Добавление нового сотрудника
	{
		
		string n;
		cout << "Enter worker name:";
		cin >> n;
		workers.push_back(Worker(n));
	}


	void listemp() //Вывод списка сотрудникова
	{
		cout << "Workers: \n";
		for (int i = 0; i < workers.size(); i++)
		{
			cout << workers[i].get_name() << " " << endl;
		}
	}

	void delemp() //Увольнение сотрудника
	{
		string n;
		cout << "Enter worker name:";
		cin >> n;
		for (int i = 0; i < workers.size(); i++) // Удаление из вектора рабочих
		{
			if (workers[i].get_name() == n)
			{
				workers.erase(workers.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < divis.size(); i++) // Удаление из списка подразделений
		{
			for (int j = 0; j < divis[i].get_div_size(); j++)
			{
				if (divis[i].get_worker(j)->get_name() == n)
				{
					divis[i].del_worker(j);
					j--;
				}
				
			}
		}
	}
	
	void add_division()
	{
		string n;
		cout << "Enter name of division:";
		cin >> n;
		divis.push_back(Division(n));
		
	}

	void del_division()
	{
		Division D; 
		string n;
		cout << "Enter name of division:";
		cin >> n;
		for (int i = 0; i < divis.size(); i++)
		{
			if (divis[i].get_div() == n)
			{
				divis.erase(divis.begin() + i);
				i--;
			}
		}
	}

	void list_division()
	{
		cout << "Divisions: \n";
		for (int i = 0; i < divis.size(); i++)
		{
			cout << divis[i].get_div() << " " << endl;
		}
	}
	
	void add_worker_div() 
	{
		string n;
		int a = -1;
		cout << "Enter worker name:";
		cin >> n;
		for(int i=0; i<workers.size(); i++) 
		{
			if (workers[i].get_name() == n)
			{
				a = i;
			}
		}
		if(a==-1)
		{
			cout << "Worker not found: 404" << endl;
			return;
		}
			
		int b = -1;
		cout << "Enter division name:";
		cin >> n;
		for(int i=0; i<divis.size(); i++) 
		{
			if (divis[i].get_div() == n)
			{
				b = i;
			}
		}
		if(b==-1)
		{
			cout << "Division not found: 404" << endl;
			return;
		}
		
		divis[b].add_worker(&workers[a]);
	}
};


int main()
{
	//Worker empl;
	//Division division;
	Shell shell;
	int n; 
	string command;
	while (command != "exit")
	{
		cout << "> ";
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
			cout << "add_div_emp - add employee to division" << endl; 
		}
		//------// Команды с сотрудниками
		if (command == "addemp") //Добавление нового сотрудника
			shell.addemp();

		if (command == "listemp") //Вывод списка сотрудникова
			shell.listemp();

		if (command == "delemp") //Увольнение сотрудника
			shell.delemp();

		//------// Команды с зонами и дверями
		if (command == "add_division")  //Добавление новой зоны
			shell.add_division();

		if (command == "list_division") // Вывод подразделений
			shell.list_division();

		if (command == "del_division") //Удаление подразделения
			shell.del_division();
			
		if (command == "add_div_emp") //Удаление подразделения
			shell.add_worker_div();
	}
	return 0;
}

