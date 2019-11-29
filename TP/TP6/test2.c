#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL_phelma.h>
#include "son.h"
//#include <SDL2/SDL_sound.h>

int main(int argc, char * argv[]) { int fs, nb_samples;
    char *son=NULL;
    char *son2=NULL;
    char *wavfile ;
    SDL_PHWindow* f;;

    if (argc !=2) { fprintf(stderr, "Usage : %s son.wav\n", argv[0] ); exit(EXIT_FAILURE);}

    wavfile=argv[1];
    /* chargement du son */
    if ( (son = SDL_PH_GetCreateWavS8(wavfile,&fs,&nb_samples))==NULL) {
      fprintf(stderr, "Erreur ouverture %s\n", wavfile);
      exit(EXIT_FAILURE);
    }
    printf("Ecouter le son intial : tapez une touche\n");
    getchar();
    if ((f=SDL_PH_CreateWindow(800,400))==NULL) {
      fprintf(stderr, "%s\n","Creation de fenetre impossible");
    }
    if (f) SDL_PH_PlayDrawSoundS8(son, nb_samples, fs, f, SDL_PH_RED);
    else SDL_PH_PlaySoundS8(son, nb_samples, fs);

    printf("Ecouter le son inverser : tapez une touche\n"); getchar();
    son2=inverser(son,nb_samples);
    if (f) SDL_PH_PlayDrawSoundS8(son2, nb_samples, fs, f, SDL_PH_BLUE);
    else SDL_PH_PlaySoundS8(son2, nb_samples, fs);

    printf("Appuyer sur Entrée pour quitter le programme\n");
    getchar();

    liberer_son(son);
    liberer_son(son2);
    if (f) SDL_PH_DestroyWindow(f);
    return EXIT_SUCCESS;
}
