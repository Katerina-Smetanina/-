// 13.112511.Словарь по частотам.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<fstream>
#include<string>
#include <iostream>
using namespace std;

	struct Node // ячейка
	{
		Node* previous; // указатель на предыдущую ячейку
		Node* next; // указатель на следующую ячейку
		string value; // значение, хранимое в ячейке
		int count;

		Node()
		{
			next = NULL;
			previous = NULL;
			count = 0;
		}

		Node(string value)
		{
			this->next = NULL;
			this->previous = NULL;
			this->value = value;
			this->count = 1;
		}
	};


	struct Stack
	{
		long long count;

		Node* head; // указатель на левую границу
		Node* tail; // указатель на правую границу

		Stack()
		{
			count = 0;

			head = new Node();
			tail = new Node();

			head->next = tail;
			tail->previous = head;
		}

		void Add(string value)
		{
			Node* cur = tail;

			while (cur->previous != head && cur->previous->value < value)
			{
				cur = cur->previous;
			}

			if (cur->previous == head)
			{
				cur->previous = new Node(value);
				cur->previous->next = cur;
				head->next = cur->previous;
				cur->previous->previous = head;

				count++;
			}
			else if (cur->previous->value == value)
				cur->previous->count++;
			else
			{
				Node* temp = new Node(value);
				cur->previous->next = temp;
				temp->previous = cur->previous;
				temp->next = cur;
				cur->previous = temp;

				count++;
			}
		}

		void Sort()
		{
			Node* cur = head->next;
			for (int i = 0; i < count; i++)
			{
				cur = head->next;
				for (int j = 0; j < count - i - 1; j++, cur = cur->next)
				{
					if (cur->count > cur->next->count)
					{
						string temp = cur->value;
						cur->value = cur->next->value;
						cur->next->value = temp;

						int tmp = cur->count;
						cur->count = cur->next->count;
						cur->next->count = tmp;
					}
				}
			}
		}

		string First()
		{
			if (count > 0)
				return head->next->value;
			else
				throw "Empty queue";
		}

		string Last()
		{
			if (count > 0)
				return tail->previous->value;
			else
				throw "Empty queue";
		}

		long long Count()
		{
			return count;
		}

		bool IsEmpty()
		{
			return count == 0;
		}

		void Clear()
		{
			Node* temp = head->next;
			Node* next;

			while (temp != tail)
			{
				next = temp->next;
				delete temp;
				temp = next;
			}

			head->next = tail;
			tail->previous = head;
			count = 0;
		}

		void Print()
		{
			Node* temp = tail->previous;
			while (temp != head)
			{
				cout << temp->value << ' ' << temp->count << '\n';
				temp = temp->previous;
			}
		}

		void DebugPrint() {
			Node* temp = head->next;
			while (temp != tail)
			{
				cout << temp->value << ' ' << temp->count << '\n';
				temp = temp->next;
			}
		}
	};


	int main(){
		ifstream input("input.txt");
		freopen("output.txt", "w", stdout);
		Stack stack;
		string word;

		try
		{
			while (!input.eof())
			{
				getline(input, word);
				if (word == "")
					break;

				stack.Add(word);
			}

			stack.Sort();
			stack.Print();
		}
		catch (...)
		{
			cout << "ERROR";
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
