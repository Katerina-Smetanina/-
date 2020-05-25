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

template <class T>
struct Node // ячейка дерева
{
	T data;

	Node<T>* left;	 // левый потомок
	Node<T>* right;	 // правый потомок
	Node<T>* parent; // родитель

	Node(T value, Node<T>* par = NULL)
	{
		data = value;
		left = NULL;
		right = NULL;
		parent = par;
	}

	bool operator>(Node<T> node)
	{
		return data > node.data;
	}
};

template <class T>
struct BinTree
{
	Node<T>* root; // корневой элемент
	int count = 0;

	BinTree()
	{
		root = NULL;
	}

	bool Add(T value)
	{
		Node<T>* newNode = new Node<T>(value);

		Node<T>* par = root;	 // элемент, который мы рассматриваем в данный момент
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
			return false;
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
		return true;
	}

	Node<T>* FindNode(T value)
	{
		Node<T>* temp = root;

		while (temp != NULL && temp->data != value) // перебираем элементы, пока не находим нужный или пока не переберём все
			temp = temp->data > value ? temp->left : temp->right;

		return temp;
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

	bool DeleteNode(T value)
	{
		return DeleteNodeA(FindNode(value));
	}

	bool DeleteNodeA(Node<T>* node)
	{
		if (node == NULL)
			return false;

		if (node->left != NULL && node->right != NULL)
		{
			Node<T>* temp = FindMaxNode(node->left);
			node->data = temp->data;

			return DeleteNodeA(temp);
		}

		if (node->left != NULL)
			node->left->parent = node->parent;
		else if (node->right != NULL)
			node->right->parent = node->parent;

		if (node != root)
		{
			if (node == node->parent->right)
				node->parent->right = node->left != NULL ? node->left : node->right;
			else
				node->parent->left = node->left != NULL ? node->left : node->right;
		}
		else
		{
			root = node->left != NULL ? node->left : node->right;
		}

		delete node;
		return true;
	}

	void print_tree(Node<T>* p, int level)
	{
		if (p == NULL)
			return;

		print_tree(p->left, level + 1);

		for (int i = 0; i < level; i++)
			cout << ".";

		cout << p->data << endl;

		print_tree(p->right, level + 1);
	}

	void print(int type = 0, char sep = ' ')
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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	BinTree<ll> bt;
	string command;
	ll temp;

	while (!cin.eof())
	{
		cin >> command;

		if (command == "ADD")
		{
			cin >> temp;
			if (bt.Add(temp))
				cout << "DONE" << endl;
			else
				cout << "ALREADY" << endl;
		}
		else if (command == "DELETE")
		{
			cin >> temp;
			if (bt.DeleteNode(temp))
				cout << "DONE" << endl;
			else
				cout << "CANNOT" << endl;
		}
		else if (command == "SEARCH")
		{
			cin >> temp;
			if (bt.FindNode(temp) != NULL)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else if (command == "PRINTTREE")
		{
			bt.print_tree(bt.root, 0);
		}
		command = "";
	}

	return 0;
}