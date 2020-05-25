// 15 112984. Гоблины и шаманы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#include <iostream>
using namespace std;
	template<class T>
	struct Node // ячейка очереди
	{
		Node* next; // указатель на следующую ячейку
		T value; // значение, хранимое в ячейке

		Node(T value)
		{
			this->next = NULL;
			this->value = value;
		}

	};

	template<class T>
	struct Queue
	{
		long long count; // кол-во элементов в очереди

		Node<T>* first; // указатель на первый элемент в очереди
		Node<T>* last; // указатель на последний элемент в очереди
		Node<T>* middle;

		Queue()
		{
			count = 0;
			first = NULL;
			last = NULL;
			middle = NULL;
		}

		void Push(T value)
		{
			Node<T>* temp = new Node<T>(value); // сначала создаём новую ячейку

			// если очередь не пустая
			// следующей за последней ячейкой в очереди будет наша новая ячейка
			// указатель на последний элемент будет указывать на нашу новую ячейку
			if (count > 0)
			{
				last->next = temp;
				last = temp;

				if (count % 2 == 0)
					middle = middle->next;
			}
			else
			{
				first = temp;
				last = temp;
				middle = temp;
			}

			//увеличиваем кол-во элементов на 1
			count++;
		}

		void CoolPush(T value)
		{
			if (count > 1)
			{
				Node<T>* temp = new Node<T>(value);
				temp->next = middle->next;
				middle->next = temp;

				if (count % 2 == 0)
					middle = temp;

				count++;
			}
			else
			{
				Push(value);
			}

		}

		T Pop()
		{
			T temp = first->value; // сохраняем значение
			Node<T>* toDelete = first; // сохраняем указатель на ячейку, которую нужно удалить
			first = first->next; // теперь первым элементом в очереди будет следующая ячейка

			if (count % 2 == 0 && count > 1)
			{
				middle = middle->next;
			}
			else if (count == 1)
			{
				middle = NULL;
			}

			count--;
			delete toDelete; // удаляем старую ненужную ячейку 

			return temp; // возвращаем значение
		}

		T First()
		{
			return first->value; // возвращаем значение первого элемента
		}

		T Last()
		{
			return last->value; // возвращаем значение последнего элемента
		}

		long long Count()
		{
			return count;
		}

		void Clear()
		{
			//в temp хранится указатель на ячейку, которую будем удалять
			//в next хранится следующая за temp ячейка
			Node<T>* temp = first;
			Node<T>* next;

			//удаляем ячейки, пока не удалим все
			while (temp != NULL)
			{
				next = temp->next;
				delete temp;
				temp = next;
			}

			//обнуяем все значения
			first = NULL;
			last = NULL;
			count = 0;
		}
	};

	int main()
	{
		Queue<ll> q;

		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);

		char command;
		ll temp;
		int n;

		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> command;
			if (command == '+')
			{
				cin >> temp;
				q.Push(temp);
			}
			else if (command == '-')
			{
				cout << q.Pop() << '\n';
			}
			else if (command == '*')
			{
				cin >> temp;
				q.CoolPush(temp);
			}
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
