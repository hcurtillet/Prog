#include <stdio.h>
#include <stdlib.h>

int diviseurs (int n, int diviseurs[]){
  int nb=0,i=0,comp=0;
  for (i=1;i<n;i++){
    if ((n%i)==0){
      diviseurs[comp]=i;
      comp++;
    }
  }
  return comp;
}

int somme(int diviseurs[], int nbdiviseurs){
  int somme=0,i;
  for(i=0;i<nbdiviseurs;i++){
    somme += diviseurs[i];
  }
  return somme;

}

void affiche(int *tableau, int tailleTableau)
{
    int i;

    for (i = 0 ; i < tailleTableau ; i++)
    {
        printf("%d\n", tableau[i]);
    }
}

int perfection(int n) {
  int tab[n],nbdiviseurs,res;
  nbdiviseurs=diviseurs(n,tab);
  res = somme(tab,nbdiviseurs);
  if (res==n){
    return 1;
  }
  else{
    return 0;
  }
}
/*
int main (){
  int n,test;
  printf("Quel nombre voulez vous tester?\n");
  scanf("%d",&n);
  test = perfection(n);
  if (test ==1){
    printf("%d est un nombre parfait\n",n);
  }
  else{
  printf("%d n'est pas un nombre parfait\n",n);
  }
}
*/


int main(){
  int n=1,test=0,nbtest;
  printf("Jusqu'où voulez vous faire des testes de nombre parfait?\n");
  scanf("%d",&nbtest);
  do {
    n++;
    test = perfection(n);
    if (test==1){
      printf("%d est un nombre parfait\n",n);
    }
  }
  while (n<nbtest);
  return 0;
}
