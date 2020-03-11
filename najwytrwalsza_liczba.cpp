#include <bits/stdc++.h>
using namespace std;

long long tab[500*1000+5];
long long n;

bool sprawdz (long long x) {
//	cout<< "s: " << x << "------------1-1-2-100-101-102----------------\n";
	long long p=0, k=n-1;
	long long wynik=0;
	while (p<n) {
//		cout<< "pk: " << p << " " << k << "\n";
		while (tab[p] + tab[k] < x)
			p++;
		while (tab[p] + tab[k] >= x && k>0)
			k--;
		if (tab[p] + tab[k] < x)
			k++;
//		cout<< "pk: " << p << " " << k << "\n";
		wynik = wynik + (n - k);
//		cout<< "w: " << wynik << "\n";
		p++;
	}
	if (wynik >= (n*n+1)/2)
		return 1;
	else
		return 0;
}

long long binsearch_wynik (long long p, long long k) {
	p--;
	k++;
	while (p+1<k) {
	//	cout<< "b: " << p << " " << k << "\n";
		long long s = (p+k)/2;
		if (sprawdz (s) == 1)
			p = s;
		else
			k = s;
	}
	return p;
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
	long long wynik;
	cin>> n;
	for (int i=0; i<n; i++)
		cin>> tab[i];
	tab[n] = 2e9;
	sort (tab, tab+n);
	cout<<	binsearch_wynik(2*tab[0], 2*tab[n-1]) << "\n";
	return 0;
}
