#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void prod(double a, double b, double *res){
    *res=a*b;
}

double somme(double a, double b ) {
    return a+b;
}

void sp(double a, double b, double *s, double *p){
    *s=somme(a,b);
    prod(a,b,p);
}

int main(){
    double a,b,s,p;
    printf("Entrez deux valeurs:\n");
    scanf("%lf\n%lf",&a,&b);
    sp(a,b,&s,&p);
    printf("La somme de %lf et %lf vaut %lf et le produit %lf",a,b,s,p);
}
