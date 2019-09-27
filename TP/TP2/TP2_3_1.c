#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double puissanceneg (float x, int n){
  double res=1;
  while (n>0){
    res=res/x;
    n=n-1;
  }
  return res;
}

int main(){
  int n=0,nmax;
  unsigned long long u=0,v=1,affiche;
  printf("Jusqu'à quel rang voulez vous afficher la suite de Fibonacci?\n");
  scanf("%d",&nmax);
  while (n<=nmax){
    if (n==0){
      affiche=u;
    }
    else if (n==1){
      affiche=v;
    }
    else{
      affiche=u+v;
      u=v;
      v=affiche;
    }
    printf("Au rang %d, la suite vaut %llu\n",n,affiche);
    n=n+1;

  }

  printf("Calculons maintenant le nombre d'or!\n");
  double a=1,b=2,c,vn=0,vm=2; /* on commence à n=2 car sinon on a abs(1-1)=0*/
  int prescision;
  printf("La préscision voulue est de 10^-?\n");
  scanf("%d",&prescision);
  while (fabs(vm-v)>(puissanceneg(10,prescision)*(vn+vm))){
    vn=vm;
    c=a+b;
    a=b;
    b=c;
    vm=b/a;
  }
  printf("Avec une préscision de 10^-%d, le nombre d'or calculé vaut %1.25lf",prescision,vn);

}
