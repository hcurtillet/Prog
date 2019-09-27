#include "stdio.h"
#include "stdlib.h"

#define  DIM 30

int main (){
  float tab[5];
  int i;
  /*
  for (i=0; i<5; i++){
    printf("Entrer la %d valeur du tableau\n",i);
    scanf("%f",&tab[i]);
  }
  for (i=0; i<5; i++){
    printf("%f\n",tab[i]);
  }
  */

  float tab1[DIM], tab2[DIM], tab3[DIM];
  for (i=0; i<DIM; i++){
    tab1[i]=8*i*i+1;
    tab2[i]=-5*i-3;
  }
  for (i=0; i<DIM; i++){
    tab3[i]=tab1[i]+tab2[i];
  }
  for (i=0; i<DIM; i++){
    printf("%f(tab1[%d])+%f(tab2[%d]) = %f (tab3[%d])\n", tab1[i],i,tab2[i],i,tab3[i],i);
  }

  printf("Cherchons le minimum de tab3\n");
  float min=tab3[0];
  for (i=0;i<DIM;i++){
    if (min>=tab3[i])
      min=tab3[i];
  }
  printf("Le minimum de tab3 est %f\n", min);
  float somme=0;
  for (i=0; i<DIM; i++){
    somme += tab3[i];
  }
  printf("La somme des valeurs de tab3 est %f\n",somme);

}
