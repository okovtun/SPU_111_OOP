#pragma warning(disable:4326)
#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
using namespace std;

namespace Geometry
{
	enum Color
	{
		black = 0x00000000,
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

#define SHAPE_TAKE_PARAMETERS	Color color, unsigned int start_x, unsigned int start_y, unsigned int line_width, bool filled = true
#define SHAPE_GIVE_PARAMETERS	color, start_x, start_y, line_width, filled

	class Shape
	{
	protected:
		Color color;
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
		bool filled;
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
			this->filled = filled;
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
			HBRUSH hBrush = CreateSolidBrush(filled?color:Color::black);	//кисть заливает замкнутую фигуру
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

	class Circle :public Shape
	{
		double radius;
	public:
		double get_radius()const
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius > Defaults::primary_size_max)radius = Defaults::primary_size_max;
			else if (radius < Defaults::primary_size_min)radius = Defaults::primary_size_min;
			this->radius = radius;
		}
		Circle(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_radius(radius);
		}
		~Circle() {}
		double get_area()const
		{
			return M_PI * pow(radius, 2);
		}
		double get_perimeter()const
		{
			return 2 * M_PI*radius;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);	//Взяли контекст устройства
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(filled?color:black);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			Ellipse(hdc, start_x, start_y, start_x + radius * 2, start_y + radius * 2);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);	//Вернули контекст устройства
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус круга: " << get_radius();
			Shape::info();
		}
	};

	class Triangle :public Shape
	{
	public:
		Triangle(SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) {}
		~Triangle() {}
		virtual double get_height()const = 0;
	};

	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side > Defaults::primary_size_max)side = Defaults::primary_size_max;
			if (side < Defaults::primary_size_min)side = Defaults::primary_size_min;
			this->side = side;
		}
		EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
		}
		~EquilateralTriangle() {}
		double get_height()const
		{
			return side * sqrt(3) / 2;
		}
		double get_area()const
		{
			return side * get_height() / 2;
		}
		double get_perimeter()const
		{
			return side * 3;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(filled?color:black);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT point[] =
			{
				{start_x, start_y + get_height()},
				{start_x + side, start_y + get_height()},
				{start_x + side / 2, start_y}
			};
			Polygon(hdc, point, 3);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
	};
	class IsoscelesTriangle :public Triangle
	{
		double base;	//основание
		double side;	//сторона
	public:
		double get_base()const
		{
			return base;
		}
		double get_side()const
		{
			return side;
		}
		void set_base(double base)
		{
			if (base > Defaults::primary_size_max)base = Defaults::primary_size_max;
			if (base < Defaults::primary_size_min)base = Defaults::primary_size_min;
			this->base = base;
		}
		void set_side(double side)
		{
			if (side > Defaults::primary_size_max)side = Defaults::primary_size_max;
			if (side < Defaults::primary_size_min)side = Defaults::primary_size_min;
			this->side = side;
		}
		IsoscelesTriangle(double base, double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_base(base);
			set_side(side);
		}
		~IsoscelesTriangle() {}
		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(base / 2, 2));
		}
		double get_area()const
		{
			return base * side / 2;
		}
		double get_perimeter()const
		{
			return side * 2 + base;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(filled ? color : black);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT point[] = 
			{
				{start_x, start_y+get_height()},
				{start_x+base, start_y+get_height()},
				{start_x+base/2, start_y}
			};
			Polygon(hdc, point, 3);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
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

	Geometry::Rectangle rect(100, 70, Geometry::Color::blue, 300, 300, 15, false);
	//rect.info();
	rect.draw();

	Geometry::Circle circle(100, Geometry::Color::yellow, 800, 100, 5);
	circle.info();

	Geometry::EquilateralTriangle etr(150, Geometry::Color::green, 500, 300, 15);
	etr.info();

	Geometry::IsoscelesTriangle iso_tri(50, 100, Geometry::Color::blue, 400, 400, 5);
	iso_tri.info();
}