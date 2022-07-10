#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<locale>
#include<windows.h>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
#include<cstdlib>
#include <sstream>
#include <utility>
#include <string>
#include <algorithm>
#include <cassert>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::_Iosb;
using std::setw;
using std::pair;
using std::make_pair;

//В Solution Inheritance добавить проект Network и в этом проекте взять файл :
//https://github.com/okovtun/PV_011/blob/master/STL/Files/Task/201%20RAW.txt
//и в этом файле поменять местами столбцы с IP - адресом и MAC - адресом,
//при этом должен создаться новый файл.
//В этом же проекте, из файла 201RAW.txt создать файл формата :
//https://github.com/okovtun/PV_011/blob/master/STL/Files/Task/201.dhcpd

//#define ZADACHA_1 
//#define ZADACHA_2 
#define INTERSNAYA_SHTUKA 

int main() {
	setlocale(LC_ALL, "");
#ifdef ZADACHA_1
	string filename_read;
	string filename_write;
	string txt = ".txt";
	cout << "Введжите имя файла для чтения: "; getline(cin, filename_read);
	cout << "Введжите имя файла для записи: "; getline(cin, filename_write);

	if (filename_read.find(txt) == string::npos) { filename_read += txt; }//проверяем окончание строки на совпадение если нету то конкатенируем строку с строкой расширения файла
	if (filename_write.find(txt) == string::npos) { filename_write += txt; }//проверяем окончание строки на совпадение если нету то конкатенируем строку с строкой расширения файла

	const int SIZE = USHRT_MAX; //Размер буффера чтения
	char buffer[SIZE] = {}; //буффер чтения

	ifstream rfile;/*имя потка*/; // объект класса ofstream
	ofstream wfile;/*имя потка*/; // объект класса ofstream

	rfile.open(filename_read);
	bool file_not_found = false;
	if (!rfile.is_open()) {
		std::cerr << "Error: file not found" << endl; file_not_found = true;
	}
	else {
		wfile.open(filename_write); //если читаемого файла нету то и нефиг создавать записываемый файл
		string left;
		string right;
		while (!rfile.eof()) {
			rfile >> left >> right;
			wfile << right << "\t" << left << "\n";
		}
		wfile.close();

	}
	rfile.close();

	string start_write = "start notepad " + filename_write;
	string start_read = "start notepad " + filename_read;

	//const char* w = start_write.c_str(); //Если вы хотите просто передать функцию std::string в функцию, которой нужен const char*, вы можете использовать
	//const char* r = start_read.c_str(); //Если вы хотите просто передать функцию std::string в функцию, которой нужен const char*, вы можете использовать
	if (!file_not_found) {
		system(start_write.c_str());
		system(start_read.c_str());
	}
#endif // ZADACHA_1

#ifdef ZADACHA_2
	string filename_read;
	string filename_write = "HOSTS.txt";
	string txt = ".txt";
	cout << "Введжите имя файла для чтения: "; getline(cin, filename_read);
	//cout << "Введжите имя файла для записи: "; getline(cin, filename_write);

	if (filename_read.find(txt) == string::npos) { filename_read += txt; }//проверяем окончание строки на совпадение если нету то конкатенируем строку с строкой расширения файла
	//if (filename_write.find(txt) == string::npos) { filename_write += txt; }//проверяем окончание строки на совпадение если нету то конкатенируем строку с строкой расширения файла
	const int SIZE = USHRT_MAX; //Размер буффера чтения
	char buffer[SIZE] = {}; //буффер чтения

	ifstream rfile;/*имя потка*/; // объект класса ofstream
	ofstream wfile;/*имя потка*/; // объект класса ofstream

	rfile.open(filename_read);
	bool file_not_found = false;
	bool overwrite = false;
	if (!rfile.is_open()) {
		std::cerr << "Error: file not found" << endl; file_not_found = true;
	}
	else {
		if (wfile.bad() == false) {
			std::cerr << "Файл HOSTS существует! Перезаписать?  Y да. N нет." << endl;// file_not_found = true;
			char simvol;
			cin >> simvol;
			if (simvol == 'Y' || simvol == 'y') { overwrite = true; }
			else if (simvol == 'N' || simvol == 'n') { overwrite = false; }

		}
		if (overwrite) {//перезаписываем файл
			wfile.open(filename_write); //если читаемого файла нету то и нефиг создавать записываемый файл
			string left;
			string right;
			int i = 1;
			while (!rfile.eof()) {
				rfile >> right >> left;
				replace(left.begin(), left.end(), '-', ':');
				wfile << "host 201-" << i << endl;
				wfile << "{" << endl;
				wfile << "\t" << "hardware ethernet" << "\t" << left << ";" << endl;
				wfile << "\t" << "fixed-address" << "\t" << "\t" << right << ";" << endl;
				wfile << "}" << endl << endl;
				i++;
			}
		}
		wfile.close();

	}
	rfile.close();

	string start_write = "start notepad " + filename_write;
	string start_read = "start notepad " + filename_read;

	//const char* w = start_write.c_str(); //Если вы хотите просто передать функцию std::string в функцию, которой нужен const char*, вы можете использовать
	//const char* r = start_read.c_str(); //Если вы хотите просто передать функцию std::string в функцию, которой нужен const char*, вы можете использовать
	if (!file_not_found) {
		if (overwrite) { system(start_write.c_str()); }
		system(start_read.c_str());
	}
#endif // ZADACHA_2

#ifdef INTERSNAYA_SHTUKA
	WCHAR text[] = { L"Hi, mother**ers! I'm here! абракадабра ёпта" };
	srand(time(0));

	STARTUPINFOW si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	CreateProcessW(L"c:\\windows\\notepad.exe", NULL, 0, 0, 0, 0, 0, 0, &si, &pi);

	Sleep(rand() % 1000);

	HWND hNotepad = FindWindowW(L"Notepad", 0);
	HWND edit = FindWindowExW(hNotepad, 0, L"Edit", 0);

	int len = wcslen(text);
	for (int i = 0; i < len; i++)
	{
		Sleep(rand() % 100);
		SendMessageW(edit, WM_CHAR, (WPARAM)text[i], 0);
	}
#endif // INTERSNAYA_SHTUKA

}

/*
Работа с файлами
для работы с файлами так как и для вывода на экран и вв вода с клавиатуры используются потокию
для вывода на экран используется поток cout для ввода с клавиатуры поток cin
cout ячвляется обьектом класса ostream
a cin обьектом класса istream
для вывода инф не в консоль а в файл используется поток fout
для чтения инф не с клавиатуры а с файла исп поток fin
fout фвл обьектом класса offstream
fin явл обьектом класса ifstream
единственным отл между файловуми потоками и консольными явл то что консольные потоки уже существуют
как обьекты и эти обьекты привязаны к консоли а вот файловых потоков не существует
и для того что бы привязать их к какому то файлу их нужно для начала создать
потоки  cin(ввода)  cout(вывода)  находятся в библиотеке iostream
классы файловых потоков fin fout  находятся в библиотеке fstream
При создании файлового потока его обязательно привяз к файлу и тогда поток открывается.
Через открытый поток можно читать либо писать файл но после того как все операции над файлом закончены его обязательно нужно закрыть
функция system позволяет вызвать любую команду командной строки windows
*/