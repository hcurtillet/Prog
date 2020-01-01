#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Exo3.h"

unsigned char distance (IMAGEUCHAR im, IMAGEUCHAR modele, int is, int js){
    double res;
    int di,dj;
    for ( di = 0; di < modele.nl; di++){
        for (dj = 0; dj < modele.nc; dj++){
            res += fabs( im.val[is - (modele.nl)/2+di][js - (modele.nc)/2 + dj] - modele.val[di][dj]);
        }
    }
    res = res/(modele.nl*modele.nc);
    return (unsigned char)(res);
}
