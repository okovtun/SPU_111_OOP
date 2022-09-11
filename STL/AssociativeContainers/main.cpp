#include<iostream>
#include<string>
#include<map>
#include<set>
#include<list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define STL_SET
//#define STL_MAP

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_SET
	std::multiset<int> set = { 50, 50, 50, 50, 25, 75, 16, 32, 32, 32, 32, 64, 64, 64, 64, 64, 80 };
	for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // STL_SET

#ifdef STL_MAP
	//Каждым элементом map является пара "ключ-значение" pair<key, value>
	//multimap

	std::multimap<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(1, "Monday"),
		{2, "Tuesday"},
		{3, "Wednesday"},
		{4, "Thursday"},
		{5, "Friday"},
		{6, "Saturday"},
		{7, "Sunday"},
		{7, "Sunday"},
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << " - " << it->second << endl;
	}
#endif // STL_MAP

	std::map<std::string, std::list<std::string>> dictionary = 
	{
		std::pair<std::string, std::list<std::string>>("deprecation", {"осуждение", "неодобрение", "протест", "возражение"}),
		{"rest", {"отдыхать", "лежать"}},
		{"space", {"пробел", "пространство", "космос"}}
	};
	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout << it->first << ":\t";
		for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt << "\t";
		}
		cout << endl;
	}
	//https://cplusplus.com/reference/stl/
}