#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "AllocLectureEcriture.h"
#include "Interpol.h"
#include "RotationF.h"

unsigned char ** rotationImage (unsigned char** im, double a, int ordre, int nbl, int nbc){
    int i, j;
    double x,y;
    double  ic=(nbl-1)/2;
    double jc = (nbc -1)/2;
    unsigned char ** ims;
    ims = alloueImage( nbl, nbc);
    for ( i = 0; i < nbl; i++ ) {
        for (j = 0; j < nbc; j++) {
            x = ic + (i - ic)*cos(a) - (j - jc)*sin(a);
            y = jc + (i - ic)*sin(a) + (j - jc)*cos(a);
            if (ordre == 0) {
              ims[i][j] = interpol0(im, nbl, nbc, x, y);
            }
            else if (ordre == 1 ){
              ims[i][j] = interpol1(im, nbl, nbc, x, y);
            }
            else {
              ims[i][j] = interpol2(im, nbl, nbc, x, y);
            }
        }
    }

    return ims;
}
