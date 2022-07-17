#pragma warning(disable:4326)
#include<iostream>
#include<Windows.h>
using namespace std;

namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,

		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
		console_default = 0x07
	};
	enum Defaults
	{
		start_x_min = 100,
		start_y_min = 100,
		start_x_max = 800,
		start_y_max = 500,

		line_width_min = 1,
		line_width_max = 30,
		primary_size_min = 5,
		primary_size_max = 500,
	};

#define SHAPE_TAKE_PARAMETERS	Color color, unsigned int start_x, unsigned int start_y, unsigned int line_width
#define SHAPE_GIVE_PARAMETERS	color, start_x, start_y, line_width

	class Shape
	{
	protected:
		Color color;
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
	public:
		Color get_color()const
		{
			return color;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}

		void set_start_x(unsigned int start_x)
		{
			if (start_x < Defaults::start_x_min)start_x = Defaults::start_x_min;
			if (start_x > Defaults::start_x_max)start_x = Defaults::start_x_max;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y < Defaults::start_y_min)start_y = Defaults::start_y_min;
			if (start_y > Defaults::start_y_max)start_y = Defaults::start_y_max;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width < Defaults::line_width_min)line_width = Defaults::line_width_min;
			if (line_width > Defaults::line_width_max)line_width = Defaults::line_width_max;
			this->line_width = line_width;
		}

		Shape(SHAPE_TAKE_PARAMETERS) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}


		//Чисто-виртуальные методы и делают класс абстрактным:
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;

		virtual void info()const
		{
			cout << "Площадь  фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};

	/*class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side < Defaults::primary_size_min)side = Defaults::primary_size_min;
			if (side > Defaults::primary_size_max)side = Defaults::primary_size_max;
			this->side = side;
		}
		Square(double side, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
		}
		~Square() {}

		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_side() << endl;
			Shape::info();
		}
	};*/

	class Rectangle :public Shape
	{
		double width;
		double height;
	public:
		double get_width()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		void set_width(double width)
		{
			if (width < Defaults::primary_size_min)width = Defaults::primary_size_min;
			if (width > Defaults::primary_size_max)width = Defaults::primary_size_max;
			this->width = width;
		}
		void set_height(double height)
		{
			if (height < Defaults::primary_size_min)height = Defaults::primary_size_min;
			if (height > Defaults::primary_size_max)height = Defaults::primary_size_max;
			this->height = height;
		}
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_height(height);
		}
		~Rectangle() {}

		double get_area()const
		{
			return width * height;
		}
		double get_perimeter()const
		{
			return (width + height) * 2;
		}
		void draw()const
		{
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);*/
			//1) Получаем окно консоли:
			HWND hwnd = GetConsoleWindow();
			//2) Получаем контекст устройства для нашего окна консоли:
			HDC hdc = GetDC(hwnd);	//то, НА ЧЕМ мы будем рисовать
			//3) Создаем карандаш:
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);//карандаш рисует контур фигуры
			//4) Создаем кисть:
			HBRUSH hBrush = CreateSolidBrush(color);	//кисть заливает замкнутую фигуру
			//hPen и hBrush - это то, ЧЕМ мы будем рисовать

			//Выбираем, ЧЕМ, и НА ЧЕМ будем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Когда мы выбрали чем, и на чем рисовать, рисуем фигуру:
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);

			//Освобождаем ресурсы:
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина прямоугольника: " << get_width() << endl;
			cout << "Высота прямоугольника: " << get_height() << endl;
			Shape::info();
		}
	};
	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_width() << endl;
			Shape::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::console_blue, 0, 0, 1);
	Geometry::Square square(55, Geometry::Color::console_red, 300, 100, 5);
	/*cout << "Длинна стороны:   " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата:" << square.get_perimeter() << endl;
	square.draw();*/
	//square.info();
	square.draw();

	Geometry::Rectangle rect(100, 70, Geometry::Color::blue, 300, 300, 5);
	//rect.info();
	rect.draw();
}