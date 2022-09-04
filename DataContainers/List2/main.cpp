#include"List.cpp"

//#define BASE_CHECK
//#define ITERATORS_CHECK
//#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(value, index);
	list.print();
	list.reverse_print();
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erase(index);
	list.print();
	list.reverse_print();
#endif // BASE_CHECK

#ifdef ITERATORS_CHECK
	List list = { 3,5,8,13,21 };
	list.print();

	for (int i : list)cout << i << tab; cout << endl;

	for (List::ReverseIterator it = list.rbegin(); it != list.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // ITERATORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	List<int> list1 = { 3,5,8,13,21 };
	List<int> list2 = { 34,55,89 };
	List<int> list3 = list1 + list2;
	/*list3.print();
	list1.print();
	list2.print();*/
	for (int i : list1)cout << i << tab; cout << endl;
	for (List<int>::ReverseIterator it = list2.rbegin(); it != list2.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (List<int>::Iterator it = list3.begin(); it != list3.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // OPERATOR_PLUS_CHECK

	List<int> i_list = { 3,5,8,13,21 };
	for (int i : i_list)cout << i << tab; cout << endl;

	List<double> d_list = { 2.5, 3.14, 5.3, 8.4 };
	for (double i : d_list)cout << i << tab; cout << endl;
	for (List<double>::ConstReverseIterator it = d_list.crbegin(); it != d_list.crend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
}

/*
---------------------------------
Class object;
Class<type> object;

template<typename T>
---------------------------------
*/