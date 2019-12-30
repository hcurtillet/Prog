#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "Projet.h"


unsigned char ** alloueImage(int nligne, int ncol) {
  int i; unsigned char **p ;
  p = malloc(nligne*sizeof(*p));
  for (i = 0; i < nligne; i++) {
        p[i] = malloc(ncol*sizeof (**p));
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
    fread(image[i],sizeof(image[i][j]),*pnbc,fp);

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


unsigned char interpol0 (unsigned char** im1, int nbl, int nbc, double x, double y){
    int xres, yres; //valeur des Coordonnées retournées (x;y)
    printf("On commence avec (%lf,%lf)\n",x,y);
    double di,dj;
    int i,j;
    i=x;
    j=y;
    di = x - i;
    dj = y - j;
    printf("On a i=%d, di=%lf, j=%d et dj=%lf \n",i,di,j,dj);
    if ( di < 0.5 ){
        xres=i;
    }
    else {
        xres=i+1;
    }
    if ( dj < 0.5 ){
        yres=j;
    }
    else {
        yres=j+1;
    }
    printf("On fini avec (%d,%d)\n",xres,yres);
    if ( xres >= 0 && xres < nbl && yres >= 0 && yres < nbc ){
      printf("On fini avec (%d,%d)=%d\n",xres,yres,im1[xres][yres]);
      return im1[xres][yres];
    }
    else {
      return 0;
    }

}

unsigned char interpol1 (unsigned char** im1, int nbl, int nbc, double x, double y){
    double di,dj,r;
    int i,j;
    i=x;
    j=y;
    di = x - i;
    dj = y - j;
    printf("On a i=%d, di=%lf, j=%d et dj=%lf \n",i,di,j,dj);
    printf("On est la \n");
    if ( i < nbl -1 && i >= 0 && j < nbc -1 && j >= 0){
      printf("C1\n");
        double r1,r2;
        r1 = H((double)(im1[i][j]),(double)(im1[i][j+1]),dj);
        r2 = H((double)(im1[i+1][j]),(double)(im1[i+1][j+1]),dj);
        r= H(r1,r2,di);
    }
    else if (  i >= nbl || i < -1 || j >= nbc || j < -1 ){
      printf("C2\n");
      return 0;
    }
    else if ( i == nbl-1 ) {
      printf("C3\n");
        r=(1-dj)*im1[i][j] + dj*im1[i][j+1];
    }
    else if ( i == -1 ){
        r=(1-dj)*im1[0][j] + dj*im1[0][j+1];
    }
    else if ( j == nbc -1 ){
        r=(1-di)*im1[i][j] + (1-dj)*di*im1[i+1][j];
    }
    else if ( j == -1) {
        r=(1-di)*im1[i][0] + (1-dj)*di*im1[i+1][0];
    }
    if ( r < 0){
      return 0;
    }
    else if (r > 255 ){
      return 255;
    }
    else {
      return (unsigned char)(r);
    }


}

unsigned char H( double a, double b, double c){
   return a + (char)((double)((b-a)*c));
}

double C0(double t ) {
    return 0.5*(pow(t,3)-pow(t,2));
}

double C1(double t) {
    return -1.5*pow(t,3) + 2*pow(t,2) + 0.5*t;
}

double C2( double t ) {
    return 1.5*pow(t,3) - 2.5*pow(t,2) + 1;
}

double C3( double t ) {
    return -0.5*pow(t,3) + pow(t,2) - 0.5*t;
}

unsigned char interpol2 (unsigned char** im1, int nbl, int nbc, double x, double y) {
  double di,dj;
  int i,j;
  i=x;
  j=y;
  di = x - i;
  dj = y - j;
  printf("On a i=%d, di=%lf, j=%d et dj=%lf \n",i,di,j,dj);
  if ( i < 1 || j < 1 || i > nbl -3 || j > nbc -3 ) {
      printf("Ça va ici\n");
      return 0;
  }
  else {
      double R1,R2,R3,R4,R;
      R1 = im1[i-1][j-1]*C3(di) + im1[i][j-1]*C2(di) + im1[i+1][j-1]*C1(di) + im1[i+2][j-1]*C0(di);
      R2 = im1[i-1][j]*C3(di) + im1[i][j]*C2(di) + im1[i+1][j]*C1(di) + im1[i+2][j]*C0(di);
      R3 = im1[i-1][j+1]*C3(di) + im1[i][j+1]*C2(di) + im1[i+1][j+1]*C1(di) + im1[i+2][j+1]*C0(di);
      R4 = im1[i-1][j+2]*C3(di) + im1[i][j+2]*C2(di) + im1[i+1][j+2]*C1(di) + im1[i+2][j+2]*C0(di);
      R=R1*C3(dj) + R2*C2(dj) + R3*C1(dj) + R4*C0(dj);
      if (R > -1 && R < 256){
        return (unsigned char)(R);
      }
      else if ( R < 0){
        return 0;
      }
      else {
        return 255;
      }
  }
}

unsigned char ** rotationImage (unsigned char** im, double a, int ordre, int nbl, int nbc){
    int i, j;
    double x,y;
    double  ic=(nbl-1)/2;
    double jc = (nbc -1)/2;
    printf("On retourne\n");
    unsigned char ** ims;
    ims = alloueImage( nbl+1, nbc);
    for ( i = 0; i < nbl; i++ ) {
        for (j = 0; j < nbc; j++) {
            x = ic + (i - ic)*cos(a) - (j - jc)*sin(a);
            y = jc + (i - ic)*sin(a) + (j - jc)*cos(a);
            printf("Switch! :%d,%d \n",i,j);
            if (ordre == 0) {
              ims[i][j] = interpol0(im, nbl, nbc, x, y);
            }
            else if (ordre == 1 ){
              ims[i][j] = interpol1(im, nbl, nbc, x, y);
            }
            else {
              ims[i][j] = interpol2(im, nbl, nbc, x, y);
            }
            printf("Fin switch! (%d,%d)=%d\n",i,j,ims[i][j]);
        }
    }

    return ims;
}



int main(){
    int nbligne, nbcol,test;
    unsigned char ** image;
    unsigned char ** imr;
    image=lectureImagePgmBinaire("palmier2.pgm", &nbligne, &nbcol);
    imr=rotationImage(image,M_PI/4,1, nbligne, nbcol);
    sauvegardeImagePgmBinaire("sortie.pgm",image,nbligne,nbcol);
    sauvegardeImagePgmBinaire("sortiememe.pgm",imr,nbligne,nbcol);


}
