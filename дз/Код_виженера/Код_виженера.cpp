#include <iostream>
#include <string>
using namespace std;

//funkcia podscheta dlinni massiva
unsigned int Lenght(const char s[])
{
	int L = 0;
	while (s[L++]);
	return (L - 1);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char abc[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";
	char key[] = "ключ";
	char word[] = "ехал грека через реку";

	//dly hraneniya kodov bykv s massiva key
	unsigned int key_num[10] = { 0 };

	//dly hraneniya kodov bykv s massiva word
	int word_num[100] = { 0 };

	//dly hraneniya kodov bykv polychennogo zashifrovannogo slova
	int word_num_new[100] = { 0 };
	int k = 0;//index kolichestva bykv v key
	int w = 0;//index kolichestva bykv v word

	system("cls");

	//perevodim slovo i klych v chislovie ekvivalenti
	while (k <= Lenght(key))//poka ne konchitsya massiv key
	{

		for (int i = 0; i < 34; i++)
		{
			//zanosim v key_num chislovoy kod bykvi
			if (key[k] == abc[i])key_num[k] = i;
		}

		k++;
	}
	while (w <= Lenght(word))//poka ne konchitsya massiv word
	{
		for (int i = 0; i < 33; i++)
		{
			//zanosim v word_num chislovoy kod bykvi
			if (word[w] == abc[i])word_num[w] = i;
		}

		w++;
	}

	w = 0; k = 0;

	while (w < Lenght(word))//poka ne konchitsya massiv word
	{
		//dobavlyaem v word_num_new symmy chisel ot word i key
		word_num_new[w] = key_num[k] + word_num[w];

		//realizyem ciklicnost dlya shifrovaniya
		if (word_num_new[w] > 34)word_num_new[w] -= 34;

		w++; k++;
		if (k >= Lenght(key))k = 0;

	}
	//vivod polychennih dannih s perevodom chisel snova v bykvi
	cout << "Shifrovanie metodom Viginera" << endl << endl;
	cout << "исходник : " << word << endl;
	cout << "ключ : " << key << endl;
	cout << "результат шифрования : ";
	w = 0;
	while (w < Lenght(word))//poka ne konchitsya massiv word
	{
		//vivod po indeksy massiva abc
		cout << abc[word_num_new[w]];
		w++;
	}
	//——————————————————————
	 //deshifryem slovo
	w = 0; k = 0;
	cout << endl;
	int t, m;
	while (w < Lenght(word))//poka ne konchitsya massiv word
	{
		t = word_num_new[w];
		m = key_num[k];
		t -= m;

		//vichitaem kody klycha iz kodov shifrovannogo soobsheniya po modyly 26 (kolichestvo bykv v alfavite)

		if (t < 0)word_num_new[w] += 26 - key_num[k];
		else word_num_new[w] -= key_num[k];

		w++; k++;
		if (k >= Lenght(key))k = 0;

	}
	cout << endl << "дешифрование: ";

	//vivod deshifrovannogo soobsheniya
	w = 0;
	while (w < Lenght(word))//poka ne konchitsya massiv word
	{
		//vivod po indeksy massiva abc
		cout << abc[word_num_new[w]];
		w++;
	}

	cin.get();
	return 0;
}