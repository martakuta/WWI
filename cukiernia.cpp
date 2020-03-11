#include <bits/stdc++.h>
using namespace std;
int plecak[1000+5];
bool jest[1000+5];
int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; // n to ilosc rodzajow ciastek, k to kwota ktora ma Jas
	cin>> n >> k;
	jest[0] = 1;
	for (int i=0; i<n; i++) {
		int c, s; // c to cena, s to smacznosc
		cin>> c >> s;
		int x=1000;
		while (x>=0) {
			if (jest[x] == 1 && x+c <= 1000) {
				if (plecak[x]+s > plecak[x+c])
					plecak[x+c] = plecak[x] + s;
					jest[x+c] = 1;
			}
			x--;	
		}
	}
//	for (int i=0; i<10; i++)
//		cout<< plecak[i] << " " << jest[i] << "\n";
	int s=k, maxi=0;
	for (int i=s; i>0; i--) {
		if (plecak[i] > maxi)
			maxi = plecak[i];
	}
	cout<< maxi << "\n";
	return 0;
}
