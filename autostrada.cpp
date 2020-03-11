#include <bits/stdc++.h>
using namespace std;

#define LL long long

double tab[100*1000+5][2]; // w 0 trzymam s, w 1 trzymam v
int n;
double tc;

bool sprawdz (double x) {
	double wynik=0;
	for (int i=1; i<=n; i++) {
		double el = tab[i][0] / (tab[i][1] + x);
		wynik += el;
	}
//	cout<< "w: " <<x << " "<< wynik << "\n";
	if (wynik > tc)
		return 1; // zbyt dlugi wyszedl czas, czyli zbyt male przekroczenie v
	else
		return 0; // wieksze niz minimalne mozliwe przekroczenie v
}

double binsearch (double p, double k) {
	while (p+0.000001<k) {
//		cout<< "b: " << p << " " << k << "\n";
		double s = (p+k)/2;
		if (sprawdz(s) == 1)
			p = s;
		else
			k = s;
	}
	return k;
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>> n >> tc;
	for (int i=1; i<=n; i++)
		cin>> tab[i][0] >> tab[i][1];
	double wyn = binsearch (0,50*1000+1);
	cout<< setprecision(9) << fixed << wyn << "\n";
	return 0;
}
