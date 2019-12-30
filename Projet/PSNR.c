#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "PSNR.h"
#include "AllocLectureEcriture.h"
#include "Interpol.h"


double psnrImage (unsigned char** im1, unsigned char** im2, int nbl, int nbc, int i1, int j1, int i2, int j2){
  int i,j;
  double mse = 0;
  for (i=i1; i < i2; i++){
      for (j = j1; j < j2; j++){
          mse += pow(im1[i][j] - im2[i][j],2);
      }
  }
  mse = mse /( nbl * nbc );
  return 20*log10( 255 / mse );


}
