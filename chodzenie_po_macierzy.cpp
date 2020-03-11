#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define f first
#define s second

map <pair <int, int>, int > m; // wspolrzedne pola i indeks pola
int rep[1000*1000+5];
int TA[4]={0, 0, 1, -1}, TB[4]={1, -1, 0, 0};

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
	int n, q, id=1;
	cin>> n >> q;
	for (int i=1; i<=q+3; i++)
		rep[i] = i;
	for (int i=0; i<q; i++) {
		char zap;
		cin >> zap;
		if (zap == 'B') {
			int a, b;
			cin>> a >> b;
			m[mp(a,b)] = id;
			for (int t=0; t<4; t++) {
				if (m[mp(a+TA[t],b+TB[t])] != 0) {
					onion (id, m[mp(a+TA[t],b+TB[t])]);
//					cout<< "onion" << id << "," <<  m[mp(a+TA[t],b+TB[t])] << "\n";
				}
			}
			id++;
		} else {
			int a1, a2, b1, b2;
			cin>> a1 >> a2 >> b1 >> b2;
			int id1 = m[mp(a1,a2)];
			int id2 = m[mp(b1,b2)];
			if (fin(id1) == fin(id2))
				cout<< "Tak\n";
			else
				cout<< "Niestety\n";
		}
//		for (int i=0; i<8; i++)
//			cout<< rep[i] << " ";
//		cout<< "\n";
	}
	return 0;
}
