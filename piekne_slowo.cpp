#include <bits/stdc++.h>
using namespace std;

int tab[1000*1000+5];

void tab_pref_suf (string s) {
	int t = 0;
	s = '#' + s;
	for (int i=2; i<s.size(); i++) {
//		cout<< i << " " << t << "\n";
		while (t>0 && s[i] != s[t+1])
				t = tab[t];
		if (s[i] == s[t+1])
			t++;
		tab[i] = t;
	}
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string poemat;
	cin>> poemat;
	tab_pref_suf (poemat);
	for (int i=1; i<=poemat.size(); i++) {
		if (tab[i] > 0)
			cout<< "1";
		else
			cout<< "0";
	}
	cout<< "\n";
	return 0;
}
