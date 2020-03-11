#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define f first
#define s second

struct klotnia {
	int a, b, t;
};

struct pytanie {
	int a, b;
};

int kiedy[1000*1000+5]; //tutaj beda wyniki kiedy dla zapytania o danym indeksie klasycy stracili ze soba kontakt
klotnia kl[1000*1000+5]; //trzyma informacje, potem posortowane, o kolejnych klotniach: kto z kim i kiedy
vector <pair<int,int> > G[1000*1000+5]; //tutaj przechowuje w tablicy wektorow ze dany klasyk mial kiedykolwiek kontakt z jakims innym klasykiem
pytanie pyt[1000*1000+5]; //tutaj trzymam pytania i dzieki temu mam ich indeksy
int rep[1000*1000+5];

bool compareKL (klotnia a, klotnia b) {
	return a.t < b.t;
}

int fin (int v) {
//	cout << v << "!" << rep[v] << endl;
//	char znak;
//	cin>> znak;
	if (rep[v] == v)
		return v;
	return rep[v]=fin(rep[v]);
}

void onion (int obecna) {
	int a = kl[obecna].a;
	int b = kl[obecna].b;
	int t = kl[obecna].t;
//	cout<< "find" << endl;
	int fa = fin(a);
//	cout<< "finda" << endl;
	int fb = fin(b);
//	cout << "hello" << endl;
	if (fa == fb)
		return;
	if (G[fa].size() > G[fb].size()) { //jesli wierzcholek a znajduje sie w  wiekszym poddrzewie (jest do niego wiecej zapytan)
		//i ide po kolei po wszystkich zapytaniach do mniejszego poddrzewa czyli b
		swap (fb, fa);
	}
//	G[fb].reserve(G[fb].size() + G[fa].size()); //rezerwuje w wektorze miejsce na wszystko co wiem ze bede do niego wrzucac
	for (int i=0; i<G[fa].size(); i++) {
		int sz = G[fa][i].f; 
		if (fin(sz) == fb) { //dla kazdego zapytania sprawdzam czy szukany nalezy do poddrzewa wiekszego
			//jesli nalezy to mamy czas w ktorym realizuje sie to zapytanie
			int zapnr = G[fa][i].s; // to jest numer ow zapytania
			kiedy[zapnr] = max (t, kiedy[zapnr]); //i daje mu obecny czas t, pod warunkiem ze nie mialam tam znalezionego wczesniej czasu
		} else { // jesli nie nalezy do poddrzewa wiekszego
			//to przepisuje dane zapytanie do wektora reprezentanta wiekszego poddrzewa
			G[fb].push_back(mp(G[fa][i].f, G[fa][i].s));
		}
	}
	//na koniec po przejsciu calego wektora moge go wyczyscic
	G[fa].clear();
	rep[fin(fa)] =fin( fb); // podlaczam poddrzewo a do poddrzewa b
	
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin>> n >> m; //n to liczba klasykow, m to liczba par ktore sie klocily
	for (int i=1; i<=m; i++) {
		cin>> kl[i].a >> kl[i].b >> kl[i].t; //a i b to numery pokloconych klasykow, t to czas w ktorym sie poklocili
	}
	sort (kl+1, kl+m+1, compareKL); //sortuje tak aby klotnie byly ustawione w tablicy kl w kolejnosci chronologicznej rosnacej
	int q;
	cin>> q; //q to liczba zapytan bajtonisty
//	for (int i=1; i<=n; i++)
//		G[i].reserve(10); //mozliwe ze bardziej oplaca sie np 15 ale to trzeba metoda prob i bledow zobaczyc gdzie ma najlepsze czasy
	for (int i=1; i<=q; i++) {
		int a, b;
		cin>> a >> b; // a i b to klasycy o ktorych pyta bajtonista: o to kiedy stracili ze sobą kontakt - bezposredni lub posredni
		pyt[i].a = a;
		pyt[i].b = b;
		G[a].push_back(mp(b, i));
		G[b].push_back(mp(a, i));
	}
	for (int i=1; i<=n; i++)
		rep[i] = i;
//	cout<< "wstepne" << endl;
	int obecna = m; // teraz wszyscy klasycy sa pokloceni, czyli zadne wierzcholki nie sa polaczone
	while (obecna > 0) {
		//biore najstarsza klotnie z tablicy kl
//		cout<< obecna << endl;
		onion (obecna);
//		cout<< obecna << endl;
		obecna --;
	}
//	cout<< "wypisz" << endl;
	for (int i=1; i<=q; i++) {
		if (kiedy[i] == 0)
			cout<< "nigdy.\n";
		else
			cout<< kiedy[i] << "\n";
	}
//	cout<< "\n";
	return 0;
}
