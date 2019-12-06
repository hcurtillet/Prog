#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL_phelma.h>
#include "fractale.h"

int main() {
  int n, i=0; int nbCouple;
  printf("Saisir la valeur de profondeur n voulu:\n");
  scanf("%d",&n);
  getchar();
  unsigned int couleur ;
  SDL_PHWindow* f1=NULL;
  f1=SDL_PH_CreateWindow(1000,1000) ;
  if ( f1== NULL) { printf("Erreur SDL\n"); exit(EXIT_FAILURE);  }
  couleur=SDL_PH_RED ;


  T_coordonnees ma={500,0},mb = { 500, 250 };
  nbCouple=calcNbCouple(n);
  T_couple listeCoupe[nbCouple];
  for ( i = 0 ; i < nbCouple; i++ ) {
    (*(listeCoupe+i)).c1.x=0;
    (*(listeCoupe+i)).c1.y=0;
    (*(listeCoupe+i)).c2.x=0;
    (*(listeCoupe+i)).c2.y=0;
  }
  T_couple * couple;
  couple = listeCoupe;
  fractale(ma, mb, n, couple);
  for ( i = 0 ; i < nbCouple; i++ ) {
    lineColor(f1->rendu,(*(listeCoupe+i)).c1.x , (*(listeCoupe+i)).c1.y, (*(listeCoupe+i)).c2.x, (*(listeCoupe+i)).c2.y,couleur);
  }
  SDL_PH_FlushWindow(f1);
  puts("Taper une touche pour continuer") ; getchar() ;
  SDL_PH_DestroyWindow(f1);
  SDL_Quit();
}
