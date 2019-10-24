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
double* adressePremierNegTabDouble(double* t, int n) {
  double* i;
  for ( i = t; i < t+n ; i++) {
    if (*i < 0 ) {
      return i;
    }
  }
  return NULL;
}

void zeroAuPremierNeg(double* t, int n) {
  double* res;
  res= adressePremierNegTabDouble(t,n);
  if (res != NULL) {
    *res=0;
  }
}

int main() {
  double t[N];
  lectureTabDouble(t,N);
  afficheTabDouble(t,N);
  zeroAuPremierNeg(t, N);
  afficheTabDouble(t,N);
}
