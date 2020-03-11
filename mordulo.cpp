#include <bits/stdc++.h>
using namespace std;

#define LL unsigned long long

const int M = 1024*1024;
//const int M = 8;
LL w[300*1000+5]; //ilosci latarenek w wagonach
LL p[2*M]; // pojemnosci
const LL inf  = 18446744073709551615;
int n;

LL szuk (LL l) {
	int x = M;
	while ( x > 1 ) {
		if (x >= M) {
			if (p[x] <= l)
				l %= p[x];
			x /= 2;
		} else if (p[2*x] <= l)
			x = 2*x;
		else if (p[2*x+1] <= l)
			x = 2*x +1;
		else
			x /= 2;
	}
	return l;
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>> n >> q;
	for (int i=M; i<n+M; i++)
		cin>> p[i];
	for (int i=1; i<=q; i++)
		cin>> w[i];
	for (int i=M+n; i<2*M; i++)
		p[i] = inf;
	for (int i=M-1; i>0; i--)
		p[i] = min(p[2*i], p[2*i+1]);
	for (int i=1; i<=q; i++) {
		LL l = w[i]; //ilosc latarenek w wagonie
		if (p[M] < l)
			l %= p[M];
		LL zostaje = szuk(l);
		w[i] = zostaje;
	}
	for (int i=1; i<=q; i++)
		cout<< w[i] << "\n";
	return 0;
}
