#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;


int main()
{
	string word1, word2;
	int sum = 0;
	getline(cin, word1);
	getline(cin, word2);


	for (int i = 0; i < word1.length(); i++)
		if (word1[i] != word2[i])
			sum++;

	cout << sum;
}