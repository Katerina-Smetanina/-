#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main(){

	setlocale(LC_ALL, "Russian");
	string code;

	cout << "Enter cipher ";
	getline(cin, code);

	int k;
	const int size = 26;
	cout << "Enter number to 25";
	cin >> k;

	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < code.length(); i++) {
		int word = code[i]- 'A';
		if (word - k < 0)
			code[i] = alphabet[size - (k - word)];
		else 
			code[i] = alphabet[word - k];
	}
	cout << code;
}