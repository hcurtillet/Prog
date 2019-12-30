#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <SDL2/SDL_phelma.h>
#include "AllocLectureEcriture.h"
#include "Interpol.h"
#include "RotationF.h"

int main(){
    int nbligne, nbcol;
    unsigned char ** image=NULL;
    unsigned char ** imr=NULL;
    SDL_PHWindow* f=NULL;
    char* fichier = "palmier2.pgm";

    image=lectureImagePgmBinaire(fichier, &nbligne, &nbcol);
    if (image==NULL) { printf("Erreur chargement image %s\n",fichier); exit(EXIT_FAILURE) ;
   }
    if( ( f=SDL_PH_CreateWindow(nbcol,2*nbligne)) == NULL) {
      fprintf(stderr,"Creation de fenetre impossible : %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }

    SDL_PH_DrawIm8(f,image,nbligne,nbcol,0,0);

    puts("Taper pour continuer"); getchar();

    imr=rotationImage(image,M_PI/180,1, nbligne, nbcol);
    SDL_PH_DrawIm8(f,imr,nbligne,nbcol,0,nbligne);

    puts("Taper pour continuer"); getchar();

    sauvegardeImagePgmBinaire("sortie.pgm",image,nbligne,nbcol);
    sauvegardeImagePgmBinaire("sortierot.pgm",imr,nbligne,nbcol);

    SDL_PH_DestroyWindow(f);
    SDL_Quit();
    exit(EXIT_SUCCESS);
}
