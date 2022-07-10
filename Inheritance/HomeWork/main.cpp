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

//� Solution Inheritance �������� ������ Network � � ���� ������� ����� ���� :
//https://github.com/okovtun/PV_011/blob/master/STL/Files/Task/201%20RAW.txt
//� � ���� ����� �������� ������� ������� � IP - ������� � MAC - �������,
//��� ���� ������ ��������� ����� ����.
//� ���� �� �������, �� ����� 201RAW.txt ������� ���� ������� :
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
	cout << "�������� ��� ����� ��� ������: "; getline(cin, filename_read);
	cout << "�������� ��� ����� ��� ������: "; getline(cin, filename_write);

	if (filename_read.find(txt) == string::npos) { filename_read += txt; }//��������� ��������� ������ �� ���������� ���� ���� �� ������������� ������ � ������� ���������� �����
	if (filename_write.find(txt) == string::npos) { filename_write += txt; }//��������� ��������� ������ �� ���������� ���� ���� �� ������������� ������ � ������� ���������� �����

	const int SIZE = USHRT_MAX; //������ ������� ������
	char buffer[SIZE] = {}; //������ ������

	ifstream rfile;/*��� �����*/; // ������ ������ ofstream
	ofstream wfile;/*��� �����*/; // ������ ������ ofstream

	rfile.open(filename_read);
	bool file_not_found = false;
	if (!rfile.is_open()) {
		std::cerr << "Error: file not found" << endl; file_not_found = true;
	}
	else {
		wfile.open(filename_write); //���� ��������� ����� ���� �� � ����� ��������� ������������ ����
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

	//const char* w = start_write.c_str(); //���� �� ������ ������ �������� ������� std::string � �������, ������� ����� const char*, �� ������ ������������
	//const char* r = start_read.c_str(); //���� �� ������ ������ �������� ������� std::string � �������, ������� ����� const char*, �� ������ ������������
	if (!file_not_found) {
		system(start_write.c_str());
		system(start_read.c_str());
	}
#endif // ZADACHA_1

#ifdef ZADACHA_2
	string filename_read;
	string filename_write = "HOSTS.txt";
	string txt = ".txt";
	cout << "�������� ��� ����� ��� ������: "; getline(cin, filename_read);
	//cout << "�������� ��� ����� ��� ������: "; getline(cin, filename_write);

	if (filename_read.find(txt) == string::npos) { filename_read += txt; }//��������� ��������� ������ �� ���������� ���� ���� �� ������������� ������ � ������� ���������� �����
	//if (filename_write.find(txt) == string::npos) { filename_write += txt; }//��������� ��������� ������ �� ���������� ���� ���� �� ������������� ������ � ������� ���������� �����
	const int SIZE = USHRT_MAX; //������ ������� ������
	char buffer[SIZE] = {}; //������ ������

	ifstream rfile;/*��� �����*/; // ������ ������ ofstream
	ofstream wfile;/*��� �����*/; // ������ ������ ofstream

	rfile.open(filename_read);
	bool file_not_found = false;
	bool overwrite = false;
	if (!rfile.is_open()) {
		std::cerr << "Error: file not found" << endl; file_not_found = true;
	}
	else {
		if (wfile.bad() == false) {
			std::cerr << "���� HOSTS ����������! ������������?  Y ��. N ���." << endl;// file_not_found = true;
			char simvol;
			cin >> simvol;
			if (simvol == 'Y' || simvol == 'y') { overwrite = true; }
			else if (simvol == 'N' || simvol == 'n') { overwrite = false; }

		}
		if (overwrite) {//�������������� ����
			wfile.open(filename_write); //���� ��������� ����� ���� �� � ����� ��������� ������������ ����
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

	//const char* w = start_write.c_str(); //���� �� ������ ������ �������� ������� std::string � �������, ������� ����� const char*, �� ������ ������������
	//const char* r = start_read.c_str(); //���� �� ������ ������ �������� ������� std::string � �������, ������� ����� const char*, �� ������ ������������
	if (!file_not_found) {
		if (overwrite) { system(start_write.c_str()); }
		system(start_read.c_str());
	}
#endif // ZADACHA_2

#ifdef INTERSNAYA_SHTUKA
	WCHAR text[] = { L"Hi, mother**ers! I'm here! ����������� ����" };
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
������ � �������
��� ������ � ������� ��� ��� � ��� ������ �� ����� � �� ���� � ���������� ������������ �������
��� ������ �� ����� ������������ ����� cout ��� ����� � ���������� ����� cin
cout ��������� �������� ������ ostream
a cin �������� ������ istream
��� ������ ��� �� � ������� � � ���� ������������ ����� fout
��� ������ ��� �� � ���������� � � ����� ��� ����� fin
fout ��� �������� ������ offstream
fin ��� �������� ������ ifstream
������������ ��� ����� ��������� �������� � ����������� ��� �� ��� ���������� ������ ��� ����������
��� ������� � ��� ������� ��������� � ������� � ��� �������� ������� �� ����������
� ��� ���� ��� �� ��������� �� � ������ �� ����� �� ����� ��� ������ �������
������  cin(�����)  cout(������)  ��������� � ���������� iostream
������ �������� ������� fin fout  ��������� � ���������� fstream
��� �������� ��������� ������ ��� ����������� ������ � ����� � ����� ����� �����������.
����� �������� ����� ����� ������ ���� ������ ���� �� ����� ���� ��� ��� �������� ��� ������ ��������� ��� ����������� ����� �������
������� system ��������� ������� ����� ������� ��������� ������ windows
*/