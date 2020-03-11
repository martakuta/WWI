/*
  Przykładowa biblioteka do zadania Jajko. Można jej użyć w swoim kodzie dopisując na początku
  #include "cjajlib.h" i zapisując plik w tym samym folderze w którym ma się kod.
*/

#ifndef CJAJLIB_H
#define CJAJLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

const int MAXR = 2017;
int N, M;

void init() {
    static int wywolano = 0;
    if(wywolano) {
        puts("Funkcje init wywołano więcej niż raz");
        exit(0);
    }
    wywolano = 1;

    scanf("%d%d", &N, &M); // N - wysokość bloku, M - pierwsza wysokość, taka że jajko się stłucze
    
    if(N < 1 || N > 1000000 || M < 1 || M > N) {
        puts("Niepoprawne liczby na wejściu");
        exit(0);
    }
}

int dajN() {
    return N;
}

int rzucJajko(int x) {
    static int uzyte = 0;
    static int ruchy = 0;

    if(x < 1 || x > N) {
        puts("Zapytanie o niepoprawne piętro!");
        exit(0);
    }
    
    bool res = x < M;
    uzyte += !res;
    ruchy++;
    
    if(uzyte > 2){
        puts("Za dużo zbitych jajek!"); 
        exit(0);       
    }
    
    if(ruchy > MAXR) {
        puts("Za dużo wykonanych ruchów");
        exit(0);
    }

    return res;
}

#endif
