#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "PSNR.h"
#include "AllocLectureEcriture.h"
#include "Interpol.h"
#include "RotationF.h"

int main(){
    int nbligne, nbcol;
    unsigned char ** image=NULL;
    unsigned char ** imr=NULL;
    char * fichier = "palmier2.pgm";
    image = lectureImagePgmBinaire(fichier, &nbligne, &nbcol);
    if (image==NULL) { printf("Erreur chargement image %s\n",fichier); exit(EXIT_FAILURE) ;
    }
    int i;
    for (i = 0; i<4; i++){
        if ( i != 2) {
           imr=rotationImage(image,1*M_PI/180,i, nbligne, nbcol);
           if (image==NULL) { printf("Erreur toration d'image\n"); exit(EXIT_FAILURE);}
           double psnr;
           psnr = psnrImage(image, imr, nbligne, nbcol, 10, 10, nbligne-10, nbcol-10);
           printf("Le psnr avec une rotation de 1 est de %lf pour une interpolation d'ordre %d\n", psnr, i);
        }
    }
    for (i = 0; i<4; i++){
        if ( i != 2) {
           imr=rotationImage(image,-1*M_PI/180,i, nbligne, nbcol);
           if (image==NULL) { printf("Erreur toration d'image\n"); exit(EXIT_FAILURE);}
           double psnr;
           psnr = psnrImage(image, imr, nbligne, nbcol, 10, 10, nbligne-10, nbcol-10);
           printf("Le psnr avec une rotation de -1 est de %lf pour une interpolation d'ordre %d\n", psnr, i);
        }
    }

    libereImage(image, nbligne);
    libereImage(imr, nbligne);


}
