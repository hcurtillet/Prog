#include <stdio.h>
#include <stdlib.h>
#include "TP7_1.h"


int pgcd(int a, int b){
  if ( a < b) {
      int tmp;
      tmp = b;
      b=a;
      a=tmp;
  }
  if ( b == 0 ){
      return a;
  }
  else {
      int reste;
      reste = a % b;
      return pgcd(b, reste);
  }
}

int main(){
    int a=221, b=782, res;
    res=pgcd(a,b);
    printf("Le pgcd de %d et %d est %d", a, b, res);

}
