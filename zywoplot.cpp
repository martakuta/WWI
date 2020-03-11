#include <bits/stdc++.h>
using namespace std;
const int M = 1024*1024;
//const int M=16;
int d[2*M];
int drzewa[500*1000+5];
void dodaj (int x, int w) {
	x += M;
	d[x] = w;
	while (x>1) {
		x /= 2;
		d[x] = d[2*x] + d[2*x+1];
	}
}
int sum (int p, int k) {
	p += M;
	k += M;
	int wynik = d[p];
	if (p != k)
		wynik += d[k];
	while (p/2 != k/2) {
		if (p%2 == 0)
			wynik += d[p+1];
		if (k%2 == 1)
			wynik += d[k-1];
		k /=2;
		p /=2;
	}
	return wynik;
}
int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin>> n >> q;
	for (int i=0; i<n; i++) {
		int h;
		cin>> h;
		d[h+M] ++;
		drzewa[i] = h;

	}
	for (int i=M-1; i>0; i--)
		d[i] = d[2*i] + d[2*i+1];
	for (int z=0; z<q; z++) {
		char akcja, a2, a3;
		cin>> akcja >> a2 >> a3;
		if (akcja == 'm') {
			int i, h;
			cin>> i >> h;
			int st = drzewa[i-1];
			int bylo = d[st+M];
			dodaj (st, bylo-1);
			int bylo2 = d[h+M]; 
			dodaj (h, bylo2+1);
			drzewa[i-1] = h;
//			cout<< st << " " << bylo << " " << h << " " << bylo2 << "\n";
			
		} else {
			int h;
			cin>> h;
			int wynik = sum(h, M-1);
			cout<< wynik << "\n";
		}
/*		for (int i=0; i<32; i++)
			cout<< d[i] << " ";
		cout<< "\n";
*/	}
	return 0;
}
