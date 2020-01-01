#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Exo3.h"

PIXEL ** alloueMemoirePixel (int nbLigne, int nbColonne){
    PIXEL ** image;
    image= calloc(nbLigne,sizeof(*image));
    if (image == NULL){return NULL;}
    int i;
    for (i = 0; i < nbLigne; i++){
        image[i]=calloc(nbColonne, 1);
        if (image[i]== NULL){return NULL;}
    }
    return image;
}

IMAGEUCHAR creationImageUChar( int nbLigne, int nbColonne) {
    IMAGEUCHAR imch;
    imch.val=alloueMemoirePixel(nbLigne, nbColonne);
    if (imch.val == NULL){
        imch.nl=0;
        imch.nc=0;
    }
    else{
        imch.nl=nbLigne;
        imch.nc=nbColonne;
    }
    return imch;
}

int estVideImageUChar ( IMAGEUCHAR im){
    if( im.nl > 0 && im.nc > 0){
        return 0;
    }
    else{
        return 1;
    }
}

void setImageUChar (IMAGEUCHAR im, PIXEL valeur){
    int i,j;
    for ( i = 0; i < im.nl; i++){
        for (j = 0; j < im.nc; j++){
            im.val[i][j]= valeur;
        }
    }
}

void afficherImageUChar( IMAGEUCHAR im){
    int i, j;
    printf("On affiche l'image de %d lignes et %d colonnes:\n",im.nl,im.nc);
    for ( i = 0; i < im.nl; i++){
        for (j = 0; j < im.nc; j++){
            printf("%d ", im.val[i][j]);
        }
        printf("\n");
    }

}

void libereImageUChar( IMAGEUCHAR * pim){
    if (pim->nl > 0 && pim->nc > 0){
        int i;
        for (i = 0; i < pim->nl; i++){
            free(pim->val[i]);
        }
        free(pim->val);
        pim->nl=0;
        pim->nc=0;
    }
}

int egalTableauUChar( PIXEL * t1, PIXEL * t2, int nbOctet){
    PIXEL *p1, *p2;
    p1=t1;
    p2=t2;
    for ( p1=t1; p1 < t1+nbOctet; p1++){
        if (*p1 != *p2){ return 0;}
        p2++;
    }
    return 1;
}

int egalImageUChar( IMAGEUCHAR im1, IMAGEUCHAR im2){
    if (im1.nc == im2.nc && im1.nl == im2.nl){
        int i;
        for (i = 0; i < im1.nl; i++){
            if (egalTableauUChar(im1.val[i], im2.val[i], im1.nc) == 0 ){
                return 0;
            }
        }
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int nbLigne, nbColonne;
    nbLigne = 2;
    nbColonne = 3;
    IMAGEUCHAR im,im2;
    im = creationImageUChar(nbLigne, nbColonne);
    im2 = creationImageUChar(nbLigne, nbColonne);
    afficherImageUChar(im);
    PIXEL val=125;
    printf("On initialise les valeurs de l'image à %d\n",val);
    setImageUChar(im, val);
    afficherImageUChar(im);
    setImageUChar(im2,val);
    im2.val[1][2]=9;
    afficherImageUChar(im2);
    printf("Images égales?\n %d \n",egalImageUChar(im,im2));
}
