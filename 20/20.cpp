// 20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#define ll long long

#include <stdio.h>
#include <limits.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <regex>
#include <map>
#include <set>

using namespace std;

struct Node
{
	int value;
	Node* next, * prev;

	Node(int value)
	{
		this->value = value;
		this->next = NULL;
		this->prev = NULL;
	}
};

class List
{
public:
	Node* head, * tail;
	int count;

	List();
	List(const List&);
	List(int count, int value = 0);
	~List();

	int Count();
	Node* At(int);
	int Value(int);
	void Clear();
	void Remove(int pos);
	void Remove(Node*);
	void Insert(int pos, int value);
	void PushBack(int n);
	void PushFront(int n);
	void Print();

	List& operator = (const List&);
	List operator + (const List&);

	bool operator == (const List&);
	bool operator != (const List&);
	bool operator <= (const List&);
	bool operator >= (const List&);
	bool operator < (const List&);
	bool operator > (const List&);

	List operator - ();
};

List::List()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

List::List(const List& L)
{
	head = NULL;
	tail = NULL;
	count = 0;

	Node* temp = L.head;
	while (temp != 0)
	{
		PushBack(temp->value);
		temp = temp->next;
	}
}

List::List(int count, int value)
{
	head = NULL;
	tail = NULL;
	this->count = 0;

	for (int i = 0; i < count; i++)
	{
		PushBack(value);
	}
}


List::~List()
{
	Clear();
}

void List::PushFront(int n)
{
	Node* temp = new Node(n);

	temp->next = head;

	if (head != 0)
		head->prev = temp;

	if (count == 0)
		head = tail = temp;
	else
		head = temp;

	count++;
}

void List::PushBack(int n)
{
	Node* temp = new Node(n);

	temp->prev = tail;

	if (tail != 0)
		tail->next = temp;

	if (count == 0)
		head = tail = temp;

	else
		tail = temp;

	count++;
}

void List::Insert(int pos, int value)
{
	if (pos < 0 || pos > count)
	{
		throw "Incorrect position";
	}

	if (pos == count)
	{
		PushBack(value);
		return;
	}

	else if (pos == 0)
	{
		PushFront(value);
		return;
	}

	Node* temp = head;

	for (int i = 0; i < pos; i++)
	{
		temp = temp->next;
	}

	Node* prevTemp = temp->prev;
	Node* tmp = new Node(value);

	prevTemp->next = tmp;
	temp->prev = tmp;

	tmp->next = temp;
	tmp->prev = prevTemp;

	count++;
}

void List::Remove(int pos)
{
	if (pos < 0 || pos >= count)
	{
		throw "Incorrect position";
	}

	Node* temp = head;

	for (int i = 0; i < pos; i++)
	{
		temp = temp->next;
	}

	Node* prevTemp = temp->prev;
	Node* nextTemp = temp->next;

	if (prevTemp != 0)
		prevTemp->next = nextTemp;

	if (nextTemp != 0)
		nextTemp->prev = prevTemp;

	if (pos == 0)
		head = nextTemp;

	if (pos == count - 1)
		tail = prevTemp;

	delete temp;

	count--;
}

void List::Remove(Node* node)
{
	if (node->next != NULL)
		node->next = node->prev;
	if (node->prev != NULL)
		node->prev = node->next;
	if (head == node)
		head = node->next;
	if (tail == node)
		tail = node->prev;

	count--;
}

void List::Print()
{
	if (count != 0)
	{
		Node* temp = head;

		while (temp->next != 0)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}

		cout << temp->value << "\n";
	}
}

void List::Clear()
{
	while (count != 0)
		Remove(0);
}

int List::Count()
{
	return count;
}

Node* List::At(int index)
{
	if (index < 0 || index >= count)
	{
		throw "Incorrect position";
	}

	Node* temp = head;

	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	return temp;
}

int List::Value(int index)
{
	return At(index)->value;
}

List& List::operator = (const List& L)
{
	if (this == &L)
		return *this;

	this->~List();

	Node* temp = L.head;

	while (temp != 0)
	{
		PushBack(temp->value);
		temp = temp->next;
	}

	return *this;
}

List List::operator + (const List& L)
{
	List result(*this);

	Node* temp = L.head;

	while (temp != 0)
	{
		result.PushBack(temp->value);
		temp = temp->next;
	}

	return result;
}

bool List::operator == (const List& L)
{
	if (count != L.count)
		return false;

	Node* t1, * t2;

	t1 = head;
	t2 = L.head;

	while (t1 != 0)
	{
		if (t1->value != t2->value)
			return false;

		t1 = t1->next;
		t2 = t2->next;
	}

	return true;
}

bool List::operator != (const List& L)
{
	return !(*this == L);
}

bool List::operator >= (const List& L)
{
	if (count > L.count)
		return true;

	if (*this == L)
		return true;

	return false;
}

bool List::operator <= (const List& L)
{
	if (count < L.count)
		return true;

	if (*this == L)
		return true;

	return false;
}

bool List::operator > (const List& L)
{
	if (count > L.count)
		return true;

	return false;
}

bool List::operator < (const List& L)
{
	if (count < L.count)
		return true;

	return false;
}

List List::operator - ()
{
	List result;

	Node* temp = head;

	while (temp != 0)
	{
		result.PushFront(temp->value);
		temp = temp->next;
	}

	return result;
}


int main()
{
	List temp;
	int ss;
	int n;

	cin >> n;
	cin >> ss;
	temp.PushBack(ss);

	if (n != 1)
	{
		if (n == 2)
		{
			cin >> ss;
			if (temp.Value(0) != ss)
			{
				temp.PushBack(ss);
			}
		}
		else
		{
			bool cur;
			int last = temp.Value(0);
			int i;
			for (i = 1; i < n; i++)
			{
				cin >> ss;
				if (last != ss)
				{
					cur = last > ss;
					last = ss;
					temp.PushBack(last);
					break;
				}
			}

			for (i = i + 1; i < n; i++)
			{
				cin >> ss;
				if (ss != last)
				{
					if ((last > ss) != cur)
					{
						temp.PushBack(ss);
						cur = last > ss;
						last = ss;
					}
					else
					{
						temp.tail->value = ss;
						last = ss;
					}
				}
			}
		}
	}

	temp.Print();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
