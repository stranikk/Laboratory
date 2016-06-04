#include <stdlib.h>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class File; // Класс файл
class Directory;

class File { // Класс файл
	string name;
public:
	File() : name("") {

	}

	File(string n) : name(n)
	{
	}

	string get_name() {
		return name;
	}

	~File();
};


class Directory { // директория 
	string name_dir;
	vector <File*> Files;
public:
	Directory()
	{
	}

	Directory(string n) : name_dir(n)
	{
	}

	string get_dir() {
		return name_dir;
	}

	void set_dir(string n) {
		name_dir = n;
	}

	void add_File(File* w) {
		Files.push_back(w);
	}

	File* get_File(int i) {
		return Files[i];
	}

	void rm_file(int i) {
		Files.erase(Files.begin() + i);
	}

	int get_dir_size() {
		return Files.size();
	}
	~Directory();
};


class Shell {
	vector <File> Files;
	vector <Directory> direct;

public:
	Shell() {
	}
	Shell(const Shell& o) {

	}

	void create_file() //Добавление нового сотрудника
	{

		string n;
		cout << "Enter File name:";
		cin >> n;
		Files.push_back(File(n));
	}


	void list_file() //Вывод списка сотрудникова
	{
		cout << "Files: \n";
		for (int i = 0; i < Files.size(); i++)
		{
			cout << Files[i].get_name() << " " << endl;
		}
	}

