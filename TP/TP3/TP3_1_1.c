#include <stdio.h>
#include <stdlib.h>

int max2entier (int a, int b){
  return a<b?b:a;
}

int max3entier (int a, int b, int c){
  int max;
  max=(a<b?b:a);
  return max<c?c:max;
}

int maxtab(int tab[], int dim){
  int max=tab3[0];
  for (i=0;i<dim;i++){
    if (max<=tab3[i])
      max=tab3[i];
  return max;
  }
}

int pgcd (int a, int b){
  int r;
  do {
    r=a%b;
    a=b;
    b=r;
  } while(r!=0);
  return a;
}
