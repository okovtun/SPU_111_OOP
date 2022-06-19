#include"String.h"
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
///////////		CLASS DEFINITION - ОПРЕДЕЛЕНИЕ КЛАССА		///////////
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
String::String(const char* str) : String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) : String(other.str)
{
	//Deep copy (Глубокое копирование, побитовое копирование, побайтовое/поэементное копирование)
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
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
	//CopyAssignment, так же как и CopyConstructor выполняет DeepCopy
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
		//if (str[i] >= 'а' && str[i] <= 'я')str[i] -= ' ';
		str[i] = ::toupper(str[i]);
	}
	return *this;
}
String& String::to_lower()
{
	for (int i = 0; i < size; i++)
	{
		//if (str[i] >= 'A' && str[i] <= 'Z')str[i] += ' ';
		//if (str[i] >= 'А' && str[i] <= 'Я')str[i] += ' ';
		str[i] = tolower(str[i]);
	}
	return *this;
}
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

///////////////////////////////////////////////////////////////////////
///////////	CLASS DEFINITION END - КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА	///////////
///////////////////////////////////////////////////////////////////////
