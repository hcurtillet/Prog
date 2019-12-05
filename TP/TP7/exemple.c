#include <SDL2/SDL_phelma.h>
int main (int ac, char **av) { unsigned int couleur ;
         /* Variable permettant de manipuler une fenetre */
  SDL_PHWindow* f1=NULL;

	/* Initialisation de la bibliotheque video
       Creation d'une fenetre de dimension 300x200,
       Couleurs sur 32 bits, Fond de couleur blanche
       CRTL-C possible pour tuer le programme */
  f1=SDL_PH_CreateWindow(300,100) ;

         /* On verifie que la fenetre est ouverte ;
         sinon, arret du programme */
  if ( f1== NULL) { printf("Erreur SDL\n"); exit(EXIT_FAILURE);  }

     /* Affichage : dessiner des objets sur la fenetre f1
	Ligne noire entre les points x=10,y=0) et (x=300,y=50)
	Attention, la ligne n'est pas encore visible a l'ecran */
  couleur=SDL_PH_RED ;
  lineColor(f1->rendu,10,0,300,50,couleur);

	/* Met a jour l'ecran : la ligne apparait */
  SDL_PH_FlushWindow(f1);

	/* un getchar pour attendre, sinon le programme se termine
     		et la fenetre disparait */
  puts("Taper une touche pour continuer") ; getchar() ;
  SDL_PH_DestroyWindow(f1);
  SDL_Quit();
}
