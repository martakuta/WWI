#include <bits/stdc++.h>
using namespace std;

int karty[500*1000+5];
int T[500*1000+5];
int odp[500*1000+5][2];

int binsearch (int p, int k, int x) {
	while (p+1<k) {
		int s = (p+k)/2;
		if (T[s] < x)
			p = s;
		else
			k = s;
	}
	return p;
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, zmien;
	cin>> n;
	for (int i=1; i<=n; i++)
		cin>> karty[i];
	
	int pierwszywolny = 1;
	for (int i=1; i<=n; i++) {
		zmien = binsearch (0, pierwszywolny, karty[i]);
		if (zmien == pierwszywolny - 1) {
			T[pierwszywolny] = karty[i];
			pierwszywolny ++;
			odp[i][0] = 1;
		} else {
			T[zmien+1] = karty[i];
			odp[i][0] = 2;
			odp[i][1] = zmien+1;
		}
	}
	int wynik = 0;
	for (int i=1; i<=n; i++) {
		if (odp[i][0] == 1)
			wynik ++;
	}
	cout<< wynik << "\n";
	for (int i=1; i<=n; i++) {
		if (odp[i][0] == 1)
			cout<< "1\n";
		else
			cout<< "2 " << odp[i][1] << "\n";
	}
	
	return 0;
}
