#pragma once
#include<iostream>
#include<ctype.h>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

///////////////////////////////////////////////////////////////////////
///////////		CLASS DECLARATION - ОБЪЯВЛЕНИЕ КЛАССА		///////////
///////////////////////////////////////////////////////////////////////

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;	//размер строки в Байтах
	char* str;	//указатель на строку в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();


	//				Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	~String();

	//				Operators
	String& operator=(const String& other);
	String& operator+=(const String& other);
	char operator[](int i)const;//i - index
	char& operator[](int i);//i - index

	//				Methods:
	void print()const;
	String& to_upper();
	String& to_lower();
};

///////////////////////////////////////////////////////////////////////
///////////	CLASS DECLARATION END - КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА	///////////
///////////////////////////////////////////////////////////////////////
