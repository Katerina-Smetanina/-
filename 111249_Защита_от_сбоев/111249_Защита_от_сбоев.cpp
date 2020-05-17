#include <iostream>
#include <string>
#include <fstream>


using namespace std;

ifstream fin;
ofstream fout;
int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	string word;
	int sum = 0;
	getline(fin, word);

	for (int i = 0; i < word.length() - 1; i++)
		if (word[i] == '1')
			sum++;

	if (word[word.length() - 1] == 'e'){
		if (sum % 2 == 0)
			word[word.length() - 1] = '0';
		else
			word[word.length() - 1] = '1';
	}
	else{
		if (sum % 2 == 1)
			word[word.length() - 1] = '0';
		else
			word[word.length() - 1] = '1';
	}
	fout << word;
}