#include<iostream>
#include<ctype.h>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

///////////////////////////////////////////////////////////////////////
///////////		CLASS DECLARATION - ���������� ������		///////////
///////////////////////////////////////////////////////////////////////

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;	//������ ������ � ������
	char* str;	//��������� �� ������ � ������������ ������
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
///////////	CLASS DECLARATION END - ����� ���������� ������	///////////
///////////////////////////////////////////////////////////////////////

//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
///////////		CLASS DEFINITION - ����������� ������		///////////
///////////////////////////////////////////////////////////////////////

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}


//				Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//Deep copy (�������� �����������, ��������� �����������, ����������/����������� �����������)
	cout << "CopyConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}

//				Operators
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	//CopyAssignment, ��� �� ��� � CopyConstructor ��������� DeepCopy
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
char String::operator[](int i)const//i - index
{
	return str[i];
}
char& String::operator[](int i)//i - index
{
	return str[i];
}


//				Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}
String& String::to_upper()
{
	for (int i = 0; i < size; i++)
	{
		//if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
		//if (str[i] >= '�' && str[i] <= '�')str[i] -= ' ';
		str[i] = ::toupper(str[i]);
	}
	return *this;
}
String& String::to_lower()
{
	for (int i = 0; i < size; i++)
	{
		//if (str[i] >= 'A' && str[i] <= 'Z')str[i] += ' ';
		//if (str[i] >= '�' && str[i] <= '�')str[i] += ' ';
		str[i] = tolower(str[i]);
	}
	return *this;
}
String operator+(const String& left, const String& right)
{
	//������������ �����
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//l-value = r-value;
		//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	//const int SIZE = USHRT_MAX;
	char sz_buffer[USHRT_MAX] = {};	//sz - String Zero (������, ��������������� �����)
	SetConsoleCP(1251);
	is >> sz_buffer;
	SetConsoleCP(866);
	obj = sz_buffer;
	return is;
}
std::istream& getline(std::istream& is, String& obj)
{
	SetConsoleCP(1251);
	is.getline(obj.get_str(), obj.get_size());
	SetConsoleCP(866);
	return is;
}

///////////////////////////////////////////////////////////////////////
///////////	CLASS DEFINITION END - ����� ����������� ������	///////////
///////////////////////////////////////////////////////////////////////

//#define NULL_TERMINATED_LINES
//#define DEBUG_ASSERTION_FAILED_1
//#define DEBUG_ASSERTION_FAILED_2
//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define KEYBOARD_INPUT_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef NULL_TERMINATED_LINES
	//ASCII-������ � ����� 0 '\0'
//NULL Terminated lines
//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	char str[] = "Hello";
	cout << str << endl;
	cout << sizeof(str) << endl;
	cout << strlen(str) << endl;
#endif // NULL_TERMINATED_LINES

#ifdef DEBUG_ASSERTION_FAILED_1
	int a = 2;
	int* pa = &a;
	int arr[] = { 3,5,8 };

	delete arr;
#endif // DEBUG_ASSERTION_FAILED_1

#ifdef DEBUG_ASSERTION_FAILED_2
	int* arr = new int[5];
	int* brr = arr;
	delete[] brr;
	delete[] arr;
#endif // DEBUG_ASSERTION_FAILED_2

#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();

	String str2(44);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();
	cout << str3 << endl;

	String str4 = str3;		//Copy constructor
	cout << "Str4:\t" << str4 << endl;

	String str5;	//Default constructor
	str5 = str4;	//Copy assignment (�������� ������������)
	cout << str5 << endl;

	int a = 2;
	int b = 3;
	a = b;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	//String str3 = str1 + " " + str2;
	//cout << str3 << endl;
	str1 += str2;
	cout << str1 << endl;
#endif // OPERATOR_PLUS_CHECK

#ifdef KEYBOARD_INPUT_CHECK
	String str;
	cout << "������� ������: ";
	//cin >> str;
	getline(cin, str);
	cout << str << endl;
	str.to_upper();
	cout << str << endl;
	str.to_lower();
	cout << str << endl;

#endif // KEYBOARD_INPUT_CHECK

	String str1;	//Default constructor
	str1.print();
	String str2(22);//Single-argument constructor
	str2.print();
	String str3 = "Hello";//Single-argument constructor
	str3.print();
	String str4();	//����� �� ���������� ������� �����������, 
	//������ ��� ����� �� ��������� ������,
	//� ����������� ������� str4(), ������� �� ��������� ������� ����������, 
	//� ���������� �������� ���� String.
	//str4.
	//� ����������� �� ��������� ����� ���� ������� ���:
	String str5{};	//Default constructor
	str5.print();
	//��� ������ �������� ������ ����� ������� ����� �����������.
	String str6 = str3;
	str6.print();
}