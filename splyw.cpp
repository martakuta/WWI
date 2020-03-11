#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

vector <pair <long long, long long> > G[1000*1000+5];
bool odw[1000*1000+5];
long long n, m, a, b, wag;
long long bak[1000*1000+5];

void dijkstra () {
	priority_queue <pair <long long, long long>, vector <pair <long long, long long> >, greater <pair <long long, long long> > > q;
	long long najbak = bak[1];
	for (int i=0; i<G[1].size(); i++)
		q.push(mp(G[1][i].s, G[1][i].f));
	while (!q.empty()) {
		long long u = q.top().s;
		long long cost = q.top().f;
		q.pop();
		if (najbak >= cost && odw[u] == 0) {
			najbak = max (najbak, bak[u]);
			odw[u] = 1;
			for (int i=0; i<G[u].size(); i++) {
				if (odw[G[u][i].f] == 0)
					q.push(mp(G[u][i].s, G[u][i].f));
			}
		}
	}
}

int main () {
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m;
	cin>> n >> m;
	for (int i=1; i<=n; i++)
		cin>> bak[i];
	for (int i=0; i<m; i++) {
		int a, b, d;
		cin>> a >> b >> d;
		G[a].push_back(mp(b, d));
		G[b].push_back(mp(a, d));
	}
/*	for (int i=0; i<=n; i++)  {
		cout<< i << ": ";
		for (int j=0; j<G[i].size(); j++)
			cout<< G[i][j].f << " " << G[i][j].s << "   ";
		cout<< "\n";
	}
	cout<< "\n";
*/	dijkstra();
	if (odw[n] == 1)
		cout<< "TAK\n";
	else
		cout<< "NIE\n";
/*	for (int i=0; i<7; i++)
		cout<< odw[i] << " ";
	cout<< "\n";
*/	return 0;
}
