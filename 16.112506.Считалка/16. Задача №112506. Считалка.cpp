// 16. Задача №112506. Считалка.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

template<class T>
struct Node // ячейка
{
	Node(T value)
	{
		this->next = NULL;
		this->previous = NULL;
		this->value = value;
	}

	Node* previous; // указатель на предыдущую ячейку
	Node* next; // указатель на следующую ячейку
	T value; // значение, хранимое в ячейке
};

template<class T>
struct Cl
{
	long long count;

	Node<T>* head;
	Node<T>* tail;
	Node<T>* curr;

	Cl()
	{
		count = 0;
		head = NULL;
		tail = NULL;
		curr = NULL;
	}

	void Add(T value)
	{
		Node<T>* temp = new Node<T>(value);

		if (count == 0)
		{
			head = temp;
			tail = temp;

			temp->next = temp;
			temp->previous = temp;

			curr = temp;
		}
		else
		{
			temp->next = head;
			head->previous = temp;

			temp->previous = tail;
			tail->next = temp;
			tail = temp;
		}

		count++;
	}

	void Next()
	{
		curr = curr->next;
	}

	void Previous()
	{
		curr = curr->previous;
	}

	T Value()
	{
		return curr->value;
	}

	T Remove()
	{
		T temp = Value();

		if (curr == curr->next)
		{
			head = NULL;
			tail = NULL;

			delete curr;

			curr = NULL;
		}
		else
		{
			curr->next->previous = curr->previous;
			curr->previous->next = curr->next;

			if (curr == head)
			{
				head = curr->next;
			}
			if (curr == tail)
			{
				tail = curr->previous;
			}

			Node<T>* n = curr->next;
			delete curr;
			curr = n;
		}

		count--;
		return temp;
	}

	long long Count()
	{
		return count;
	}

	void Clear()
	{
		Node<T>* temp = head->next;
		Node<T>* next;

		while (temp != temp->next)
		{
			next = temp->next;
			Remove(temp);
			temp = next;
		}

		head = NULL;
		tail = head;
		count = 0;
	}
};

int main()
{
	int n, k;
	cin >> n >> k;

	Cl<int> _;

	for (int i = 1; i <= n; i++)
	{
		_.Add(i);
	}

	for (; _.Count() > 0;)
	{
		for (int i = 1; i < k; i++)
		{
			_.Next();
		}
		cout << _.Remove() << ' ';
	}

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
