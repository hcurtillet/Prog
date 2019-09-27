#include "stdio.h"
#include "stdlib.h"

int abs(int a){
  return a>0?a:-a;
}

int prod3(int a, int b, int c){
  return a*b*c;
}

int fact(int n){
  if (n>1){
    return n*fact(n-1);
  }
  else{
    return 1;
  }
}
int main(){
  int a,b,c;
  printf("Entrer une valeur\n");
  scanf("%d",&a);
  printf("La valeur absolue de %d est %d\n",a,abs(a));
  printf("Entrer une valeur\n");
  scanf("%d",&b);
  printf("Entrer ENCORE une valeur\n");
  scanf("%d",&c);
  printf("Le produit de %d, %d et %d est %d\n",a,b,c, prod3(a,b,c));
  printf("%d factorielle vaut %d\n",a,fact(a));

}
