#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "AllocLectureEcriture.h"
#include "Interpol.h"
#include "RotationF.h"

unsigned char ** alloueImage(int nligne, int ncol) {
  int i; unsigned char **p ;
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

void SkipComments(FILE *fp)
{
    int ch;
    char line[100];
    while ((ch = fgetc(fp)) != EOF && isspace(ch)) {
        ;
    }
    if (ch == '#') {
        fgets(line, sizeof(line), fp);
        SkipComments(fp);
    } else {
        fseek(fp, -1, SEEK_CUR);
    }
}

unsigned char ** lectureImagePgmBinaire (char* fic, int* pnbl, int* pnbc){
  FILE* fp;
  int i,j;
  int  intensite;
  char str[512];
  fp = fopen(fic,"rb");
  if (fp == NULL) puts("Ouverture impossible");
  fscanf(fp,"%[^\n]",str);
  SkipComments(fp);
  fscanf(fp,"%d %d %d\n",pnbc,pnbl,&intensite);
  if ( intensite < 0 || intensite > 255 ) { puts("Intensité non renconnue !");}
  unsigned char ** image;
  image=alloueImage(*pnbl,*pnbc);
  for(i=0;i<*pnbl;i++){
    for(j=0;j<*pnbc;j++){
      fread(image[i]+j,sizeof(image[i][j]),sizeof(image[i][j]),fp);
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