	void rm_file() //Увольнение сотрудника
	{
		string n;
		cout << "Enter File name:";
		cin >> n;
		for (int i = 0; i < Files.size(); i++) // Удаление из вектора рабочих
		{
			if (Files[i].get_name() == n)
			{
				Files.erase(Files.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < direct.size(); i++) // Удаление из списка подразделений
		{
			for (int j = 0; j < direct[i].get_dir_size(); j++)
			{
				if (direct[i].get_File(j)->get_name() == n)
				{
					direct[i].rm_file(j);
					j--;
				}

			}
		}
	}

	void add_Directory()
	{
		string n;
		cout << "Enter name of Directory:";
		cin >> n;
		direct.push_back(Directory(n));

	}

	void del_Directory()
	{
		Directory D;
		string n;
		cout << "Enter name of Directory:";
		cin >> n;
		for (int i = 0; i < direct.size(); i++)
		{
			if (direct[i].get_dir() == n)
			{
				direct.erase(direct.begin() + i);
				i--;
			}
		}
	}

	void list_Directory()
	{
		cout << "Directorys: \n";
		for (int i = 0; i < direct.size(); i++)
		{
			cout << direct[i].get_dir() << " " << endl;
		}
	}

	void add_File_dir()
	{
		string n;
		int a = -1;
		cout << "Enter File name:";
		cin >> n;
		for (int i = 0; i<Files.size(); i++)
		{
			if (Files[i].get_name() == n)
			{
				a = i;
			}
		}
		if (a == -1)
		{
			cout << "File not found: 404" << endl;
			return;
		}

		int b = -1;
		cout << "Enter Directory name:";
		cin >> n;
		for (int i = 0; i<direct.size(); i++)
		{
			if (direct[i].get_dir() == n)
			{
				b = i;
			}
		}
		if (b == -1)
		{
			cout << "Directory not found: 404" << endl;
			return;
		}

		direct[b].add_File(&Files[a]);
	}
	void list_dir_File() {
		string n;
		int b = -1;
		cout << "Enter Directory name:";
		cin >> n;
		for (int i = 0; i<direct.size(); i++)
		{
			if (direct[i].get_dir() == n)
			{
				b = i;
			}
		}
		if (b == -1)
		{
			cout << "Directory not found: 404" << endl;
			return;
		}
		cout << "Files in Directory: \n";
		for (int i = 0; i < direct[b].get_dir_size(); i++)
		{
			cout << direct[b].get_File(i)->get_name() << " " << endl;
		}

	}
	void search_File_dir() {
		string n;
		int a = -1;
		cout << "Enter File name:";
		cin >> n;
		for (int i = 0; i<Files.size(); i++)
		{
			if (Files[i].get_name() == n)
			{
				a = i;
				cout << "File found in a system: " <<n<< endl;
			}
		}
		if (a == -1)
		{
			cout << "File not found" << endl;
			return;
		}
		for (int i = 0; i < direct.size(); i++) {

			for (int j = 0; j < direct[i].get_dir_size(); j++)
			{
				if (direct[i].get_File(j)->get_name() == n) {
					cout << "File: " << n << " found in the Directory: " << direct[i].get_dir() << endl;
				}
			}
		}
	}
	void rename_dir() {
		string n,r;
		int b = -1;
		cout << "Enter to rename Directory:";
		cin >> n;
		for (int i = 0; i<direct.size(); i++)
		{
			if (direct[i].get_dir() == n)
			{
				b = i;
				cout << "Enter new name Directory: ";
				cin >> r;
				direct[i].set_dir(r);
			}
		}
		if (b == -1)
		{
			cout << "Directory not found: 404" << endl;
			return;
		}

	}
	void move_File_dir() {
		string n,e;
		int a = -1;
		cout << "Enter File name to move:";
		cin >> n;
		for (int i = 0; i<Files.size(); i++)
		{
			if (Files[i].get_name() == n)
			{
				a = i;
			}
		}
		if (a == -1)
		{
			cout << "File not found: 404" << endl;
			return;
		}
		int b = -1;
		cout << "Enter Directory to move in: ";
		cin >> e;
		for (int i = 0; i<direct.size(); i++)
		{
			if (direct[i].get_dir() == e)
			{
				b = i;
			}
		}
		if (b == -1)
		{
			cout << "Directory not found: 404" << endl;
			return;
		}
		int m = 0;
		for (int i = 0; i < direct.size(); i++) {

			for (int j = 0; j < direct[i].get_dir_size(); j++)
			{
				if (direct[i].get_File(j)->get_name() == n) {
					m = i;
				}
			}
		}
		direct[b].add_File(&Files[a]);
		direct[m].rm_file(a);
	}
};


int main()
{
	Shell shell;
	int n;
	string command;
	while (command != "exit")
	{
		cout << "> ";
		cin >> command;

		if (command == "help") {
			cout << "---FILE---" << endl;
			cout << "create_file - add new file" << endl;
			cout << "list_file - list of files" << endl;
			cout << "rm_file - delete file" << endl;
			cout << "---Directory---" << endl;
			cout << "add_dir - add new Directory" << endl;
			cout << "list_dir - list of Directorys" << endl;
			cout << "del_dir - delete Directory" << endl;
			cout << "add_dir_file - add file to Directory" << endl;
			cout << "list_dir_file - list file of Directory" << endl;
			cout << "search_file_dir - search file in Directorys" << endl;
			cout << "rename_dir - reform Directory" << endl;
			cout << "move_file_dir - move file to new Directory" << endl;
		}
		//------// Команды с файлами
		if (command == "create_file") //Добавление нового файла
			shell.create_file();

		if (command == "list_file") //Вывод списка файлов в системе
			shell.list_file();

		if (command == "rm_file") //Удаление файла
			shell.rm_file();

		//------// Команды с директориями
		if (command == "add_dir")  //Добавление новой папки
			shell.add_Directory();

		if (command == "list_dir") // Вывод списка созданных папок
			shell.list_Directory();

		if (command == "del_dir") //Удаление папки
			shell.del_Directory();

		if (command == "add_dir_file") //добавление файла в папку
			shell.add_File_dir();

		if (command == "list_dir_file") // вывод списка файлов из одной папки (содержание папки)
			shell.list_dir_File();

		if (command == "search_file_dir") // поиск файла по системе
			shell.search_File_dir();

		if (command == "rename_dir") // переименовывание уже созданной папки
			shell.rename_dir();

		if (command == "move_file_dir") // перемещение файла между папками
			shell.move_File_dir();
	}
	return 0;
}

Directory::~Directory()
{
}

File::~File()
{
}
