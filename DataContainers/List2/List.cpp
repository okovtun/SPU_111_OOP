#include"List.h"

////////////////////////////////////////////////////////////////////////////////////////////
//////////////////			����������� ������ - CLASS DEFINITION		////////////////////

////////////////////////////////////////////////////////////////////////////////////////////
//////////////////						Element						////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>List<T>::Element::Element(T Data, Element* pNext, Element* pPrev)
	:Data(Data), pNext(pNext), pPrev(pPrev)
{
	cout << "EConstructor:\t" << this << endl;
}
template<typename T>List<T>::Element::~Element()
{
	cout << "EDestructor:\t" << this << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////
//////////////////					ConstIterators						////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>List<T>::ConstBaseIterator::ConstBaseIterator(Element* Temp) :Temp(Temp)
{
#ifdef DEBUG
	cout << "CBItConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>List<T>::ConstBaseIterator::~ConstBaseIterator()
{
#ifdef DEBUG
	cout << "CBItDestructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>bool List<T>::ConstBaseIterator::operator==(const ConstBaseIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>bool List<T>::ConstBaseIterator::operator!=(const ConstBaseIterator& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>const T& List<T>::ConstBaseIterator::operator*()const
{
	return Temp->Data;
}

//-------------------------------------------------------------------

template<typename T>List<T>::ConstIterator::ConstIterator(Element* Temp) :ConstBaseIterator(Temp)
{
	cout << "ItConstructor:\t" << this << endl;
}
template<typename T>List<T>::ConstIterator::~ConstIterator()
{
	cout << "ItDestructor:\t" << this << endl;
}
template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
{
	ConstIterator old = *this;	//��������� ������ �������� ���������
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}
template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}

//---------------------------------------------------------------

template<typename T>List<T>::ConstReverseIterator::ConstReverseIterator(Element* Temp) :ConstBaseIterator(Temp)
{
#ifdef DEBUG
	cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>List<T>::ConstReverseIterator::~ConstReverseIterator()
{
#ifdef DEBUG
	cout << "RItDestructor:\t" << this << endl;
#endif // DEBUG
}

template<typename T>
typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}

template<typename T>
typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator++(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}
template<typename T>
typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>
typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator--(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}

////////////////////////////////////////////////////////////////////////////////////////////
//////////////////						Iterators						////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>T& List<T>::Iterator::operator*()
{
	return ConstBaseIterator::Temp->Data;
}
template<typename T>T& List<T>::ReverseIterator::operator*()
{
	return ConstBaseIterator::Temp->Data;
}

////////////////////////////////////////////////////////////////////////////////////////////
//////////////////						List							////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>typename List<T>::ConstIterator List<T>::cbegin()const
{
	return Head;
}
template<typename T>typename List<T>::ConstIterator List<T>::cend()const
{
	return nullptr;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::crbegin()const
{
	return Tail;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::crend()const
{
	return nullptr;
}
template<typename T>typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template<typename T>typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}
//					Constructors:
template<typename T>List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>List<T>::List(const std::initializer_list<T>& il) :List()
{
	for (T const* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
}
template<typename T>List<T>::List(const List& other) :List()
{
	*this = other;
}
template<typename T>List<T>::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
	cout << "LDestructor:\t" << this << endl;
}

//					Operators:
template<typename T>List<T>& List<T>::operator=(const List<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	return *this;
}

//					Adding elements:
template<typename T>void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
		size++;
		return;
	}
	Head = Head->pPrev = new Element(Data, Head);
	size++;
}
template<typename T>void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)return push_front(Data);
	Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	size++;
}
template<typename T>void List<T>::insert(T Data, int Index)
{
	if (Index > size)return;
	if (Index == size)return push_back(Data);
	if (Index == 0)return push_front(Data);
	Element* Temp;
	if (Index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < Index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
	}
	Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
	size++;
}

//					Removing elements:
template<typename T>void List<T>::pop_front()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
		size--;
		return;
	}
	Head = Head->pNext;
	delete Head->pPrev;
	Head->pPrev = nullptr;
	size--;
}
template<typename T>void List<T>::pop_back()
{
	if (Head == Tail)return pop_front();
	Tail = Tail->pPrev;
	delete Tail->pNext;
	Tail->pNext = nullptr;
	size--;
}
template<typename T>void List<T>::erase(int index)
{
	if (index >= size)return;
	if (index == size - 1)return pop_back();
	if (index == 0)return pop_front();
	Element* Temp;
	if (index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
	}
	//1) ��������� ������� �� ������
	Temp->pPrev->pNext = Temp->pNext;
	Temp->pNext->pPrev = Temp->pPrev;
	//2) ������� ������� �� ������:
	delete Temp;
	size--;
}

//					Methods:
template<typename T>void List<T>::print()const
{
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "���������� ��������� ������: " << size << endl;
}
template<typename T>void List<T>::reverse_print()const
{
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "���������� ��������� ������: " << size << endl;
}

template<typename T>List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> cat = left;
	for (typename List<T>::ConstIterator it = right.cbegin(); it != right.cend(); ++it)
	{
		cat.push_back(*it);
		//*it *= 10;
	}
	return cat;
}
//////////////////	  ����� ����������� ������ - CLASS DEFINITION	END	////////////////////
////////////////////////////////////////////////////////////////////////////////////////////