#include <bits/stdc++.h>
using namespace std;

int tab[2][3]; // pa = [0][0], pb = [1][0], ga = [0][1], gb = [1][1], sa = [0][2], sb = [1][2]
bool tie_break = 0;

void zwieksz (int x) {
	int p;
	if (x == 0)
		p = 1; // p to numer przeciwnika
	else
		p = 0;
	int pm = 4; //pilki potrzebne do wygrania gema
	if (tie_break == 1) {
		pm = 7;
		tie_break = 0;
	}
//	cout<< tab[x][0] << " " << pm << " " << tab[x][0] - tab[p][0] << "\n";
	if (tab[x][0] < pm || tab[x][0] - tab[p][0] < 2) //jesli jeszcze nie wygral 4 pilek lub nie ma przewagi 2 pilek to zwiekszam pilki
		tab[x][0] ++;
	
	if (tab[x][0] >= pm && tab[x][0] - tab[p][0] >= 2)  {//jesli teraz wygral min 4 pilki i ma przewage 2 pilek to wygrywa gema
		tab[x][1] ++;
		tab[x][0] = 0; //po zakonczeniu gema pilki sie zeruja
		tab[p][0] = 0;
	}
	if (tab[x][1] == 6 && tab[p][1] == 6) { // jesli jest 6:6 to wyjatek, tie-break
		tie_break = 1;
//		cout<< "tie-break\n";
	}
	if (tab[x][1] >= 6 && tab[x][1] - tab[p][1] >= 2)  {//jesli wygral min 6 gemow i ma przewage 2 gemow to wygrywa seta
		tab[x][2] ++;
		tab[x][1] = 0; //po zakonczeniu seta gemy sie zeruja
		tab[p][1] = 0;
	}
	if (tab[x][1] == 7) { //jesli stalo sie ze wygral 7 gema to znaczy ze byl tie-break i ten 7 gem wygrywa seta mimo ze jest 1 przewagi
		tab[x][2] ++;
		tab[x][1] = 0;
		tab[p][1] = 0;
	}
	if (tab[x][2] == 3) { //jesli wygral 3 seta to wygrywa mecz
		if (x == 0)
			cout<< "A\n";
		else
			cout<< "B\n";
		return;
	}
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string mecz;
	cin>> mecz;
	int dl = mecz.size();
	
	for (int i=0; i<dl; i++) {
		if (mecz[i] == 'A')
			zwieksz (0);
		else
			zwieksz (1);
//		cout<< mecz[i] << " " << tab[0][0] << " " << tab[1][0] << " " << tab[0][1] << " " << tab[1][1] << " " << tab[0][2] << " " << tab[1][2] << "\n";
	}
	return 0;
}
