#include <stdio.h>
#include <stdlib.h>

void swap2Double ( double* x, double* y ) {
  double tmp;
  tmp = *x;
  *x=*y;
  *y=tmp;
}

void swap3Double ( double* x, double* y , double* z ) {
  swap2Double(x, z);
  swap2Double(y, z);
}


int main(void) {
  double x = 10, y = 2;
  printf("Valeur de x=%lf et y=%lf avant l’echange\n",x,y);
  swap2Double( &x, &y );
  printf("Valeur de x=%lf et y=%lf apres l’echange\n",x,y);
  /* ici a doit valoir 2 et b 10 */
  double a = 10, b = 2, c = 3;
  printf("Valeur de a=%lf b=%lf c=%lf avant l’echange\n",a,b,c);
  swap3Double(&a,&b,&c);
  /* ici a == 3, b == 10, c == 2 */
  printf("Valeur de a=%lf b=%lf c=%lf apres l’echange\n",a,b,c);
  return EXIT_SUCCESS;
}
