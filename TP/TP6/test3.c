#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL_phelma.h>
#include "son.h"


int main(int argc, char * argv[]) {
    char *son=NULL;
    char *son1=NULL;

    char* wavfile1 = argv[1];
    int  freq1,taille1;

    if (argc!=3) { fprintf(stderr, "Usage : %s son.wav son2.wav\n",argv[0] ); exit(EXIT_FAILURE);}
    SDL_PHWindow* f = SDL_PH_CreateWindow(800,400);

    printf("Ecouter le 1er son : tapez une touche\n");
    getchar();
    son1 = SDL_PH_GetCreateWavS8(wavfile1, &freq1, &taille1);
    if (f) SDL_PH_PlayDrawSoundS8(son1, taille1, freq1, f, SDL_PH_RED);
    else SDL_PH_PlaySoundS8(son1, taille1, freq1);

    /* Modulation */
    //printf("Ecouter la modulation du premier signal : appuyez sur une touche\n");
    //getchar();
    //son = modulation(freq1, 10, son1, taille1);

    //printf("Ecouter un filtre en peigne du premier signal : appuyez sur une touche\n");
    //getchar();
    //son = peigne_entier(1-pow(10,-3.0*171/1000.), 171, son1, taille1);

    //printf("Ecouter un filtre dephaseur du premier signal : appuyez sur une touche\n");
    //getchar();
    //son = passetout(0.95,1000, son1, taille1);

    printf("Son filtre\n");
    getchar();
    if (f) SDL_PH_PlayDrawSoundS8(son, taille1, freq1, f, SDL_PH_GREEN);
    else SDL_PH_PlaySoundS8(son, taille1, freq1);
    getchar();
    liberer_son(son);


    /* Echo */
    int taille;
    taille = taille1 * 1.5;
    double dureeEcho = 0.5;
    double attenuationEcho = 0.5;
    printf("Ecouter un echo pas beau de %lf secondes, decroissance %lf sur le 1er son : appuyez sur une touche\n",
           dureeEcho, attenuationEcho);
    getchar();

    int res = echo(son1,taille1, freq1, dureeEcho, attenuationEcho, taille, &son);
    if(res == 0) {
        if (f) {
            SDL_PH_ClearWindow(f);
            SDL_PH_PlayDrawSoundS8(son, taille, freq1, f, SDL_PH_MAGENTA);
        }
        else SDL_PH_PlaySoundS8(son, taille, freq1);
        liberer_son(son);
    } else {
        printf("une erreur s'est produite dans le calcul de l'écho : erreur %d\n", res);
    }
    getchar();
    liberer_son(son1);
    if (f) SDL_PH_DestroyWindow(f);
    return EXIT_SUCCESS;
}
