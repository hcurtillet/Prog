#include <stdio.h>
#include <stdlib.h>

double somme( double a, double b ) {
  return a + b;
}

void diff( double a , double b, double* d) {
  *d = a-b;
}

void sommediff( double a, double b, double* c, double* d) {
  *c=somme(a,b);
  diff(a,b,d);
}

int main() {
  double x, y, z, w;
  printf("Saisir des valeurs pour x et y.\n");
  scanf("%lf %lf", &x, &y);
  sommediff(x,y,&w,&z);
  printf("La somme de x et y vaut %lf et la différence vaut %lf", w, z);

}
