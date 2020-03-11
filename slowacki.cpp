#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define f first
#define s second

const int MXN = 5*1e5 +5;
const int MXLG = 20;
const long long inf = 1e18;
int dep[MXN];
int jump[MXN][MXLG];
vector <pair<int, int> > G[MXN];
long long odl[MXN];
bool odw[MXN];
int n;

void dfs (int v, int pop) {
	jump[v][0] = pop;
	for(int i=1; i<MXLG; i++)
		jump[v][i] = jump[ jump[v][i-1] ][i-1];
	dep[v] = dep[pop]+1;
	for (int i=0; i<G[v].size(); i++) {
		if (G[v][i].s == pop)
			continue;
		dfs(G[v][i].s, v);
	}
}

int lca (int a, int b) {
	if (dep[a] < dep[b])
		swap(a, b);
	for (int i=MXLG-1; i>=0; i--) {
		if (dep[jump[a][i]] >= dep[b])
			a = jump[a][i];
	}
//	cout<< dep[a] << " " << dep[b] <<"\n";
	assert (dep[a] == dep[b]);
	if (a==b)
		return a;
	for (int i=MXLG-1; i>=0; i--) {
		if (jump[a][i] != jump[b][i]) {
			a = jump[a][i];
			b = jump[b][i];
		}
	}
//	cout<< jump[a][0] << " " << jump[b][0] << "\n";
	assert (jump[a][0] == jump[b][0]);
	return jump[a][0];
}

void dijkstra (int v) {
	for (int i=0; i<=n; i++) {
		odl[i] = inf;
		odw[i] = 0;
	}
	odl[v] = 0;
	priority_queue <pair<long long, int> > q;
	q.push (mp(0, v));
	while (!q.empty()) {		
		int u = q.top().s;
		long long cost = -q.top().f;
		q.pop();
		if (odw[u] == 1)
			continue;
		odw[u] = 0;
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
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, c;
	cin>> n;
	for (int i=1; i<n; i++) {
		cin >> a >> b >> c;
		G[a].push_back(mp(c, b));
		G[b].push_back(mp(c, a));
	}
	dep[0] = -1;
	dfs (1, 0);
/*	for (int i=1; i<=n; i++)
		cout<< dep[i] << " ";
	cout<< "\n";
	for (int i=1; i<=n; i++) {
		for (int j=0; j<MXLG; j++)
			cout<< jump[i][j] << " ";
		cout<< "\n";
	}
*/
	dijkstra(1);
	bool zakoncz = 0;
	while (!zakoncz) {
		cin>> a;
		if (a == -1)
			return 0;
		cin>> b;
		int ojciec = lca(a, b);
//		cout<< ojciec << "\n";
		long long wynik = odl[a] + odl[b] - odl[ojciec]*2;
		cout<< wynik << "\n";
	}
	return 0;
}
