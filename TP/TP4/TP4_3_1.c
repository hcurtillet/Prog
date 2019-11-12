#include <stdio.h>
#include <stdlib.h>
#define N 5


void lectureTabDouble(double* t, int n) {
  int i ;
  for (i=0 ; i<n ; i++) scanf("%lf",t+i) ;
}
void afficheTabDouble(double* t, int n) {
  int i ;
  for (i=0 ; i<n ; i++) printf("%lf\n",t[i]) ;
}


int estSymetriqueTabDouble(double t[], int n){
  double* p1;
  double* p2;
  p1 = t;
  p2 = t+n-1;
  while( (*p1==*p2) && (p1 <= (t+n))) {
    p1++;
    p2--;
  }
  return ( p1== t+n)?1:0;


}



int main() {
  double tab[N];
  lectureTabDouble(tab,N);
  printf("%d",estSymetriqueTabDouble(tab,N));
}
