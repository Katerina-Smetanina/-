#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double Eps = 1e-15;


struct Db
{
	double d;
	int id;
	Db()
	{
		d = 0.;
		id = -1;
	}
};

bool operator < (Db A, Db B)
{
	return (A.d < B.d - Eps) || (fabs(A.d - B.d) < Eps && A.id < B.id);
}

vector <Db> S, V;
int N, M;
double Cur = 0;

double T(double t)
{
	double Sum1 = 0, Sum2 = 0, Max = 0;
	int Count = 0;
	vector <Db> Ss = S;
	for (int i = 0; i < N; ++i)
	{
		Ss[i].d = S[i].d - t * V[i].d;
	}
	sort(Ss.rbegin(), Ss.rend());
	for (int i = 0; i < S.size(); ++i)
	{
		Sum1 += Ss[i].d;
		Sum2 += V[i].d;
		Max = max(Max, Sum1 / Sum2);
	}
	return t + Max;
}

bool New(double t)
{
	int* Old = new int[N];
	for (int i = 0; i < N; ++i)
	{
		Old[i] = S[i].id;
	}
	for (int i = 0; i < N; ++i)
	{
		S[i].d -= V[i].d * t;
	}
	sort(S.rbegin(), S.rend());
	for (int i = 0; i < min(N, M); ++i)
	{
		if (S[i].id != Old[i] && S[i].d > Eps)
		{
			cout << Cur << " " << S[i].id + 1 << " " << V[i].id + 1 << endl;
		}
	}
	return S[0].d > Eps;
}


int main()
{
	cin >> N;
	S.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i].d;
		S[i].id = i;
	}
	cin >> M;
	V.resize(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> V[i].d;
		V[i].id = i;
	}
	sort(S.rbegin(), S.rend());
	sort(V.rbegin(), V.rend());
	V.resize(N);
	cout.precision(20);
	cout << T(0) << endl;
	for (int i = 0; i < min(N, M); ++i)
	{
		cout << 0 << " " << S[i].id + 1 << " " << V[i].id + 1 << endl;
	}
	bool flag = 1;
	while (flag)
	{
		double t = T(0);
		double L = 0, R = t;
		for (int i = 0; i < 200; ++i)
		{
			double M = (L + R) / 2;
			if (T(M) > t + Eps)
			{
				R = M;
			}
			else
			{
				L = M;
			}
		}
		Cur += L;
		flag = New(L);
	}

}