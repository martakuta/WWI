#include <bits/stdc++.h>
#include "cjajlib.h"
using namespace std;

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	int n = dajN();
	bool stluklosie1 = 0;
	int pietro = min(878, n);
	while (stluklosie1 == 0) {
//		cout<< "rzuc" << pietro << "\n";
		if (rzucJajko(pietro) == 1) {
			pietro += 878;
			pietro = min(pietro, n);
		} else 
			stluklosie1 = 1;
	}
//	cout<< "sluklosie1=" << pietro << "\n";
	bool stluklosie2 = 0;
	pietro -= 878;
	pietro ++;
	pietro = max (pietro, 1);
	while (stluklosie2 == 0) {
//		cout<< "rzuc" << pietro << " ";
		if (rzucJajko(pietro) == 1)
			pietro ++;
		else
			stluklosie2 = 1;
	}
//	cout<< "sluklosie2=" << pietro << "\n";
	cout<< pietro << "\n";
	return 0;
}
