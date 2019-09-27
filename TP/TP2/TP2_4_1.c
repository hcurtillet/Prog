#include <stdio.h>
#include <math.h>

double puissance (double x, int n){
  double res=1;
  while (n>0){
    res=res*x;
    n=n-1;
  }
  return res;
}

double puissanceneg (float x, int n){
  double res=1;
  while (n>0){
    res=res/x;
    n=n-1;
  }
  return res;
}

int main(){
  double u=1,v=0,puiss,a,pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348;
  int n=0,prescision;
  printf("La préscision voulue est de 10^-?\n");
  scanf("%d",&prescision);
  v=(4-2.0/4-1.0/5-1.0/6);
  printf("Pour n=%d, u=%1.25lf et v=%1.25lf\n",n,u,v);
  while (fabs(u-pi/2.0)>puissanceneg(10,prescision)*(u+pi/2.0)){
    n++;
    u=u*(4*n*n)/((2*n-1)*(2*n+1));
  }
  printf("Pour une préscision de 10^-%d, u=%1.25lf à n=%d\n",prescision,u,n);
  n=0;
  while (fabs(v-pi)>puissanceneg(10,prescision)*(v+pi)){
    n++;
    puiss=puissance(1/16.0,n);
    a=(4.0/(8*n+1)-2.0/(8*n+4)-1.0/(8*n+5)-1.0/(8*n+6));
    v=v+a*puiss;
    printf("Pour n=%d, v=%1.25lf\n",n,v);
  }
  printf("Pour une préscision de 10^-%d, v=%1.25lf à n=%d\n",prescision,v,n);


}
