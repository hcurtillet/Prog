
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
      *(sonInverse+i)=*(son +taille - i);
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
  char * sortie;int i;
  sortie = allouer_son(taille);
  for(i=0; i<taille;i++) {
      if ( i > retard ) {
          *(sortie+i)=*(son+i)+gain*(*(son+i-retard));
      }
      else {
          *(sortie+i)=*(son+i);
      }
  }
  return sortie;
}

char* passetout(double gain, int retard, char* son, int taille) {
    char * sortie;int i;
    sortie = allouer_son(taille);
    for(i=0; i<taille;i++) {
        if ( i > retard ) {
            *(sortie+i)=-gain*(*(son+i))+*(son+i-retard)+gain*(*(sortie+i-retard));
        }
        else {
            *(sortie+i)=-gain*(*(son+i));
        }
    }
    return sortie;

}

int echo( char* son, int taille, int fs, float dureeEchoSec, float attenuation, int tailleSonFinal,  char ** pson) {
    int i=0;
    int retard = dureeEchoSec*fs;
    for ( i=0; i < taille; i++) {
      pson=allouer_son(tailleSonFinal);
      if ( i > retard ) {
          *(pson[i]+i)=*(son+i)+(char)(*(son+i-retard)*attenuation);
      }
      else {
          *(pson[i]+i)=*(son+i);
      }
    }
}
