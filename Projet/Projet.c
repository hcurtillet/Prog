#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Projet.h"


unsigned char ** alloueImage(int nligne, int ncol) {
  unsigned char i,j; unsigned char **p ;
  p = calloc(nligne,sizeof(*p));
  for (i = 0; i < nligne; i++) {
        p[i] = calloc(ncol,sizeof (**p));
  }
  return p;
}

void libereImage (unsigned char ** im, int nligne) {
    int i;
    for (i = 0; i < nligne; i++) {
        free(im[i]);
    }
    free(im);
}

unsigned char ** lectureImagePgmBinaire (char* fic, int* pnbl, int* pnbc){
  FILE* fp;
  int i,j;
  int  *intensite;
  char str[512];
  fp = fopen(fic,"rb");
  if (fp == NULL) puts("Ouverture impossible");
  fscanf(fp,"%[^\n]\n",str);
  fgets(str,511,fp);
  fscanf(fp,"%d %d %d\n",pnbc,pnbl,intensite);
  if ( *intensite < 0 || *intensite > 255 ) { puts("Intensité non renconnue !");}
  unsigned char ** image;
  image=alloueImage(*pnbl,*pnbc);
  for(i=0;i<*pnbl;i++){
    for(j=0;j<*pnbc;j++){
      fread(image[i]+j,sizeof(image[i][j]),sizeof(image[i][j]),fp);
      /*printf("Coordonnée (%d;%d):%d\n",i,j,*(image[i]+j));*/ //pour afficher les valeurs au cas où
    }
  }
  fclose(fp);
  return image;
}

void sauvegardeImagePgmBinaire(char* fic, unsigned char** im, int nbl, int nbc){
     FILE* fp;
     int i,j;
     fp = fopen(fic,"wb");
     if (fp == NULL) puts("Ouverture impossible");
     fprintf(fp, "%s\n", "P5");
     fprintf(fp,"%d %d\n%d\n", nbc,nbl,255);
     for(i=0;i<nbl;i++){
       for(j=0;j<nbc;j++){
         fwrite(im[i]+j,sizeof(im[i][j]),sizeof(im[i][j]),fp);
       }
     }
     fclose(fp);
     libereImage(im, nbl);
}
/*
unsigned char interpol0 (unsigned char** im1, int nbl, int nbc, double x, double y){
    int xres, yres; //valeur des Coordonnées retournées (x;y)
    printf("On commence");
    if ( x < nbc -1 || x >= 0) {
        if ( x - fabs(x) < 0.5 ) {
            xres = fabs (x) ;
        }
        else {
            xres = fabs(x) + 1;
        }
    }
    else if ( x < nbc -1 ){
      xres = nbc;
    }
    else {
       x = 0;
    }
    if ( y < nbl -1 || y >= 0) {
        if ( y - fabs(y) < 0.5 ) {
            yres = fabs (y) ;
        }
        else {
            yres = fabs(y) + 1;
        }
    }
    else if ( y < nbl -1 ){
      yres = nbl;
    }
    else {
       y = 0;
    }
    return im1[xres][yres];
}

unsigned char interpol1 (unsigned char** im1, int nbl, int nbc, double x, double y){
    double di,dj;
    int i,j;
    i=fabs(x);
    j=fabs(y);
    di = x - i;
    dj = y - j;
    if ( x < nbl -1 || x >= 0 || y < nbc -1 || y >= 0){
        unsigned char r1,r2;
        r1 = H(im1[i][j],im1[i][j+1],dj);
        r2 = H(im1[i+1][j],im1[i+1][j+1],dj);
        return H(r1,r2,di);
    }
    else if (  x >= nbl || x < -1 || y >= nbc || y < -1 ){
      return 0;
    }
    else if ( i == nbl - 1 ) {
        return (unsigned char)((1-dj)*im1[i][j] + dj*im1[i][j+1]);
    }
    else if ( i == -1 ){
        return (unsigned char)( (1-dj)*im1[0][j] + dj*im1[0][j+1]);
    }
    else if ( j == nbc -1 ){
        return (unsigned char)((1-di)*im1[i][j] + (1-dj)*di*im1[i+1][j]);
    }
    else if ( j == -1) {
        return (unsigned char)((1-di)*im1[i][0] + (1-dj)*di*im1[i+1][0]);
    }
    return 0;

}

unsigned char H( unsigned char a, unsigned char b, double c){
   return a + (char)((double)((b-a)*c));
}
*/
int main(){
    int nbligne, nbcol;
    unsigned char ** image;
    image=lectureImagePgmBinaire("tourtest.pgm", &nbligne, &nbcol);
    //printf("Interpolation %d",interpol0(image, nbligne, nbcol, 3.5, 4.6));
    sauvegardeImagePgmBinaire("sortie.pgm",image,nbligne,nbcol);
}
