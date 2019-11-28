#ifndef _SON_H_
#define _SON_H_

/*
Ce fichier definit les prototypes des fonctions de manipulation des sons
*/

char * allouer_son(int nb_samples);

void liberer_son(  char * son);

char* creer_sin( char amplitude, int taille, int freqsin, int freqson);

char* inverser( char* son, int taille);

char* modulation(double fe, double fmod, char* son, int taille) ;

char* peigne(double gain, int retard, char* son, int taille);

char* passetout(double gain, int retard, char* son, int taille);

/// Partie optionnelle

char* flanging(double gain, char* son, int taille, int fe) ;

int echo( char* son, int taille, int fs, float dureeEchoSec, float attenuation, int tailleSonFinal,  char ** pson);


#endif
