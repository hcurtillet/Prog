#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL_phelma.h>
#include "son.h"

int main(int argc, char * argv[]) {
    /* Les tableaux contenant les donnees */
    char* son=NULL;
    char* son2=NULL;
    /* Le nom du fichier contenant le son */
//    char wavfile[] = "sons/DRUMS1_8bits.wav";
    char wavfile[] = "sons/johnny.wav";
    int nb_samples, fd, amplitude=100, fs;

    int i=0;
    /* La variable manipulant la fenetre graphique */
    SDL_PHWindow* f=NULL;

    puts("Ecouter le son initial: tapez une touche");  getchar();
    /* Jouer le son contenu dans le fichier*/
    SDL_PH_PlaySoundWav(wavfile);

    /* Charger un fichier son dans un tableau */
    if ( (son = SDL_PH_GetCreateWavS8(wavfile,&fs,&nb_samples))==NULL) {
      fprintf(stderr, "Erreur ouverture %s\n", wavfile);
      exit(EXIT_FAILURE);
    }

    /* afficher ses caracteristiques et l'ecouter*/
    printf("le fichier %s a %d echantillons et une frequence d'echantillonage de %d\n", wavfile, nb_samples, fs);
    puts("Ecouter le son recupere: tapez une touche"); getchar();

    /* Creer une fenetre pour l'affichage graphique */
    f=SDL_PH_CreateWindow(800,400);
    /* Ecouter et afficher le trace si la fenetre existe */
    if (f) SDL_PH_PlayDrawSoundS8(son, nb_samples, fs, f, SDL_PH_RED);
    else SDL_PH_PlaySoundS8(son, nb_samples, fs);

    /* Creer  un train de DiracÂ : meme nombre dâ€™echantillons frequence d'echantillonnage Ã  44100Hz train Ã  441 Hz*/
    fs = 44100;
    fd = fs/100;
    son2 = allouer_son(nb_samples);
    for(i=0; i<nb_samples; i++)
        son2[i] =  ((i%fd)==0)*amplitude;
    printf("Signal en peigne de Dirac Ã  %d Hz: tapez une touche\n",fd);
    getchar();
    /* Ecouter ce train de dirac et l'affciher si possible */
    if (f) { SDL_PH_ClearWindow(f);
        SDL_PH_PlayDrawSoundS8(son2, nb_samples, fs, f, SDL_PH_RED);
    }
    else  SDL_PH_PlaySoundS8(son2, nb_samples, fs);
    /* liberer la memoire */
    liberer_son(son2);

    /* Ecouter un signal continuÂ : meme nombre dâ€™echantillons*/
    son2 = allouer_son(nb_samples);
    for(i=0; i<nb_samples; i++)
        son2[i] = amplitude;
    puts("Signal continu: tapez une touche");   getchar();
    /* Ecouter et visualiser le signal continu */
    if (f) {  SDL_PH_ClearWindow(f);
        SDL_PH_PlayDrawSoundS8(son2, nb_samples, fs, f, SDL_PH_RED);
    }
    else  SDL_PH_PlaySoundS8(son2, nb_samples, fs);

    /* Liberer la memoire */
    liberer_son(son2);
    liberer_son(son);
    if (f) SDL_PH_DestroyWindow(f);
    return EXIT_SUCCESS;
}
