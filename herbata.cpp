#include <bits/stdc++.h>
using namespace std;

const int M = 1025*256;
long long d[2*M];
long long d2[2*M];

long long sum (int p, int k, long long *d) {
	p = p+M-1;
	k = k+M-1;
	long long wynik = d[p];
	if (p != k)
		wynik += d[k];
	while (p/2 != k/2) {
		if (p%2 == 0)
			wynik += d[p+1];
		if (k%2 == 1)
			wynik += d[k-1];
		p /= 2;
		k /= 2;
	}
	return wynik;
}

void dodaj (int gdzie, int ile, long long *d) {
	gdzie = gdzie+M-1;
	d[gdzie] = ile;
	while (gdzie>1) {
		gdzie /= 2;
		d[gdzie] = d[gdzie*2] + d[gdzie*2+1];
	}
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin>> n >> m;
	for (int i=M; i<M+n; i++) { //wczytuje podstawe drzewa
		cin>> d[i];
		d2[i] = d[i] * d[i];
	}
	for (int i=M-1; i>0; i--) {
		d[i] = d[2*i] + d[2*i+1];
		d2[i] = d2[2*i] + d2[2*i+1];
	}
	bool dzialanie;
	for (int i=0; i<m; i++) {
		cin>> dzialanie;
		if (dzialanie == 1) { // Bajtalina chce wiedziec ile roznych herbat moze zaparzyc
			int p, k;
			cin>> p >> k;
			long long sumaliczb = sum(p, k, d);
			long long sumakwadratow = sum(p, k, d2);
			long long wynik = sumaliczb*sumaliczb - sumakwadratow;
			wynik /= 2;
			cout<< wynik << "\n";
		} else { // jest jakas dostawa
			int pudelko, ile;
			cin>> pudelko >> ile;
			dodaj (pudelko, ile, d);
			dodaj (pudelko, ile*ile, d2);
		}
	}
	return 0;
}
