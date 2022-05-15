#include<iostream>
using namespace std;

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
};

//#define STRUCT_POINT

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

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
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