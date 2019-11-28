
/*
    Squelette des fonctions pour le tp 6 sur le son
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "son.h"


char * allouer_son(int nb_samples) {
    char* son=NULL;
    son=calloc(nb_samples,sizeof(*son));
    return son;

}


void liberer_son(  char * son) {
    free(son);
}


char* creer_sin( char amplitude, int taille, int freqsin, int freqson) {
    char * sortie;int i=0;
    sortie = allouer_son(taille);
    for(i=0; i<taille;i++){
      *(sortie+i)=(char)(amplitude*sin(2*M_PI*freqsin*i/freqson));
    }
    return sortie;
}


char* inverser( char* son, int taille) {
    char * sonInverse;int i;
    sonInverse=allouer_son(taille);
    for(i=0; i<(taille);i++){
      *(sonInverse+i)=-*(son +i);
    }
    return sonInverse;
}


char* modulation(double fe, double fmod, char* son, int taille) {
    char * modul;int i;
    modul=allouer_son(taille);
    for(i=0; i<taille;i++){
      *(modul+i)=*(son+i)*sin(2*M_PI*fmod*i/fe);
    }
    return modul;
}

char* peigne_entier(double gain, int retard, char* son, int taille) {
  /* A completer */
  return NULL;
}

char* passetout(double gain, int retard, char* son, int taille) {
  /* A completer */
  return NULL;
}

int echo( char* son, int taille, int fs, float dureeEchoSec, float attenuation, int tailleSonFinal,  char ** pson) {
  /* A completer */
  return NULL;
}
