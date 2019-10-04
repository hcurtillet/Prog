#ifndef _MASTER
#define _MASTER
#define M 7
#define N 5
#include <stdio.h>
void init(int tab[], int n, int m);
void affiche(int tab[], int n, int m);
int malplace(int joueur[], int  machine[], int n, int m);
void lire(int tab[], int n, int m);
int bienplace(int joueur[], int machine[], int n);

#endif
