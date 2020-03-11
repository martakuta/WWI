#include <bits/stdc++.h>
using namespace std;

string slowa[10*1000+5];
int pocz[10*1000+5];
int sum[27], biez[27];
string wynik = "";

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	string a;
	cin>> n;
	cin>> a;
	slowa[0] = a;
	for (int j=0; j<a.size(); j++) {
		sum[ (int)(a[j]) - 97 ] ++;
	}
	
	for (int i=1; i<n; i++) {
		cin>> a;
		slowa[i] = a;

		for (int j=0; j<a.size(); j++) {
			biez[ (int)(a[j]) - 97 ] ++;
		}
		for (int j=0; j<26; j++) {
			sum[j] = min (sum[j], biez[j]);
		}
	}
	for (int i=25; i>=0; i--) {
		int ile = sum[i];
		if (ile > 0) {
			for (int j=0; j<n; j++) {
				int ilelit = ile;
				if (slowa[j].size() <= pocz[j])
					break;
				if (j == n-1)
					wynik += char(i+97);
				while (ilelit > 0) {
					for (int x=pocz[j]; x<slowa[j].size(); x++) {
						if (slowa[j][x] == char(i+97)) {
							ilelit --;
						}
						if (ilelit == 0) {
							pocz[j] = x + 1;
							break;
						}
					}
				}
				
			}
		}
	}
	if (wynik < "bitek")
		wynik = "bitek";
	cout<< wynik << "\n";
	return 0;
}
