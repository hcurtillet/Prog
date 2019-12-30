#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "AllocLectureEcriture.h"
#include "Interpol.h"
#include "RotationF.h"

unsigned char interpol0 (unsigned char** im1, int nbl, int nbc, double x, double y){
    int xres, yres; //valeur des Coordonnées retournées (x;y)
    double di,dj;
    int i,j;
    i=x;
    j=y;
    di = x - i;
    dj = y - j;
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
    if ( xres >= 0 && xres < nbl && yres >= 0 && yres < nbc ){
      return im1[xres][yres];
    }
    else {
      return 0;
    }

}

unsigned char interpol1 (unsigned char** im1, int nbl, int nbc, double x, double y){
    double di,dj;
    int i,j;
    i=x;
    j=y;
    di = x - i;
    dj = y - j;
    if ( i < nbl -1 && i >= 0 && j < nbc -1 && j >= 0){
        unsigned char r1,r2;
        r1 = H(im1[i][j],im1[i][j+1],dj);
        r2 = H(im1[i+1][j],im1[i+1][j+1],dj);
        return H(r1,r2,di);
    }
    else if (  i >= nbl || i < -1 || j >= nbc || j < -1 ){
      return 0;
    }
    else if ( i == nbl-1 ) {
        return (unsigned char)((1-dj)*im1[i][j] + dj*im1[i][j+1]);
    }
    else if ( i == -1 ){
        return((1-dj)*im1[0][j] + dj*im1[0][j+1]);
    }
    else if ( j == nbc -1 ){
        return (unsigned char)((1-di)*im1[i][j] + (1-dj)*di*im1[i+1][j]);
    }
    else if ( j==-1) {
        return (unsigned char)((1-di)*im1[i][0] + (1-dj)*di*im1[i+1][0]);
    }
    return 0;



}

unsigned char H( unsigned char a, unsigned char b, double c){
   return a + (unsigned char)((double)((b-a)*c));
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
  if ( i < 1 || j < 1 || i > nbl -3 || j > nbc -3 ) {
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
