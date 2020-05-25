// 1114. Оптимизация.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<bits>

using namespace std;
const int nmax = 1e5 + 9;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long lli;
typedef pair<lli, lli > pii;
lli m[nmax];
lli w2[nmax];
lli w[nmax];
lli p[nmax];
lli N;
lli M;
pii sl[nmax];
lli a[nmax];
lli b[nmax];
lli ans;
void mergesort(lli a[], lli lef, lli righ) {
	if (righ - lef + 1 <= 1)return;
	lli mid = (lef + righ) / 2;
	mergesort(a, lef, mid);
	mergesort(a, mid + 1, righ);
	for (int i = lef; i <= righ; i++) {
		b[i] = a[i];
	}
	lli i = lef, j = mid + 1, k = lef;
	while (i <= mid && j <= righ) {
		if (b[i] <= b[j]) {
			a[k] = b[i]; i++; k++;
		}
		else {
			ans += mid - i + 1;
			a[k] = b[j];
			j++;
			k++;
		}
	}
	while (i <= mid) {
		a[k] = b[i]; i++; k++;
	}
	while (j <= righ) {
		a[k] = b[j]; j++; k++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		cin >> m[i];
	}
	for (int i = 1; i <= M; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			lli x;
			cin >> x;
			w2[i] += m[x];
			p[x] = i;
		}
	}
	for (int i = 1; i <= N; i++) {
		w[i] = w2[p[i]];
		sl[i] = mp(m[i], -(w[i] - m[i]));
	}
	sort(sl + 1, sl + 1 + N);
	lli br = 0;
	for (int i = 1; i <= N; i++) {
		br++;
		a[br] = sl[i].se;
	}
	br = 0;
	mergesort(a, 1, N);
	cout << ans << "\n";
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
