#include <bits/stdc++.h>
using namespace std;

vector <int> G[100*1000+5];
vector <int> glowy;
vector <int> ogony;
int zawiera[100*1000+5];

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, g, o;
	cin>> n >> m >> g >> o;
	for (int i=0; i<m; i++) {
		int a, b;
		cin>> a >> b;
		if (a != b) { //bo jesli sa przy u lub v to zaburzaja zliczanie ich sasiadow, a tak naprawde potem i tak bysmy je pomineli
			G[a].push_back(b);
			G[b].push_back(a);
		}
	}
	for (int i=1; i<=n; i++) {
		if (G[i].size() -1 >= g)
			glowy.push_back(i);
		if (G[i].size() -1 >= o)
			ogony.push_back(i);
	}
	for (int i=0; i<glowy.size(); i++) {
		for (int j=0; j<ogony.size(); j++) {
			if (glowy[i] == ogony[j])
				continue;
			bool g_o = 0;
			for (int x=1; x<=n; x++)
				zawiera[x] = 0;
			int biez_g = glowy[i];
			int biez_o = ogony[j];
			for (int x=0; x<G[biez_g].size(); x++) {
				if (G[biez_g][x] == biez_o)
					continue;
				zawiera[ G[biez_g][x] ] = 1; //1 jesli jest tylko dla glow
			}
			for (int x=0; x<G[biez_o].size(); x++) {
				if (G[biez_o][x] == biez_g) {
					g_o = 1;
					continue;
				}
				if (zawiera[ G[biez_o][x] ] == 1)
					zawiera[ G[biez_o][x] ] = 3;
				else
					zawiera[ G[biez_o][x] ] = 2;
			}
			int brakglow = g, brakogonow = o, podwojne = 0;
			for (int x=1; x<=n; x++) {
				if (zawiera[x] == 1)
					brakglow --;
				else if (zawiera[x] == 2)
					brakogonow --;
				else if (zawiera[x] == 3)
					podwojne ++;
			}
			if (podwojne < brakglow + brakogonow)
				continue;
			else if (g_o == 1){
				cout<< "TAK\n";
				cout<< biez_g << " " << biez_o << "\n";
				queue <int> gl;
				queue <int> og;
				queue <int> podw;
				for (int y=1; y<=n; y++) {
					if (zawiera[y] == 1)
						gl.push(y);
					if (zawiera[y] == 2)
						og.push(y);
					if (zawiera[y] == 3)
						podw.push(y);
				}
				int jeszcze_g = g;
				if (gl.size() >= jeszcze_g) { 
					while (jeszcze_g > 0) {
						int wybierz = gl.front();
						gl.pop();
						cout<< wybierz << " ";
						jeszcze_g --;
					}
				} else {
					while (!gl.empty()) {
						int wybierz = gl.front();
						gl.pop();
						cout<< wybierz << " ";
						jeszcze_g --;
					}
					while (jeszcze_g > 0) {
						int wybierz = podw.front();
						podw.pop();
						cout<< wybierz << " ";
						jeszcze_g --;
					}
				}
				cout<< "\n";
				int jeszcze_o = o;
				if (og.size() >= jeszcze_o) { 
					while (jeszcze_o > 0) {
						int wybierz = og.front();
						og.pop();
						cout<< wybierz << " ";
						jeszcze_o --;
					}
				} else {
					while (!og.empty()) {
						int wybierz = og.front();
						og.pop();
						cout<< wybierz << " ";
						jeszcze_o --;
					}
					while (jeszcze_o > 0) {
						int wybierz = podw.front();
						podw.pop();
						cout<< wybierz << " ";
						jeszcze_o --;
					}
				}
				cout<< "\n";
				return 0;
			}
		}
	}
	cout<< "NIE\n";
	return 0;
}
