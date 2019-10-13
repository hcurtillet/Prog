#include <stdio.h>
void SDL_PH_DrawMasterMind(SDL_PHWindow* f1,int tab[], int nb, int taille) { int i, coul;
for (i=0; i<nb; i++) {
switch(tab[i]) {
case 0: coul=SDL_PH_RED; break; /* PH_GetPixelRed */
case 1: coul=SDL_PH_GREEN; break; /* PH_GetPixelGreen */
case 2: coul=SDL_PH_BLUE; break; /* PH_GetPixelBlue */
case 3: coul=SDL_PH_YELLOW; break;
case 4: coul=SDL_PH_MAGENTA; break;
case 5: coul=SDL_PH_CYAN; break;
default: coul=SDL_PH_BLACK; break;
}
/* un pion est represente par un cercle */
filledCircleColor (f1->rendu,i*(3*taille+1)+3*taille/2,3*taille/2,taille,coul) ;
}
/* On fait l’affichage a l’ecran */
/*Nombre de point du master mind */
#define N 7
/*Nombre de couleurs du master mind */
#define M 7
/* Taille d’un rayon d’un point. La taille d’une case est alors 3R+1 */
#define R 30
int main(int a, char** b) {
int i,j;
int t[N] ; /* Tableau representant le master mind */
SDL_PHWindow* f1=NULL;
/* initialisation du systeme video,audio de la SDL */
if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO| SDL_INIT_EVENTS) !=0) {
fprintf(stderr,"initialisation de la SDL impossible : %s\n", SDL_GetError());
exit(EXIT_FAILURE);
}
/* Creation de la fenetre d’affichage graphique */
f1=SDL_PH_CreateWindow((N)*(3*R+1)+1,3*R+3);
if ( f1==NULL) {printf("Creation de fenetre impossible \n"); exit(EXIT_FAILURE); }
/* Fenetre vide */
SDL_PH_ClearWindow(f1);
/* On dessine une grille */
SDL_PH_DrawGrid(f1,1,N,3*R+1,3*R+1,0,0);
/* Initialisation du tableau */
for (i=0; i<N; i++) t[i]=i;
/* Affichage du master mind et attente */
SDL_PH_DrawMasterMind(f1,t,N,R);
printf("Tapez une touche pour continuer \n"); getchar();
/* 5 autres masterMind affiches successivement
for (j=0; j<5; j++) {
for (i=0; i<N; i++) t[i]=rand()%M;
SDL_PH_DrawMasterMind(f1,t,N,R);
printf("Tapez une touche pour continuer \n"); getchar();
}
/* On libere la memoire utilisee*/
if (f1) SDL_PH_DestroyWindow(f1);
SDL_Quit();
exit(EXIT_SUCCESS);
}
