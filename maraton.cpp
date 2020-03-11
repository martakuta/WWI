#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

vector <pair <int, int> > G[200*1000+5];
long long odl[200*1000+5];
bool odw[200*1000+5];
int n;
const long long inf = 1e18;

void dijkstra (int v) {
	for (int i=0; i<=2*n; i++) {
		odl[i] = inf;
		odw[i] = 0;
	}
	odl[v] = 0;
	priority_queue <pair <long long, int> > q;
	q.push( mp(0, v));
	while (!q.empty()) {
		int u = q.top().s;
		long long cost = -q.top().f;
		q.pop();
		if (odw[u] == 1)
			continue;
		odw[u] = 1;
		for (int i=0; i<G[u].size(); i++) {
			int w = G[u][i].s;
			if (G[u][i].f + cost < odl[w]) {
				odl[w] = G[u][i].f + cost;
				q.push(mp(-odl[w], w));
			}
		}
	}
}

int main () {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m;
	cin>> n >> m;
	for (int i=0; i<m; i++) {
		int a, b, c;
		cin>> a >> b >> c;
		G[a].push_back(mp(c, b+n));
		G[b].push_back(mp(c, a+n));
		G[a+n].push_back(mp(2*c, b));
		G[b+n].push_back(mp(2*c, a));
	}
/*	for (int i=0; i<11; i++) {
		cout<< i << ": ";
		for (int j=0; j<G[i].size(); j++)
			cout<< G[i][j].f << " " << G[i][j].s << "    ";
		cout<< "\n";
	}
*/	dijkstra(1);
	long long wynik = min(odl[n], odl[2*n]);
	cout<< wynik << "\n";
	return 0;
}
