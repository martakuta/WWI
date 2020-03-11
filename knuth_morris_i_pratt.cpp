#include <bits/stdc++.h>
using namespace std;

const int N = 1000*1000+5;
int T[2*N];

void kmp (string s) {
	int wynik = 0;
	s = '#' + s;
	for (int i=2; i<s.size(); i++) {
		while (wynik > 0 && s[i] != s[wynik+1])
			wynik = T[wynik];
		if (s[i] == s[wynik+1])
			wynik ++;
		T[i] = wynik;
	}
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>> n;
	for (int nr=0; nr<n; nr++) {
		string a, b; //czy slowo a zawiera sie w slowie b
		cin>> a >> b;
		a += '*';
		int dl_a = a.size();
		int x=0;
		bool jest = 1;
		while (x<dl_a) {
			string wzorzec = "";
			while (a[x] != '*') {
				wzorzec += a[x];
				x++;
			}
			string szukaj = wzorzec + '$' + b;
			kmp (szukaj);
//			cout<< " " <<szukaj << " " <<wzorzec << ":\n";
//			for (int i=0; i<=szukaj.size(); i++)
//				cout<< T[i];
//			cout<< "\n";
			int ile = wzorzec.size();
			for (int i=0; i<=szukaj.size(); i++) {
				if (T[i] == ile) {
//					cout<< i << "\n";
					string nowy = "";
					for (int k=i; k<szukaj.size(); k++)
						nowy += szukaj[k];
					b = nowy;
//					cout<< nowy << "\n";
/*					if (nowy == "") {
						cout<< "Nie ma go.\n";
						jest = 0;
						i = szukaj.size();
					}
*/					break;
				}
				if (i == szukaj.size()) {
					cout<< "Nie ma go.\n";
					jest = 0;
					x = dl_a;
				}
			}
			x++;
		}
		if (jest == 1)
			cout<< "Jest.\n";
	}
	return 0;
}
