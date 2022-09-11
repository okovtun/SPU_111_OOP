#include<iostream>
#include<array>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define STL_ARRAY
#define STL_VECTOR

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - это контейнер, который хранит данные в виде статического массива.
	const int N = 5;
	std::array<int, N> arr = { 3,5,8,13,21 };
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнер, который хранит данные в виде динамического массива.
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	try
	{
		for (int i = 0; i < vec.size() * 2; i++)
		{
			//cout << vec[i] << tab;	//бросает аппаратное исключение
			cout << vec.at(i) << tab;	//бросает исключение C++, которое можно обработать
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	cout << "Size:    " << vec.size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "Max size:" << vec.max_size() << endl;

	vec.push_back(55);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

	cout << "Size:    " << vec.size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "Max size:" << vec.max_size() << endl;

	cout << vec.front() << endl;
	cout << vec.back() << endl;

	int index;
	int count;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите количество добавляемых элементов: "; cin >> count;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	vec.insert(vec.begin() + index, count, value);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << *(vec.data() + i) << tab;
	}
	cout << endl;
#endif // STL_VECTOR

}