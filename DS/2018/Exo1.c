#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double racine(double a, double eps){
    if (a==0){ return 0;}
    double x,y;
    x=a;
    y=(x+a/x)/2;
    while ( abs(x - y ) > eps){
        x=y;
        y=(x+a/x)/2;
    }
    return y;
}

int main() {
   double a, eps;
   eps = pow(10,-7);
   printf("Entrer la valeur choisi pour a\n");
   scanf("%lf",&a);
   printf("La racine de %lf est à peut près égale à %lf\n", a, racine(a,eps));
}
