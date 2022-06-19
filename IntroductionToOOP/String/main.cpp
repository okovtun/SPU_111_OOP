#include<iostream>
#include<ctype.h>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;	//размер строки в Байтах
	char* str;	//указатель на строку в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}


	//				Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		//Deep copy (Глубокое копирование, побитовое копирование, побайтовое/поэементное копирование)
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		//CopyAssignment, так же как и CopyConstructor выполняет DeepCopy
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	char operator[](int i)const//i - index
	{
		return str[i];
	}
	char& operator[](int i)//i - index
	{
		return str[i];
	}


	//				Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
	String& to_upper()
	{
		for (int i = 0; i < size; i++)
		{
			//if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
			//if (str[i] >= 'а' && str[i] <= 'я')str[i] -= ' ';
			str[i] = ::toupper(str[i]);
		}
		return *this;
	}
	String& to_lower()
	{
		for (int i = 0; i < size; i++)
		{
			//if (str[i] >= 'A' && str[i] <= 'Z')str[i] += ' ';
			//if (str[i] >= 'А' && str[i] <= 'Я')str[i] += ' ';
			str[i] = tolower(str[i]);
		}
		return *this;
	}
	
};
String operator+(const String& left, const String& right)
{
	//Конкатенация строк
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
	char sz_buffer[USHRT_MAX] = {};	//sz - String Zero (Строка, заканчивающаяся нулем)
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
	//ASCII-символ с кодом 0 '\0'
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
	str5 = str4;	//Copy assignment (оператор присваивания)
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
	cout << "Введите строку: ";
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
	String str4();	//Здесь не вызывается никакой конструктор, 
	//потому что здесь НЕ создается объект,
	//а объявляется функция str4(), которая НЕ принимает никаких параметров, 
	//и возвращает значение типа String.
	//str4.
	//А конструктор по умолчанию можно явно вызвать так:
	String str5{};	//Default constructor
	str5.print();
	//При помощи фигурных скобок можно вызвать любой конструктор.
}