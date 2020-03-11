#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

long long odl[1005];
const long long inf = 1e13;
int n, m;
long long s;
long long tab[105][105];
long long glowna[10005][3];

bool floyd (long long v) {
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++)
			tab[i][j] = inf;
	}
	for (int i=0; i<m; i++) {
		tab[glowna[i][0]][glowna[i][1]] =min( glowna[i][2]-v, tab[glowna[i][0]][glowna[i][1]]) ;
		
	}
	for (int k=1; k<=n; k++) { //KIJ :))
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if (tab[i][k] + tab[k][j] < tab[i][j] )
					tab[i][j] = tab[i][k] + tab[k][j];
			}
		}
	}
	for (int i=1; i<=n; i++) {
		if (tab[i][i] < 0) { //czyli jest cykl ujemny
/*			for (int x=0; x<=n; x++) {
				for (int y=0; y<=n; y++) 
					cout<< tab[x][y] << " ";
				cout<< "\n";
			}
			cout<< "\n";
			cout<< v << "\n";
*/			return 0;
		}
	}
	return 1;
}

int main () {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>> n >> m;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++)
			tab[i][j] = inf;
	}
	for (int i=0; i<m; i++) {
		long long a, b;
		long long c;
		cin>> a >> b >> c;
		glowna[i][0] = a;
		glowna[i][1] = b;
		glowna[i][2] = c*1000;
	}
	for (int k=0; k<n; k++) { //KIJ :))
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (tab[i][k] + tab[k][j] < tab[i][j] )
					tab[i][j] = tab[i][k] + tab[k][j];
			}
		}
	}

	long long p=-1*1e12, k=1e12;
	while (p+1<k) {
		s = (p+k)/2;
		if (floyd(s) == 1)
			p = s;
		else
			k = s;
	}
	double wynik = p;
	wynik /= 1000;
	cout<< setprecision(2) << fixed << wynik << "\n";
	return 0;
}
