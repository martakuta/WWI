#include <bits/stdc++.h>
using namespace std;

struct dom {
	int x, y;
};

dom domy[5005];
int odl[5005];
bool odw[5005];
const int inf = 1e9;

long long dl (int a, int b) {
	long long iksy = ((long long)(domy[a].x) - (long long)(domy[b].x))*((long long)(domy[a].x) - (long long)(domy[b].x));
	long long igreki = ((long long)(domy[a].y) - (long long)(domy[b].y))*((long long)(domy[a].y) - (long long)(domy[b].y));
	long long d = iksy + igreki;
	return ceil(sqrt(d));
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>> n;
	for (int i=1; i<=n; i++) {
		cin>> domy[i].x >> domy[i].y;
		odl[i] = inf;
	}
	odl[1] = 0;
	int zrobione = 0; 
	int obecny = 1;
	while (zrobione < n) {
		odw[obecny] = 1;
		for (int i=2; i<=n; i++) {
			int dlugosc = dl(i, obecny);
			if (dlugosc < odl[i] && odw[i] == 0)
				odl[i] = dlugosc;
		}
		int najmwartosc = inf, najm;
		for (int i=2; i<=n; i++) {
			if (odl[i] < najmwartosc && odw[i] == 0) {
				najmwartosc = odl[i];
				najm = i;
			}
		}
		obecny = najm;
		zrobione ++;
	}
//	for (int i=1; i<=n; i++)
//		cout<< odl[i] << " ";
//	cout<< "\n";
	int najw = 0;
	for (int i=1; i<=n; i++) {
		if (odl[i] > najw)
			najw = odl[i];
	}
	long long wynik = (n-1) * najw;
	cout<< wynik << "\n";
	return 0;
}
