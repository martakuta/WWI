#include <bits/stdc++.h>
using namespace std;

struct kr {
	int p, k, wag, nr;
};

kr T[1000*1000+5];

bool comparekr (kr a, kr b) {
	return a.wag < b.wag;
}

int rep[1000*1000+5];
queue <int> biore;

int fin (int v) {
	if (rep[v] == v)
		return v;
	else
		return rep[v] = fin(rep[v]);
}

void onion (int a, int b) {
	rep[fin(b)] = fin(a);
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin>> n >> m;
	for (int i=1; i<=m; i++) {
		int a, b, c;
		cin>> a >> b >> c;
		T[i].p = a;
		T[i].k = b;
		T[i].wag = c;
		T[i].nr = i;
	}
	for (int i=1; i<=n; i++)
		rep[i] = i;
	sort (T+1, T+m+1, comparekr);
	for (int i=1; i<=m; i++) {
		int pocz = T[i].p, kon = T[i].k, numer = T[i].nr;
		if (fin(pocz) != fin(kon)) {
			onion(pocz, kon);
			biore.push(numer);
		}
/*		for (int i=0; i<6; i++)
			cout<< rep[i] << " ";
		cout<< "\n";
*/	}
	while (!biore.empty()) {
		int numer = biore.front();
		cout<< numer << "\n";
		biore.pop();
	}
//	for (int i=0; i<6; i++)
//		cout<< T[i].p << " " << T[i].k << " " << T[i].wag << " " << T[i].nr << "\n";
	return 0;
}
