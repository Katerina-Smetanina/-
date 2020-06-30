// 5.112139.Помехи при передаче информации.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> vec;
string source, final;

int func(int i, int j) {
	if (i < 0) return j + 1;
	if (j < 0) return i + 1;
	if (vec[i][j] == -1) {
		vec[i][j] = 1 + func(i - 1, j);
		vec[i][j] = min(vec[i][j], 1 + func(i, j - 1));
		if (source[i] == final[j]) {
			vec[i][j] = min(func(i - 1, j - 1), vec[i][j]);
		}
		else {
			vec[i][j] = min(vec[i][j], 1 + func(i - 1, j - 1));
		}
	}
	return vec[i][j];
}

int main()
{
	int n, m;
	cin >> n >> source >> m >> final;
	int length1 = source.length(), len2 = final.length();

	for (int i = 0; i < length1; i++) {
		vector<int> data;

		for (int j = 0; j < len2; j++) {
			data.push_back(-1);
		}
		vec.push_back(data);
	}

	cout << func(length1 - 1, len2 - 1) << endl;
}