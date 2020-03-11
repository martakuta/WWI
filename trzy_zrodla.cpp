#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL r;	
int z[3][2];

bool odl (int zr, int x, int y) {
	int zx = z[zr][0];
	int zy = z[zr][1];
/*	int iks = x - zx;
	int igrek = y - zy;
	LL iksy = iks*iks;
	LL igreki = igrek*igrek;
	LL wynik = iksy + igreki;
*/	LL r2 = r*r;
	LL wynik = (x-zx)*(x-zx) + (y-zy)*(y-zy);
	if (wynik <= r2) // jest w zasiegu zrodla
		return 1;
	else
		return 0;
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x, y;
	int trafione=0, nietrafione=0;
	cin>> r;
	r *= 1000;
	for (int i=0; i<3; i++) {
		cin>> x >> y;
		z[i][0] = x*1000;
		z[i][1] = y*1000;
	}
	srand(100);
	//dla wygody licze teren w "m" a dopiero potem zamienie je na "km"
	for (int i=0; i<2000000; i++) {
		x = rand()%10001;
		y = rand()%10001;
//		cout<< x << " " << y << "   ";
		//licze czy jest w zasiegu ktoregos ze zrodel
		bool jest = 0;
		for (int j=0; j<3; j++) { // sprawdzam po kolei dla kazdego zrodla
			if (odl(j, x, y) == 1) {
				jest = 1;
				break;
			}
		}
		if (jest == 1)
			trafione ++;
		else
			nietrafione ++;
	}
	double traf = trafione;
	double nietraf = nietrafione;
	double wynik = traf/(nietraf+traf);
	wynik *= 100;
//	cout<< "\n" << trafione << " " << nietrafione << "\n";
	cout<< setprecision(2) << fixed << wynik << "\n";	
	return 0;
}
