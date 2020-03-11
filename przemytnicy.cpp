#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define f first
#define s second

int n;
vector <pair <int, int> > G[10*1000+5];
int odl[10*1000+5];
bool odw[10*1000+5];
const int inf = 1e9;

void dijkstra (int v) {
	for (int i=1; i<=2*n; i++) {
		odl[i] = inf;
		odw[i] = 0;
	}
	odl[v] = 0;
	priority_queue <pair <int,int> > q;
	q.push(mp(0, v));
	while (!q.empty()) {
		int cost = -q.top().f;
		int u = q.top().s;
		q.pop();
		if (odw[u] == 1)
			continue;
		odw[u] = 1;
		for (int i=0; i<G[u].size(); i++) {
			int x = G[u][i].s;
			if (odl[x] > G[u][i].f + cost) {
				odl[x] = G[u][i].f + cost;
				q.push(mp(-odl[x], x));
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, a, b, c, cena;
	cin>> n;
	for (int i=1; i<=n; i++) {
		cin>> cena;
		G[i].push_back(mp(cena/2, i+n));
	}
	cin>> m;
	for (int i=0; i<m; i++) {
		cin>> a >> b >> c;
		G[a].push_back(mp(c, b));
		G[a+n].push_back(mp(c, b+n));
	}
	dijkstra(1);
	cout<< odl[n+1] << "\n";
	return 0;
}
