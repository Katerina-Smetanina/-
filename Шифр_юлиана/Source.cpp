#include<iostream>
#include<string>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string ul;
	//cout << "Введите шифровку ";
	getline(cin, ul);

	int k;
	const int size = 26;
	//cout << "Введите число ";
	cin >> k;
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < ul.length(); i++) {
		int find = ul[i] - 'A';
		if (find - k < 0) ul.at(i) = alphabet.at(size - (k - find));
		else ul.at(i) = alphabet.at(find - k);
	}
	cout << ul;
}