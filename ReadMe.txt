https://github.com/okovtun/SPU_111_OOP.git
https://www.youtube.com/watch?v=MQwW_YFhVCU&list=PLeqyOOqxeiIPy9kTEWJfeRfP1SlTccBPQ
https://meet.google.com/mho-khdw-fhj

TOREAD:
https://drive.google.com/drive/folders/1mIhAKMp5-Jpy6s5X8u924tRCXFEdHE_z?usp=sharing
https://ru.wikipedia.org/wiki/CSV
https://cplusplus.com/reference/cstring/strtok/

TODO:
1. Упростить процедуры добавления элементов до одного выражения;
2. Проверочный код должен заработать:
	List list = { 3, 5, 8, 13, 21 };
	for(int i:list)
		cout << i << tab; 
	cout << endl;
3. Обеспечить вывод списка в main() в обратном порядке;

DONE:
1. Написать и проветрить метод erase(). Метод erase() удаляет значение по индексу;
2. Проверочный код должен заработать:			DONE
	ForwardList list1 = { 3, 5, 8, 13, 21 };
	ForwardList list2 = { 34, 55, 89 };
	ForwardList list3 = list1 + list2;
3. Проверочный код должен заработать:
	ForwardList list = { 3, 5, 8, 13, 21 };
	for(int i: list)
	{
		cout << i << tab;
	}
	cout << endl;

DONE:
1. Во все геометрические фигуры добавить атрибут 'filled', который определяет, закрашена ли фигура, DONE
   или же отображается контуром;
2. В иерархию геометрических фигур добавить класс Circle.						DONE
   Круг можно нарисовать используя функцию Ellipse из библиотеки WinGDI;
3. В иерархию геометрических фигур добавить иерархию треугольников.				DONE
   Треугольник можно нарисовать используя функцию Polygon из библиотеки WinGDI;
4. Реализовать класс Паралелограмм;
5. В отдельной ветке нарисовать все эти фигуры используя библиотеку DirectX или OpenGL;

DONE:
Реализовать иерархию классов геометрических фигур: 
квадрат, прямоугольник, круг, треугольник и т.д.
Для каждой фигуры нужно найти площадь, периметр, 
вывести их на экран,
а также вывести на экран первичные свойства фигуры
(для квадрата это длина стороны, для прямоугольника - высота, ширина,
для круга - радиус.....)
Каждую фигуру нужно нарисовать.

TOREAD:
https://cplusplus.com/doc/tutorial/classes2/

TODO:
В Solution Inheritance добавить проект Network и в этом проекте взять файл:
https://github.com/okovtun/PV_011/blob/master/STL/Files/Task/201%20RAW.txt
и в этом файле поменять местами столбцы с IP-адресом и MAC-адресом,
при этом должен создаться новый файл.
В этом же проекте, из файла 201RAW.txt создать файл формата:
https://github.com/okovtun/PV_011/blob/master/STL/Files/Task/201.dhcpd

DONE:
1. Создать ветку AcademySeparated, и в этой ветке вынести все классы проекта Academy в отдельные файлы;
2. Для всех классов перегрузить оператор вывода на экран;

DONE:
1. От ветки master создать ветку FractionSeparated, и в этой ветке
   разделить классы Fraction и Point на файлы;
2. Вычислить, сколько памяти занимает 1 кадр с разрешением FullHD;
3. Вычислить, сколько памяти занимает 1 кадр с разрешением 4K;
4. В классе String реализовать MoveAssignment;

DONE:
1. Для класса String перегрузить оператор ввода:
	String str;
	cout << "Введите строку: "; cin >> str;
2. Написать метод void to_upper(), который переводит строку в верхний регистр;
3. Написать метод void to_lower(), который переводит строку в нижний регистр;
4. Реализовать метод ??? is_palindrome(???), который опеределяет,
   является ли строка палиндромом

DONE:
1. Проверчный код в секции CONVERSIONS_HOME_WORK должен заработать:
	https://github.com/okovtun/SPU_111_OOP/blob/a434eb0cd56ac34d91ff59951c5d6d8e5b2afa61/IntroductionToOOP/Fraction/main.cpp#L361
	https://www.webmath.ru/poleznoe/formules_12_7.php
2. В Solution IntroductionToOOP добавить проект String и реализовать в нем класс String,
   описывающий строку. Обеспечить следующие варианты создания объектов:
   String str1;		//создает пустую строку размером 80 Byte
   String str2(44);	//создает пустую строку заданного размера, в данном случае 44 Байта
   String str3 = "Hello";
   String str4 = "World";
   String str5 = str3 + str4;
   cout << str5 << endl;

   cout << "Введите строку: "; cin >> str1;

DONE:
Для класса Fraction перегрузить:
1. Арифметические операторы:+, -, *, /;
2. Составные присваивания:	+=, -=, *=, /=;
3. Incremento/Decremento;
4. Операторы сравнения: ==, !=, >, <, >=, <=;

DONE:
В новом проекте реализовать класс Fraction, опиывающий простую дробь.
В классе должны быть все необходимые методы и операторы.

DONE:
1. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
2. Написать метод ??? distance(???), который возвращает расстояние до указанной точки;		DONE
3. Написать функцию ??? distance(???), которая возвращает расстояние между двумя точками;	DONE