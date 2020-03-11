#include <bits/stdc++.h>
using namespace std;

int T[500*1000+5];
int dp[500*1000+5][2];

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>> n;
	for (int i=1; i<=n; i++) {
		cin>> T[i];
	}
	for (int i=1; i<=n; i++) { //biore liczbe czyli podnosze jej wartosc do 9
		dp[i][0] = max (dp[i-1][0], dp[i-1][1]) + T[i]; //jesli teraz nie biore liczby to w poprzednim ruchu moglam ja wziac lub nie - w zaleznosci co mi sie bardziej oplaca
		dp[i][1] = dp[i-1][0] + 9; //jesli teraz biore liczbe to w poprzednim ruchu musialam nie wziac
	}
	int wynik = max (dp[n][0], dp[n][1]);
	cout<< wynik << "\n";
	return 0;
}
