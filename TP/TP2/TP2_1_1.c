#include <stdio.h>
int main(){
  int j,m,a;
  printf("Entrer une date au format jj/mm/aaaa:\n");
  scanf("%2d/%2d/%4d",&j,&m,&a);
  if(j<1 || j>31 || m>12 || m<1){printf("Format de date incorrect!\n");return 0;}
  if (j==31){
    if (m==2 || m==4 || m==6 || m==9 || m==11){printf("Le mois selectionné n'a pas 31 jours\n");return 0;}
  }
  else if (m==2){
    if (j>29){printf("Le mois de Février n'a pas %d jours\n",j); return 0;}
    else if (j==29){
      if (a%4!=0){printf("Le mois de Février n'a pas %d jours en %d\n",j,a);return 0;}
    }
  }
  printf("La date est %2d/%2d/%4d\n",j,m,a);
  if (j<30){
    if(m!=2){j++;}
    else{
      if (j==29){
        j=1;
        m++;
      }
      else if (j==28){
        if (a%4==0){
          j++;
        }
        else {
          j=1;
          m++;
        }
      }
      else{
        j++;
      }
    }
  }
  else{
    if(j==30){
      if(m==4 || m==6 || m==9 || m==11){
        j=1;
        m++;
      }
      else{
        j++;
      }
    }
    else{
      if(m==12){
        j=1;
        m=1;
        a++;
      }
      else{
        j=1;
        m++;
      }
    }
  }
    printf("Demain, on sera le %2d/%2d/%4d\n",j,m,a);

}
