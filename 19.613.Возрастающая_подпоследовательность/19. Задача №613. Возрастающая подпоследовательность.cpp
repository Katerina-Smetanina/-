// 19. Задача №613. Возрастающая подпоследовательность.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#define ll long long

#include <algorithm>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

template<typename TT_cont>
void Print(TT_cont const& cont)
{
	copy(cont.begin(), cont.end(), ostream_iterator<typename TT_cont::value_type>(cout, " "));
	cout << endl;
}

void SetLongestIncreasingSubsequence(deque<int> const& numbers, deque<int>& subsequence)
{
	int         numbers_size = numbers.size();
	deque<int>   seq_lens(numbers_size, 1);
	deque<int>   prev_indexes(numbers_size);
	int         seq_len_max = 1;
	int         last_ind = 0;

	for (int i = 1; i < numbers_size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (numbers[j] < numbers[i] && seq_lens[j] + 1 > seq_lens[i])
			{
				seq_lens[i] = seq_lens[j] + 1;
				prev_indexes[i] = j;

				if (seq_lens[i] > seq_len_max)
				{
					seq_len_max = seq_lens[i];
					last_ind = i;
				}
			}
		}
	}

	while (int(subsequence.size()) < seq_len_max)
	{
		subsequence.push_front(numbers[last_ind]);
		last_ind = prev_indexes[last_ind];
	}
}

int main()
{
	int n, temp;
	deque<int> numbers;
	deque<int> subsequence;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		numbers.push_back(temp);
	}

	SetLongestIncreasingSubsequence(numbers, subsequence);
	cout << subsequence.size() << '\n';
	Print(subsequence);

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
