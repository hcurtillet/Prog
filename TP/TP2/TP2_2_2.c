#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double max(double a, double b){
  if(a>=b)
  return a;
  else
  return b;
}


int main(){
  int nbTest=0, nbValeurOk=0;
  float res;
  srand(time(NULL));
  while (nbTest<100000000) {
    float l1,l2,l3,l4,maxi;
    l1=(float)rand()/(RAND_MAX+1.0);
    l2=1-l1;
    l3=l2*(float)(rand()/(RAND_MAX+1.0));
    l4=l2-l3;
    maxi=max(max(l1,l3),l4);
    if(maxi ==l1 && l3+l4>=l1){
      nbValeurOk++;
    }
    else if (maxi == l3 && l3<=l1+l4){
      nbValeurOk++;
    }
    else if (maxi ==l4 && l4<=l3+l1){
      nbValeurOk++;
    }
  nbTest++;
}
res=nbValeurOk/100000000.0;
  printf("La probabilité calculé est de %lf",res);
}
