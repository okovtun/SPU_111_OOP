#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//Создаем структуру:
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//				Constructors:
	/*Point()
	{
		//int() - значение по умолчанию для типа данных int
		//double() - значение по умолчанию для типа данных double
		//cout << int() << endl;
		//cout << double() << endl;
		x = y = double();
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		//Single-Argument constructor (Конструктор с одним параметром)
		this->x = x;
		this->y = 0;
		cout << "1argConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	//				Methods:
	double distance(const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		//sqrt - Square Root (Квадратный коринь)
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}

	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(pow(x_distance, 2) + pow(y_distance, 2));
}
Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

//#define STRUCT_POINT
//#define DISTANCE 
//#define CONSTRUCTORS_CHECK
//#define COPY_ASSIGNMENT_1
//#define COPY_ASSIGNMENT_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type name;
	int a;	//Объявление переменной 'a' типа 'int'
	Point A;//Объявление переменной 'A' типа 'Point'
			//Объявление (создание) объекта 'A' структуры 'Point'
			//Создание экземпляра 'A' структуры 'Point'
	//				КЛАСС		-	ЭТО ТИП ДАННЫХ
	//				СТРУКТУРА	-	ЭТО ТИП ДАННЫХ

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;	//Создаем указатель на 'Point'
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE
	Point A;
	A.set_x(2);
	A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	Point B;
	B.set_x(7);
	B.set_y(8);
	//B(7, 8);
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	B.print();
	cout << "\n-------------------------------------\n";
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << "\n-------------------------------------\n";
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << "\n-------------------------------------\n";
	cout << "Расстояние между точками A и B:   " << distance(A, B) << endl;
	cout << "\n-------------------------------------\n";
	cout << "Расстояние между точками B и A:   " << distance(B, A) << endl;
	cout << "\n-------------------------------------\n";
#endif // DISTANCE

#ifdef CONSTRUCTORS_CHECK
	Point A;	//Default constructor
	A.print();

	Point B = 5;//Single-Argument constructor (Конструктор с одним параметром)
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef COPY_ASSIGNMENT_1
	Point A(2, 3);
	Point B = A;	//CopyConstructor
	Point C;
	C = B;	//CopyAssignment  
#endif // DEBUG

#ifdef COPY_ASSIGNMENT_2
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << "\n---------------------------------\n";
	A = B = C = Point(2, 3);
	cout << "\n---------------------------------\n";
#endif // COPY_ASSIGNMENT_2

	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();
	Point C = A + B;
	C.print();
}

/*
-----------------------------------------------------------------
.  - Оператор прямого доступа (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
-----------------------------------------------------------------
*/

/*
-----------------------------------------------------------------
1. Encapsulation;
	Модификаторы доступа:
		private:	закрытые поля, доступны только внутри класса.
		public:		открытые поля, доступные из любого места программы.
		protected:	защищенные поля, доступны только внутри нашего класса
					и его дочерних классов.
	Get/Set-методы:
	get (взять, получить)	используются для доступа на чтение.
	set (задать, установить)

2. Inheritance;
3. Polymorphism;
-----------------------------------------------------------------
*/

/*
----------------------------------------------------------------------
1. Constructor - это метод, который создает объект;
	-с параметрами;
	-без параметров;
	-конструктор по умолчанию - это конструктор,
								который может быть вызван без параметров;
	-конструктор копирования;
	-конструктор переноса;
2. ~Destructor  - это метод, который уничтожает объект по истечении его времени жизни;
3. Operator=;
----------------------------------------------------------------------
*/

/*
------------------------------------------
			Overloading rules:
1. Перегрузить можно только существующие операторы, 
   нельзя придумывать новыет операторы. Например:
	+  перегружается;
	*  перегружается;
	++ перегружаетсяж
	** НЕ перегружается;
2. Не все существующие операторы можно перегрузить.
   Не перегружаются:
	?: - Conditional ternary operator
	:: - Scope operator (Оператор разрешения видимости)
	.  - Оператор приямого доступа (Point operator)
	.* - Pointer to member selection
	#	 Preprocessor convert to string
	##	 Preprocessor concatenate
3. Перегруженные операторы сохраняют приоритет;
4. 

++, +=......
------------------------------------------
*/