#include <bits/stdc++.h>
using namespace std;

vector <int> G[500*1000+5];
int czasy[500*1000+5][2];
int t=0;

void dfs (int v) {
	t++;
	czasy[v][0] = t;
	for (int i=0; i<G[v].size(); i++) {
		if (czasy[G[v][i]][0] == 0)
			dfs(G[v][i]);
	}
	t++;
	czasy[v][1] = t;
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a, b;
	cin>> n;
	for (int i=1; i<n; i++) {
		cin >> a;
		G[a].push_back(i);
		G[i].push_back(a);
	}
	dfs (0);
//	for (int i=0; i<n; i++)
//		cout<< czasy[i][0] << " " << czasy[i][1] << "\n";
	bool zakoncz = 0;
	while (!zakoncz) {
		cin>> a;
		if (a == -1)
			return 0;
		cin>> b;
		if (czasy[a][0] < czasy[b][0] && czasy[a][1] > czasy[b][1])
			cout<< "TAK\n";
		else
			cout<< "NIE\n";
	}
	return 0;
}
