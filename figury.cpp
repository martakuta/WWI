#include <bits/stdc++.h>
using namespace std;

bool tab[2005][2005];
int rep[2005*2005];
int obwody[2005*2005];
int t1[4] = {0,-1,0,1};
int t2[4] = {-1,0,1,0};

int fin (int v) {
	if (rep[v] == v)
		return v;
	else
		return rep[v] = fin(rep[v]);
}

void onion (int a, int b) {
//	cout<< "union" << a << "," << b << " " << obwody[a] << " "  << obwody[b] << " ";
	if (fin(a) == fin(b))
		return;
	obwody[fin(a)] += obwody[fin(b)];
	rep[fin(b)] = fin(a);
//	cout<< obwody[a] << "\n";
//	cout<< "union" << a << "," << b << " " << obwody[b] << "\n";
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	
	cin>> n >> m;
	//scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			char znak;
			//scanf(" %c", &znak);
			cin>> znak;
			if (znak == 'X')
				tab[i][j] = 1;
			rep[(i-1)*m+j] = (i-1)*m + j;
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (tab[i][j] == 1) {
				for (int l=0; l<4; l++) {
					if (tab[i+t1[l]][j+t2[l]] == 0) {
						obwody [(i-1)*m+j] ++;
					}
				}
			}
		}
	}
/*	for (int i=1; i<=n*m; i++)
		cout<< obwody[i] << " ";
	cout<< "\n";
*/
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (tab[i][j] == 1) {
				for (int l=0; l<4; l++) {
					if (tab[i+t1[l]][j+t2[l]] == 1) {
						onion ( (i-1)*m+j, (i+t1[l]-1)*m + j+t2[l]);
					}
				}
			}
		}
	}
	int w, k;
	cin>> w >> k;
	int pole = (w-1)*m+k;
	int wynik = obwody[fin(pole)];
	cout<< wynik << "\n";
/*	for (int i=1; i<=n*m; i++)
		cout<< obwody[i] << " ";
	cout<< "\n";*/
/*	for (int i=1; i<=n*m; i++) {
		rep[i] = fin(i);
	}
	int w, k, wynik = 0;
	//scanf("%d%d", &w, &k);
	cin>> w >> k;
	int skladowa = rep[(w-1)*m+k];
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (rep[(i-1)*m+j] == skladowa) { //czyli nalezy do ulubionej figury
				int sasiedzi = 0;
				for (int l=0; l<4; l++) {
					if (tab[i+t1[l]][j+t2[l]] == 1)
						sasiedzi ++;
				}
				int ob_tu = 4 - sasiedzi;
				wynik += ob_tu;
			}
		}
	}
	//printf("%d\n", wynik);*/
	//cout<< wynik << "\n";
	return 0;
}
