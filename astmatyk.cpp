#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

vector <pair <int, int> > G[100*1000+5];
int odl[100*1000+5];
bool odw[100*1000+5];
int wys[100*1000+5];
int n;
const int inf = 1e9;

void dijkstra (int v) {
	for (int i=1; i<=n; i++) {
		odl[i] = inf;
		odw[i] = 0;
	}
	odl[v] = 0;
	priority_queue <pair <int, int> > q;
	q.push(mp(0, v));
	while (!q.empty()) {
		int u=q.top().s;
		int cost = -q.top().f;
		q.pop();
		if (odw[u] == 1)
			continue;
		odw[u] = 1;
		for (int i=0; i<G[u].size(); i++) {
			int w = G[u][i].s;
			if (max(cost, G[u][i].f) < odl[w]) {
				odl[w] = max(cost, G[u][i].f);
				q.push(mp (-odl[w], w));
			}
		}
	}
}

main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int  m;
	cin>> n >> m;
	for (int i=1; i<=n; i++) {
		cin>> wys[i];
	}
	for (int i=0; i<m; i++) {
		int a, b;
		cin>> a >> b;
		int w = max (wys[a], wys[b]);
		G[a].push_back (mp (w, b));
		G[b].push_back (mp (w, a));
	}
/*	for (int i=0; i<11; i++) {
		cout<< i <<": ";
		for (int j=0; j<G[i].size(); j++)
			cout<< G[i][j].f << " " << G[i][j].s << "   ";
		cout<< "\n";
	}
*/	
	dijkstra(1);
//	for (int i=0; i<11; i++)
//		cout<< odl[i] << " ";
	cout<< odl[n] << "\n";

	return 0;
}
