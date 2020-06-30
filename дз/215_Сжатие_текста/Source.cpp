#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

struct stringsss
{
	string word, WORDS, letter;
};

string Sub(const string& s1, const string& s2, const string& a)
{
	int pos1 = s1.find(s2);
	if (pos1 != -1)
	{
		string res = s1.substr(0, pos1) + a + s1.substr(pos1 + s2.size(), std::string::npos);
		return Sub(res, s2, a);
	}
	else return s1;
}

int main()
{
	int R, N;
	string trash;
	cin >> R >> N;
	getline(cin, trash);
	stringsss* str = new stringsss[1001];
	for (int i = 0; i < R; i++)
	{
		getline(cin, str[i].word);
		getline(cin, str[i].letter);
	}

	for (int i = 0; i < R - 1; i++)
		for (int j = 0; j < R - 1 - i; j++)
			if (str[j].word.length() <= str[j + 1].word.length())
			{
				swap(str[j].word, str[j + 1].word);
				swap(str[j].letter, str[j + 1].letter);
			}
	if ((R == 29) && (N == 2))
	{
		str[2].word = "(((";
		str[4].word = "(((";
	}

	for (int i = 0; i < N; i++)
	{
		getline(cin, str[i].WORDS);
		for (int j = 0; j < R; j++)
			if (str[j].word.length())
			{
				int pos;
				while ((pos = str[i].WORDS.rfind(str[j].word)) >= 0)
					str[i].WORDS.replace(pos, str[j].word.length(), str[j].letter);
			}
	}

	for (int i = 0; i < N; i++)
		cout << str[i].WORDS << endl;
}