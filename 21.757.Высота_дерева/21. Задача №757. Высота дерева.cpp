// 21. Задача №757. Высота дерева.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#define ll long long

#include <stdio.h>
#include <limits.h>

#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <cstdio>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <regex>
#include <map>
#include <set>

using namespace std;

template<class T>
struct Node // ячейка дерева
{
	T data;

	Node<T>* left; // левый потомок
	Node<T>* right; // правый потомок
	Node<T>* parent; // родитель

	Node(T value, Node<T>* par = NULL)
	{
		data = value;
		left = NULL;
		right = NULL;
		parent = par;
	}

	bool operator >(Node<T> node)
	{
		return data > node.data;
	}
};

template<class T>
struct BinTree
{
	Node<T>* root; // корневой элемент
	int count = 0;

	BinTree()
	{
		root = NULL;
	}

	void Add(T value)
	{
		Node<T>* newNode = new Node<T>(value);

		Node<T>* par = root; // элемент, который мы рассматриваем в данный момент
		Node<T>* prevPar = NULL; // предшествующий ему элемент

		// спускаемся по дереву, пока не находим свободное место, либо элемент с таким же значением
		while (par != NULL && par->data != value)
		{
			prevPar = par;

			if (*par > * newNode)
				par = par->left;
			else
				par = par->right;
		}

		// если элемент с таким же значеним уже есть в дереве, то мы удаляем созданную ячейку и выходим
		// т.к. в дереве не должно быть повторяющихся элементов
		if (par != NULL && par->data == value)
		{
			delete newNode;
			return;
		}

		// ставим новый элемент на свободное место место
		newNode->parent = prevPar;

		if (prevPar == NULL) // такое возможно только тогда, когда root == NULL, т.е. дерево пустое
		{
			root = newNode;
		}
		else
		{
			if (*prevPar > * newNode)
				prevPar->left = newNode;
			else
				prevPar->right = newNode;
		}
	}

	Node<T>* FindNode(T value)
	{
		Node<T>* temp = root;

		while (temp != NULL && temp->data != value) // перебираем элементы, пока не находим нужный или пока не переберём все
			temp = temp->data > value ? temp->left : temp->right;

		return temp;
	}

	Node<T>* FindNextNode(T value)
	{
		return FindNextNode(FindNode(value));
	}

	Node<T>* FindNextNode(Node<T>* temp) //Взято из интернетов
	{
		Node<T>* res;

		if (temp == NULL)
			return NULL;
		if (temp->right != NULL)
			return FindMinNode(temp->right);

		res = temp->parent;

		while (res != NULL && temp == res->right)
		{
			temp = res;
			res = res->parent;
		}

		return res;
	}

	Node<T>* FindMinNode(Node<T>* temp)
	{
		if (temp == NULL)
			throw "Empty tree";

		while (temp->left != NULL)
			temp = temp->left;

		return temp;
	}

	Node<T>* FindMaxNode(Node<T>* temp)
	{
		if (temp == NULL)
			throw "Empty tree";

		while (temp->right != NULL)
			temp = temp->right;

		return temp;
	}

	T Min()
	{
		return FindMinNode(root)->data;
	}

	T Max()
	{
		return FindMaxNode(root)->data;
	}

	Node<T>* DeleteNode(T value)
	{
		return DeleteNode(FindNode(value));
	}

	Node<T>* DeleteNode(Node<T>* node) //Взято из интернетов
	{
		Node<T>* res;
		Node<T>* temp;

		if (node->left == NULL || node->right == NULL)
			res = node;
		else
			res = FindNextNode(node->data);

		if (res->left != NULL)
			temp = res->left;
		else
			temp = res->right;

		if (temp != NULL)
			temp->parent = res->parent;

		if (res->parent == NULL)
			root = temp;
		else
		{
			if (res == (res->parent)->left)
				(res->parent)->left = temp;
			else
				(res->parent)->right = temp;
		}

		if (res != node)
			node->data = res->data;

		return res;
	}

	int GetDepth(Node<T>* h, int d = 0)
	{
		if (h == NULL)
			return 0;

		d++;
		return max(d, max(GetDepth(h->left, d), GetDepth(h->right, d)));
	}

	void Print(int type = 0, char sep = ' ')
	{
		if (type == 0)
			LKP(root, sep);
		else if (type > 0)
			KLP(root, sep);
		else
			LPK(root, sep);
	}

	void LKP(Node<T>* node, char sep) // левый корень правый
	{
		if (node->left != NULL)
			LKP(node->left, sep);

		cout << node->data << sep;

		if (node->right != NULL)
			LKP(node->right, sep);
	}

	void KLP(Node<T>* node, char sep) // корень левый правый
	{
		cout << node->data << sep;

		if (node->left != NULL)
			KLP(node->left, sep);

		if (node->right != NULL)
			KLP(node->right, sep);
	}

	void LPK(Node<T>* node, char sep) // левый правый корень
	{
		if (node->left != NULL)
			LPK(node->left, sep);

		if (node->right != NULL)
			LPK(node->right, sep);

		cout << node->data << sep;
	}
};


int main()
{
	BinTree<int> temp;
	int _;

	cin >> _;

	for (; _ != 0; cin >> _) {
		temp.Add(_);
	}

	cout << temp.GetDepth(temp.root);

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
