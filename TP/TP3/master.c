 #include <stdio.h>
 #include <stdlib.h>
#include "master.h"

 #define N 5
 #define M 7

/*
	Cette fonction calcule le nombre de pions mal places dans le tableau "test par rapport au tableau "conf"
       Elle retourne ce nombre.
	Chaque tableau comporte n elements.
	Vous avez M couleurs au maximum. Vous devez definir M.
*/

int malplace(int test[], int conf[], int n, int m) {
    int  mal = 0, i, j;

    /* Pour chaque couleur */
    for (j = 0; j < m; j++) {
        int ct = 0, cc = 0;
        /*
         * on compte le nombre de fois qu'elle apparait dans la
         * sequence a tester et dans la sequence a deviner, mais sans
         * prendre en compte les pions bien places.
         */
        for (i = 0; i < n; i++) {
            if (j == test[i] && test[i] != conf[i])
                ct++;
            if (j == conf[i] && test[i] != conf[i])
                cc++;
        }

        /*
         * Le nombre de pions mal places, pour chaque couleur, est
         * tout betement le minimum des occurences precedemment
         * recensees dans chacune des deux sequences.
         */
        mal += ct > cc ? cc : ct;
    }
    return (mal);
}

/*
 * Cette fonction initialise aleatoiremetn un tableau
 */
void init(int tab[], int n, int m) {
    int i;
    for (i = 0; i < n; i++)
        tab[i] = rand() % m;
}

/*
  Cette fonction affiche un tableau de n entiers avec la convention suivante
   0 : Rouge", 1: "Vert",2 : "Bleu", 3: "Cyan",4 : "Magenta",5: "Jaune",6 :"Blanc
*/
void affiche(int tab[], int n, int m) {
    int i;
    char* texte[]= {"Rouge","Vert","Bleu","Cyan","Magenta","Jaune","Blanc"};
    for (i = 0; i < n; i++)
        if(tab[i]<0 || tab[i]>=m) printf("Couleur inconnue");
        else printf("%s ", texte[tab[i]]);
    printf("\n");
}


void lire(int tab[], int n, int m) {
  int i, couleur;
    do{
    printf("Choisissez les couleurs aux bonnes positions %d\n");
    printf("Rouge=0 Vert=1 Bleu=2 Cyan=3 Magenta=4 Jaune=5 Blanc=6\n");
    scanf("%d %d %d %d %d",&tab[0],&tab[1],&tab[2],&tab[3],&tab[4]);
    int test=1;
    for(i=0;i<n;i++){
      if(tab[i]<0 || tab[i]>M-1){
        test=0;
        printf("Veuillez entrer des valeur entre 0 et %d\n", m-1);
    }
    }
  }while(test==0);
}



int bienplace(int machine[], int joueur[], int n)  {
  int res=0,i;
  for(i=0;i<n;i++){
    if(machine[i]==joueur[i]){
      res++;
    }
  }
  return res;
}

int main(){
  int machine[N], joueur[N], nbcoups, bp,mp;
  init(machine, N, M);
  do{
    lire(joueur, N,M);
    mp=malplace(machine, joueur, N,M);
    bp=bienplace(machine, joueur,N);
    printf("Il y a %d couleur(s) bien placée(s) et %d mal placée(s)\n",bp,mp);
  }while (bp!=N);
}
