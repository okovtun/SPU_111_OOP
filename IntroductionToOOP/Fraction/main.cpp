//Fraction
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction;
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;	//Целая часть
	int numerator;	//Числитель 
	int denominator;//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	//				Incremento/Decremento:
	Fraction& operator++()	//Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)//Suffix increment
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	//			Type-cast operators:
	explicit operator int()const
	{
		return this->integer;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//				Methods:

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;
		return inverted;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		if (!integer && !numerator)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	return result;*/
	return Fraction	//явно вызываем конструктор, который создает временный безымянны объект
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper();//Для временного безымянного объекта вызываем метод to_proper();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator())
		return true;
	else
		return false;*/
	return 
		left.get_numerator()*right.get_denominator() == 
		right.get_numerator()*left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return
		left.get_numerator()*right.get_denominator() >
		right.get_numerator()*left.get_denominator();*/
	return (double)left > right;
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator()*right.get_denominator() <
		right.get_numerator()*left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	if (!obj.get_integer() && !obj.get_numerator())os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	/*int integer, numerator, denominator;
	cin >> integer >> numerator >> denominator;
	obj(integer, numerator, denominator);*/
	const int SIZE = 256;
	char sz_buffer[SIZE] = {};//sz_ - String Zero
	//is >> sz_buffer;
	is.getline(sz_buffer, SIZE);
	char* sz_numbers[3] = {};
	char sz_delimiters[] = "() /";
	//https://cplusplus.com/reference/cstring/
	//https://cplusplus.com/reference/cstring/strtok/
	int n = 0;	//Индекс элемента в массиве с подстроками (токенами) sz_numbers
	for (char* pch = strtok(sz_buffer, sz_delimiters); pch; pch = strtok(NULL, sz_delimiters))
	{
		sz_numbers[n++] = pch;
	}
	//for (int i = 0; i < n; i++)cout << sz_numbers[i] << "\t"; cout << endl;
	obj = Fraction();
	switch (n)
	{
		//atoi() - ASCII-string to int (функция преобразования строки в int)
	case 1: obj.set_integer(atoi(sz_numbers[0])); break;
	case 2: 
		obj.set_numerator(atoi(sz_numbers[0]));
		obj.set_denominator(atoi(sz_numbers[1]));
		break;
	case 3:obj(atoi(sz_numbers[0]), atoi(sz_numbers[1]), atoi(sz_numbers[2]));
	}
	return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS
//#define COMPARISON_OPERATORS
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
//#define CONVERSIONS_HOME_WORK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;	//Default constructor
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS
	Fraction A(2, 3, 4);
	A.print();
	/*A.to_improper();
	A.print();
	A.to_proper();
	A.print();*/
	Fraction B(3, 4, 5);
	B.print();

	double a = 2;
	double b = 3;
	double c = a * b;

	Fraction C = A * B;
	C.print();
	cout << "\n------------------------------------------------\n";
	(A / B).print();
	cout << "\n------------------------------------------------\n";
	A *= B;
	A.print();
	cout << "\n------------------------------------------------\n";

	for (double i = .75; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (Fraction i(3, 4); i.get_integer() < 10; i++)
	{
		i.print();
	}
#endif // ARITHMETICAL_OPERATORS

#ifdef COMPARISON_OPERATORS
	cout << (Fraction(1, 2) > Fraction(5, 10)) << endl;
#endif // COMPARISON_OPERATORS

#ifdef TYPE_CONVERSIONS_BASICS
	//(type)value - C-like notation		(C-подобная форма записи)
//type(value) - Functional notation	(Фнкциональная форма записи)

	cout << (double)15 / 2 << endl;

	int a = 2;		//No conversions
	double b = 3;	//From less to more
	int c = a + b;	//From more to less without data loss
	int d = 2.5;	//From more to less with data loss  
#endif // TYPE_CONVERSIONS_BASICS

	/*
		1. Из других типов в наш (from other to class).
		   Выполняет конструктор с одним параметром и оператор присваивания
						(Single-argument constructor и CopyAssignment);
		2. Из нашего типа в другие типы. Выполняют операторы преобразования типов;
	*/

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	//1. Single-argument constructor;
//2. Assignment operator;

//Fraction A = 5;		//From int to Fraction
	Fraction A;
	cout << "\n--------------------------------\n";
	A = Fraction(5);
	cout << "\n--------------------------------\n";
	cout << A << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	/*
--------------------------------------------------------
operator type()
{
	......
	......
	return ...;
}
--------------------------------------------------------
*/

	Fraction A(2, 3, 4);
	cout << A << endl;

	int a = A;
	cout << a << endl;

	double b = A;
	cout << b << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

#ifdef CONVERSIONS_HOME_WORK
	Fraction A = 2.75;
	cout << A << endl;
#endif // DEBUG

	Fraction A(2,3,4);
	cout << "Введите простую дробь: "; 
	cin >> A;
	cout << A << endl;
	/*
	--------------------------------------------------------
	5
	1/2
	2(2/3)
	2 3/4
	--------------------------------------------------------
	*/
}