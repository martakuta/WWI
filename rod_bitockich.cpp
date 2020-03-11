#include <bits/stdc++.h>
using namespace std;

const int MXN = 5*1e5 +5;
const int MXLG = 20;
const long long inf = 1e18;
int dep[MXN];
int jump[MXN][MXLG];
vector <int> G[MXN];
int n;
int maxi[MXN];
int mini[MXN];
int ojcowie[MXN];

void dfs (int v, int pop) {
	jump[v][0] = pop;
	for(int i=1; i<MXLG; i++) {
		jump[v][i] = jump[ jump[v][i-1] ][i-1];
		maxi[v] = max(maxi[v], maxi[jump[v][i-1]]);
		mini[v] = min(mini[v], mini[jump[v][i-1]]);
	}
	dep[v] = dep[pop]+1;
	for (int i=0; i<G[v].size(); i++) {
		if (G[v][i] == pop)
			continue;
		dfs(G[v][i], v);
	}
}

int lca (int a, int b) {
//	cout<< "lca" << a << "," << b << ":\n";
//	cout<< "PREa0maxi=" << maxi[a][0] << "a0mini=" << mini[a][0] << "b0maxi=" << maxi[b][0] << "b0mini=" << mini[b][0] << "\n";

//	int wynmaxi = -1e9, wynmini = 1e9;
	if (dep[a] < dep[b])
		swap(a, b);
	for (int i=MXLG-1; i>=0; i--) {
		if (dep[jump[a][i]] >= dep[b]) {
//			wynmaxi = max (wynmaxi, maxi[a][i]);
//			wynmini = min (wynmini, mini[a][i]);
			a = jump[a][i];
		}
	}
//	cout<< "w1: " << wynmini << " " << wynmaxi << "\n";
//	cout<< dep[a] << " " << dep[b] <<"\n";
	assert (dep[a] == dep[b]);
	if (a==b)
//		return make_pair(wynmini, wynmaxi);
		return a;
	for (int i=MXLG-1; i>=0; i--) {
		if (jump[a][i] != jump[b][i]) {
//			wynmaxi = max (wynmaxi, maxi[a][i]);
//			wynmaxi = max (wynmaxi, maxi[b][i]);
//			wynmini = min (wynmini, mini[a][i]);
//			wynmini = min (wynmini, mini[b][i]);
			a = jump[a][i];
			b = jump[b][i];
		}
	}
//	cout<< "w2: " << wynmini << " " << wynmaxi << "\n";
//	cout<< jump[a][0] << " " << jump[b][0] << "\n";
	assert (jump[a][0] == jump[b][0]);
//	cout<< "a0maxi=" << maxi[a][0] << "a0mini=" << mini[a][0] << "b0maxi=" << maxi[b][0] << "b0mini=" << mini[b][0] << "\n";
//	wynmaxi = max(wynmaxi, maxi[a][0]);
//	wynmaxi = max(wynmaxi, maxi[b][0]);
//	wynmini = max(wynmini, mini[a][0]);
//	wynmini = max(wynmini, mini[b][0]);
//	cout<< "w3: " << wynmini << " " << wynmaxi << "\n";
//	return make_pair(wynmini, wynmaxi);
	return jump[a][0];
}


int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b;
	cin>> n;
	for (int i=1; i<n; i++) {
		cin >> a;
		ojcowie[i] = a;
		G[a].push_back(i);
		G[i].push_back(a);
	}
	for (int i=0; i<=n; i++) {
		mini[i] = G[i].size() - 1;
		maxi[i] = G[i].size() - 1;
	}
	mini[0] ++;
	maxi[0] ++;
	dep[0] = -1;
	dfs (0, 0);
/*	for (int i=1; i<=n; i++)
		cout<< dep[i] << " ";
	cout<< "\n";
	for (int i=1; i<=n; i++) {
		for (int j=0; j<MXLG; j++)
			cout<< jump[i][j] << " ";
		cout<< "\n";
	}
	cout<< "minima: ";
	for (int i=0; i<n; i++) {
		cout<< mini[i] << " ";
	}
	cout<< "\nmaksima: ";
	for (int i=0; i<n; i++) {
		cout<< maxi[i] << " ";
	}
	cout<< "\n";
*/	int q;
	cin>> q;
	for (int i=0; i<q; i++) {
		cin>> a >> b;
		int ojciec = lca(a, b);
		if (ojciec == a || ojciec == b)
			ojciec = ojcowie[ojciec];
		
//		cout<< ojciec << "\n";
		int minimum = mini[ojciec];
		int maximum = maxi[ojciec];
		minimum ++;
		maximum ++;
		cout<< minimum << " " << maximum << "\n";
		
	}
	return 0;
}
