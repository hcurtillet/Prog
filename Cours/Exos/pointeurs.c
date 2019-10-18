#include <stdio.h>
#include <stdlib.h>
#define N 10

int lecture(int tab[], int dim) {
  int* res;
  for (res=tab; res < tab+N; res++) {
    printf("La valeur du tableau à l'indice %p est %d\n ", res-tab , *res);
  }
  return 0;
}

int somme(int tab[], int dim) {
  int somme=0, i=0;
  for (i=0; i < dim; i++) {
    somme += *(tab+i);
  }
  return somme;

}

void copie(int tabnew[], int tab[], int dim) {
  int i;
  for (i=0; i < N; i++) {
    *(tabnew + i)= *(tab+i);
  }
}


int main() {
  int tab[N], tab2[N];
  int i=0;
  for (i=0; i < N; i++) {
    *(tab+i)=4*i;
    *(tab2+i)=2*i-6;
  }
  lecture(tab, N);
  lecture(tab2, N);
  printf("La somme des éléments du tableau est %d\n ", somme(tab, N));
  copie(tab2, tab, N);
  lecture(tab2, N);
}
