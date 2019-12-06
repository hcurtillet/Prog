#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fractale.h"


void fractale(T_coordonnees ma, T_coordonnees mb, int n, T_couple* couple ) {
  (*couple).c1.x=ma.x;
  (*couple).c1.y=ma.y;
  (*couple).c2.x=mb.x;
  (*couple).c2.y=mb.y;
  if ( n > 1 ) {
    T_coordonnees m1, m2;
    m1.x= mb.x + R*COS*(mb.x - ma.x) - R*SIN*(mb.y - ma.y);
    m2.x= mb.x + R*COS*(mb.x - ma.x) + R*SIN*(mb.y - ma.y);
    m1.y= mb.y + R*SIN*(mb.x - ma.x) + R*COS*(mb.y - ma.y);
    m2.y= mb.y - R*SIN*(mb.x - ma.x) + R*COS*(mb.y - ma.y);
    couple++;
    fractale(mb, m1, n-1, couple );
    int i=pow(2,n-1)-1;
    couple+=i;
    fractale(mb, m2, n-1, couple );
  }
}

int calcNbCouple(int n ) {
    int u=0, i=0;
    for ( i=0 ; i<n ; i++) {
        u=u+pow(2,i);
    }
    return u;
}
/*
int main(int argc, char const *argv[]) {
  int n=3, i=0; int nbCouple;
  T_coordonnees ma={100,0},mb = { 100, 100 };
  nbCouple=calcNbCouple(n);
  T_couple listeCoupe[nbCouple];
  for ( i = 0 ; i < nbCouple; i++ ) {
    (*(listeCoupe+i)).c1.x=0;
    (*(listeCoupe+i)).c1.y=0;
    (*(listeCoupe+i)).c2.x=0;
    (*(listeCoupe+i)).c2.y=0;
  }
  for ( i = 0 ; i < nbCouple; i++ ) {
    printf(" Le couple %d est (%d;%d) et (%d;%d)\n", i, (*(listeCoupe+i)).c1.x , (*(listeCoupe+i)).c1.y, (*(listeCoupe+i)).c2.x, (*(listeCoupe+i)).c2.y);
  }
  T_couple * couple;
  couple = listeCoupe;
  fractale(ma, mb, n, couple);
  for ( i = 0 ; i < nbCouple; i++ ) {
    printf(" Le couple %d est (%d;%d) et (%d;%d)\n", i, (*(listeCoupe+i)).c1.x , (*(listeCoupe+i)).c1.y, (*(listeCoupe+i)).c2.x, (*(listeCoupe+i)).c2.y);
  }
}
*/
