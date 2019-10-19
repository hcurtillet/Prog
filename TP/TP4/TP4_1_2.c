#include <stdio.h>
#include <stdlib.h>

double produit( double x, double y ) {
  return x*y;
}

void somme( double x , double y , double* res ) {
  *res= x + y;
}

void sommediff( double a, double b, double* c, double* d) {
  somme(a,b,c);
  *d=produit(a,b);
}


int main() {
  double x, y, z, w;
  printf("Saisir des valeurs pour x et y.\n");
  scanf("%lf %lf", &x, &y);
  sommediff(x,y,&w,&z);
  printf("La somme de x et y vaut %lf et le produit vaut %lf", w, z);

}
