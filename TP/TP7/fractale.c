#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fractale.h"


void fractale(T_coordonnees ma, T_coordonnees mb, int n) {
  printf("Les coordonnées des points sont (%lf,%lf) et (%lf,%lf)\n", ma.x, ma.y, mb.x, mb.y);
  if ( n > 1 ) {
    printf("\n On descend!\n\n");
    T_coordonnees m1, m2;
    m1.x= mb.x + R*COS*(mb.x - ma.x) - R*SIN*(mb.y - ma.y);
    m2.x= mb.x + R*COS*(mb.x - ma.x) + R*SIN*(mb.y - ma.y);
    m1.y= mb.x + R*SIN*(mb.x - ma.x) + R*COS*(mb.y - ma.y);
    m2.y= mb.x - R*SIN*(mb.x - ma.x) + R*COS*(mb.y - ma.y);
    fractale(mb, m1, n-1);
    printf("\n On descend!\n\n");
    fractale(mb, m2, n-1);
  }
}
