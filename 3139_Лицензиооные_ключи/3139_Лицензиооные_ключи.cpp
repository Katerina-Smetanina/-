#include <iostream>
#include <vector>
using namespace std;

int count(vector <char>& key, vector <char>& alphabet, int P);

bool check(vector <char>& key, vector <char>& alphabet, vector <int>& sum, int P) {
	int c = count(key, alphabet, P), b = 0;
	for (int i = 0; i < sum.size(); ++i)
	{
		if (sum[i] == c)
		{
			return false;
			b = 1;
			break;
		}
		b = 2;
	}
	if (b == 2)
		return true;
}

int count(vector <char>& key, vector <char>& alphabet, int P) {
	int sum = 0, y = 0;
	for (int i = 0; i < 25; ++i)
		for (int k = 0; k < 36; ++k)
			if (key[i] == alphabet[k])
				sum = sum + k;
	sum = sum % P;
	return sum;
}

void Gen(vector <char>& key, vector <char>& alphabet, int P, vector <int>& sum) {
	for (int i = 0; i < 25; ++i)
		for (int k = 0; k < 36; ++k) {
			key.erase(key.begin() + i);
			if (i == 24) key.push_back(alphabet[k]);
			else key.insert(key.begin() + i, alphabet[k]);
			if (check(key, alphabet, sum, P) == true)
				break;
		}
}

void plustire(vector<char>& key) {
	key.insert(key.begin() + 5, '-');
	key.insert(key.begin() + 11, '-');
	key.insert(key.begin() + 17, '-');
	key.insert(key.begin() + 23, '-');
}

void minustire(vector<char>& key) {
	key.erase(key.begin() + 5);
	key.erase(key.begin() + 10);
	key.erase(key.begin() + 15);
	key.erase(key.begin() + 20);
}

bool impossible(vector <int>& sum, int P) {
	int p = 0, b = 0;
	while (p != P) {
		for (int k = 0; k < sum.size(); ++k)
			if (p == sum[k]) {
				++p;
				b = 1;
			}
		if ((b == 0) && (p < 901)) {
			b = 2;
			break;
		}
		b = 0;
	}
	if (b == 2) return true;
	else return false;
}

int main()
{
	int x = 29, N, P;
	cin >> N >> P;
	vector <char> alphabet = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	vector <int> sum(0);
	while (N > 0) {
		vector <char> key(x);
		for (int i = 0; i < 29; ++i)
			cin >> key[i];
		minustire(key);
		sum.push_back(count(key, alphabet, P));
		key.clear();
		--N;
	}
	vector <char> key = { '0','0','0','0','0','0','0','0','0','0', '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' };
	if (impossible(sum, P)) {
		Gen(key, alphabet, P, sum);
		if (check(key, alphabet, sum, P)) {
			plustire(key);
			for (int i = 0; i < 29; ++i)
				cout << key[i];
		}
		else cout << "Impossible";
	}
	else cout << "Impossible";
}
