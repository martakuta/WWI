#include <bits/stdc++.h>
using namespace std;

vector <int> slowa[10*1000+5][26];
int pocz[10*1000+5];


int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	string wynik = "";
	cin>> n;
	for (int i=0; i<n; i++) {
		string a;
		cin>> a;
		for (int j=0; j<a.size(); j++) {
			slowa[i][ (int)(a[j] - 97) ].push_back(j);
		}
		for (int j=0; j<26; j++) {
			reverse (slowa[i][j].begin(), slowa[i][j].end());
		}
	}
	for (int i=25; i>=0; i--) {
		int mini = 1000*1000*1000;
		for (int j=0; j<n; j++) {
			if (!slowa[j][i].empty()) {
				while (slowa[j][i].back() < pocz[j] ) {
					slowa[j][i].pop_back();
					if (slowa[j][i].empty())
						break;
				}
			}
			int d = slowa[j][i].size();
			mini = min (mini, d);
		}
		int dodaj = mini;
		while (dodaj > 0) {
			wynik += (char)(i + 97);
			dodaj --;
		}
		for (int j=0; j<n; j++) {
			int zabierz = mini;
			while (zabierz > 0) {
				pocz[j] = slowa[j][i].back() + 1;
				slowa[j][i].pop_back();
				zabierz --;
			}
		}
	}
	if (wynik < "bitek")
		wynik = "bitek";
	cout<< wynik << "\n";
	return 0;
}
