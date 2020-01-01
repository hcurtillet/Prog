#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void moyenne( double a, double b, double* moy){
    *moy = (a+b)/2;
}

double prod(double a, double b) {
    return a*b;
}

void mp(double a, double b, double*moy, double * produit){
    moyenne(a,b,moy);
    *produit=prod(a,b);
}
int main(){
    double a,b,moy,prod;
    printf("Entrer deux valeurs\n");
    scanf("%lf \n %lf",&a,&b);
    mp(a, b, &moy, &prod);
    printf("La moyenne de %lf et %lf est %lf\n",a,b,moy);
    printf("Le produit de %lf et %lf est %lf",a,b,prod);

}
