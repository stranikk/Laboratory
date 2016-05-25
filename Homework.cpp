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
class Door;
class Zone;

class Worker { // Класс сотрудники 
	vector <Worker> workers;
	string name;
	string history;

public:
	Worker()
	{
		EmplNumber = 0;
		Category = 0;
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
		Worker E; int n;
		cout << "Enter employee number:";
		cin >> n;
		for (int i = 0; i < workers.size(); i++)
		{
			if (workers[i].EmplNumber == n)
			{
				workers.erase(workers.begin() + i);
			}
		}
	}

	void chgcat() //Изменение категории доступа отдельного сотрудника
	{
		Worker E; int n;
		cout << "Enter employee number:";
		cin >> n;
		for (int i = 0; i < workers.size(); i++)
		{
			if (workers[i].EmplNumber == n)
			{
			cout << "Enter new employee category:";
			cin >> n;
			workers[i].Category = n;
			}
		}
	}

	int getempcat(int n) {
		for (int i = 0; i < workers.size(); i++)
		{
			if (empls[i].EmplNumber == n)
			{
				return workers[i].Category;
			}

		}
	}
};

class Door {
public:
	int DoorNumber;
	int DoorCategory;
	int DoorZone;

	Door() 
	{
		DoorNumber = 0;
		DoorCategory = 0;
		DoorZone = 0;
	}
};

class Zone {
	friend Employee;
	vector <Door> doors;
	vector <Zone> zones;
	int ZoneNumber;
	int ZoneCategory;
public:
	Zone() 
	{
		ZoneCategory = 0;
		ZoneNumber = 0;
	}

	void addzone()
	{
		Zone Z; int n; int count = 0;
		cout << "Enter zone number:";
		cin >> n;
		for (int i = 0; i < zones.size(); i++)
		{
			if (zones[i].ZoneNumber == n) 
			{
				cout << "Zone with this ID number already exists!" << endl;
				count = 1;
			}
		}
		if (count == 0)
		{
			Z.ZoneNumber = n;
			cout << "Enter zone category:";
			cin >> n;
			Z.ZoneCategory = n;
			zones.push_back(Z);
		}
		count = 0;	
	}

	void delzone()
	{
		Zone Z; int n;
		cout << "Enter zone number:";
		cin >> n;
		for (int i = 0; i < zones.size(); i++)
		{
			if (zones[i].ZoneNumber == n)
			{
				zones.erase(zones.begin() + i);
			}
		}
	}

	void deldoor()
	{
		Door D; int n;
		cout << "Enter zone number:";
		cin >> n;
		for (int i = 0; i < doors.size(); i++)
		{
			if (doors[i].DoorNumber == n)
			{
				doors.erase(doors.begin() + i);
			}
		}
	}

	int getzonecat(int n)
	{
		for (int i = 0; i < zones.size(); i++)
		{
			if (zones[i].ZoneNumber == n)
			{
				return zones[i].ZoneCategory;
			}
		}
	}

	int getdoorcat(int n)
	{
		for (int i = 0; i < doors.size(); i++)
		{
			if (doors[i].DoorNumber == n)
			{
				return doors[i].DoorCategory;
			}
		}
	}

	void adddoor()
	{

		Door D; int n; int count = 0;
		cout << "Enter door number:";
		cin >> n;
		for (int i = 0; i < doors.size(); i++)
		{
			if (doors[i].DoorNumber == n)
			{
				cout << "Door with this ID number already exists!" << endl;
				count = 1;
			}
		}
		if (count == 0)
		{
			D.DoorNumber = n;
			cout << "Enter zone number for door:";
			cin >> n;
			for (int i = 0; i < zones.size(); i++)
			{
				if (zones[i].ZoneNumber == n)
				{
					D.DoorZone = n;
					D.DoorCategory = getzonecat(n);
					doors.push_back(D);
				}

			}
			count = 0;
		}
	}

	void listzone()
	{
		cout << "Zones: \n";
		cout << "Zone - Category \n";
		for (int i = 0; i < zones.size(); i++)
		{
			cout << zones[i].ZoneNumber << " " << zones[i].ZoneCategory << endl;
		}
	}

	void listdoor()
	{
		int n;
		cout << "Enter zone number:";
		cin >> n;
		for (int i = 0; i < zones.size(); i++)
		{
			if (zones[i].ZoneNumber == n)
			{
				for (int i = 0; i < doors.size(); i++)
				{
					if (doors[i].DoorZone = zones[i].ZoneNumber)
					{
						cout << doors[i].DoorNumber << ", ";
					}
				}
			}
		}
	}
};


int main()
{
	Employee empl;
	Zone zone;
	int n; string command;
	while (command != "end")
	{
		cin >> command;

		if (command == "help") {
			cout << "---EMPLOYEE---" << endl;
			cout << "addemp - add new employee" << endl;
			cout << "listemp - list of employers" << endl;
			cout << "delemp - delete employee" << endl;
			cout << "chgcat - change access category of employee" << endl;
			cout << "---ZONES AND DOORS---" << endl;
			cout << "addzone - add new zone" << endl;
			cout << "adddoor - add new door to zone" << endl;
			cout << "listzone - list of zones" << endl;
			cout << "listdoor - list of doors of zone" << endl;
			cout << "delzone - delete zone" << endl;
			cout << "deldoor - delete door" << endl;
			cout << "---OTHER---" << endl;
			cout << "trydoor - " << endl;
		}
		//------// Команды с сотрудниками
		if (command == "addemp") //Добавление нового сотрудника
			empl.addemp();

		if (command == "listemp") //Вывод списка сотрудникова
			empl.listemp();

		if (command == "delemp") //Увольнение сотрудника
			empl.delemp();

		if (command == "chgcat") //Изменение категории доступа отдельного сотрудника
			empl.chgcat();
		//------// Команды с зонами и дверями
		if (command == "addzone")  //Добавление новой зоны
			zone.addzone();

		if (command == "adddoor") //Добавление новой двери
			zone.adddoor();

		if (command == "listzone") //Вывод списка зон
			zone.listzone();

		if (command == "listdoor") //Вывод списка дверей отдельной зоны
			zone.listdoor();

		if (command == "delzone") //Удаление зоны
			zone.delzone();

		if (command == "deldoor") //Удаление двери
			zone.deldoor();
		//------// Общие команды
		if (command == "trydoor") //Попытка доступа человека к двери
		{
			int g;
			cout << "Enter employee number:" << endl;
			cin >> n;
			cout << "Enter door number:" << endl;
			cin >> g;
			if (zone.getdoorcat(g) <= empl.getempcat(n)) 
			{
				cout << "SUCCESS" << endl;
			}
			else if (zone.getdoorcat(g) > empl.getempcat(n))
			{
				cout << "ACCESS DENIED" << endl;
			}

		}

	}
	return 0;
}

