#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sn(int n ) {
    if (n == 0){ return 3;}
    double res=3;
    int i;
    for (i = 1; i < n+1; i++){
        if (i%2){
            res += 4./((2*i)*(2*i+1)*(2*i+2));
        }
        else{
            res -= 4./((2*i)*(2*i+1)*(2*i+2));
        }
    }
    return res;
}

double Pi(double eps){
    double x=sn(0),y=sn(1);
    int i=2;
    while( fabs(x-y) > (fabs(x)+fabs(y))*eps){
        x=y;
        y=sn(i);
        i++;
    }
    return y;

}

int main (){
    printf("Valeur de epsillon?\n");
    double eps;
    scanf("%lf",&eps);
    printf("La valeur de PI est %lf",Pi(eps));
}
