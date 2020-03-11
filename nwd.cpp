#include <bits/stdc++.h>
using namespace std;

const int M = 1024*1024;
long long d[2*M];
int kubelek[M];

int nwd (int a, int b) {
	if (a < b)
		swap (a, b);
	if (b==0)
		return a;
	else
		return nwd(b, a%b);
}

void dodaj (int gdzie, int ile) {
	gdzie = gdzie+M-1;
	d[gdzie] = ile;
	while (gdzie>1) {
		gdzie /= 2;
		d[gdzie] = nwd(d[gdzie*2], d[gdzie*2+1]);
	}
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>> q;
	for (int i=0; i<q; i++) {
		int z;
		cin>> z;
		if (z > 0) {
			kubelek[z] ++;
			dodaj (z, z);
		} else {
			kubelek[-z] --;
			if (kubelek[-z] == 0)
				dodaj (-z, 0);
		}
		int wynik = d[1];
		cout<< wynik << "\n";
	}	
	return 0;
}
