#include <bits/stdc++.h>
using namespace std;

const int N = 1000*1000+5;
int T[2*N];
const int podst = 1e9 + 7;
const int mod = 1e9 + 37;

long long hasz (int p, int k) {
	long long wynik = T[p];
	for (int i=p+1; i<=k; i++) {
		wynik *= podst;
		wynik %= mod;
		wynik += T[i];
		wynik %= mod;
	}
	return wynik;
}

long long potega (int a, int b) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	if (b%2 == 0)
		return (potega ( (a*a)%mod, b/2))%mod;
	if (b%2 == 1)
		return (a * potega ( (a*a)%mod, b/2))%mod;
}

int main () {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>> n;
	for (int nr=0; nr<n; nr++) {
		string a, b; //czy slowo a zawiera sie w slowie b
		cin>> a >> b;
		int dl_a = a.size();
		int dl_b = b.size();
		for (int i=0; i<dl_a; i++)
			T[i] = (int)(a[i]);
		for (int i=dl_a; i<dl_a+dl_b; i++)
			T[i] = (int)(b[dl_a + i]);
		int x = 0, apocz = 0, bpocz = dl_a;
		while (x < dl_a) {
			while (x<dl_a && T[x] != (int)('*') )
				x++;
			int ahasz = hasz (apocz, x-1);
			int dl_hasz = x - apocz;
			int bhasz = hasz (bpocz, bpocz+dl_hasz-1);
			if (ahasz == bhasz) {
				bpocz += dl_hasz;
				apocz += dl_hasz +1;
				continue;
			}
			for (int i=bpocz+1; i<dl_a+dl_b; i++) {
				long long nowy = (long long)(bhasz) - (long long)(T[i])*potega(podst, dl_hasz) + T[i+dl_hasz];
				nowy %= mod;
				nowy += mod;
				nowy %= mod;
				bhasz = nowy;
				if (ahasz == bhasz) {
					bpocz += i + dl_hasz;
					apocz += dl_hasz + 1;
				}
			}
			if (apocz = 
		}
		
	}
	return 0;
}
