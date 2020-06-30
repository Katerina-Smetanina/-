#include <cstdio>
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
		for (int i = 0; i < count; i++) {
			cur = head->next;

			for (int j = 0; j < count - i - 1; j++, cur = cur->next) {

				if (cur->count > cur->next->count) {
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

	void Print() {
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


int main() {
	ifstream input("input.txt");
	freopen("output.txt", "w", stdout);
	Stack stack;
	string word;



	while (!input.eof())
	{
		getline(input, word);
		if (word == "")
			break;

		stack.Add(word);
	}

	stack.Sort();
	stack.Print();

	return 0;
}
