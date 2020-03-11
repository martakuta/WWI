#include <bits/stdc++.h>
using namespace std;
char T[1000+5][1000+5];
vector <pair<int,int> > G[1000+5][1000+5];
#define mp make_pair
#define f first
#define s second
int odl[1000+5][1000+5];
int w, h;
const int inf=1000*1000*1000;
void bfs (int p1, int p2) {
	for (int i=0; i<=h; i++) {
		for (int j=0; j<=w; j++)
			odl[i][j] = inf;
	}
	odl[p1][p2] = 0;
	queue <pair <int, int> > q;
	q.push(mp(p1, p2));
	while (!q.empty()) {
		int u1 = q.front().f;
		int u2 = q.front().s;
		q.pop();
		for (int j=0; j<G[u1][u2].size(); j++) {
			int x1 = G[u1][u2][j].f;
			int x2 = G[u1][u2][j].s;
			if (odl[x1][x2] > odl[u1][u2]+1) {
				odl[x1][x2] = odl[u1][u2]+1;
				q.push(mp(x1, x2));
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>> w >> h;
	int p1, p2, w1, w2;
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=w; j++) {
			char znak;
			cin>> znak;
			T[i][j] = znak;
			if (znak == 'P') {
				p1 = i;
				p2 = j;
				T[i][j] = '.';
			}
			if (znak == 'W') {
				w1 = i;
				w2 = j;
				T[i][j] = '.';
			}
		}
	}
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=w; j++) {
			if (T[i][j] == '#')
				continue;
			if (T[i][j-1] == '.')
				G[i][j].push_back(mp(i, j-1));
			if (T[i][j+1] == '.')
				G[i][j].push_back(mp(i, j+1));
			if (T[i-1][j] == '.')
				G[i][j].push_back(mp(i-1, j));
			if (T[i+1][j] == '.')
				G[i][j].push_back(mp(i+1, j));
		}
	}
	bfs(p1, p2);
	if (odl[w1][w2] == inf)
		cout<< "NIE\n";
	else cout<< odl[w1][w2] << "\n";
/*	for (int i=0; i<10; i++) {
		cout<<"i=" << i << ": ";
		for (int j=0; j<10; j++) {
			cout<< "j=" << j << ": ";
			for (int a=0; a<G[i][j].size(); a++)
				cout<< G[i][j][a].f << " " << G[i][j][a].s << "   ";
		}
		cout<< "\n";
	}*/
/*	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++)
			cout<< odl[i][j] << " ";
		cout<< "\n";
	}*/
	
	return 0;
}
