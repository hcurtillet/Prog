#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ** alloueMatrice(int nl, int nc){
    int **m;
    m=calloc(nl,sizeof(*m));
    *m=calloc(nl*nc,sizeof(**m));
    int i;
    for ( i = 0; i < nl-1; i++){
        m[i+1]=m[i]+nc;
    }
    return m;
}



void libereMatrice(int** m) { free(*m); free(m); }

void affiche(int ** m, int nl, int nc){
    int i,j;
    for ( i = 0; i < nl; i++ ){
        for ( j = 0; j < nc; j++ ){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}

int testeLigne(int** mat, int nl, int nc, int k){
    int * hist=calloc(nc,sizeof(int));
    int *p;
    for ( p = mat[k]; p < mat[k] + nc; p++){
        hist[*p]++;
    }
    for ( p = hist; p < hist + nc; p++){
        if (*p!=1){free(hist);return 0;}
    }
    free(hist);
    return 1;
}

int testeColonne(int** mat, int nl, int nc, int k){
    int * hist=calloc(nl,sizeof(int));
    int *p;
    for ( p = mat[0] + k; p < mat[nl-1] + k; p+=nc){
        hist[*p]++;
    }
    for ( p = hist; p < hist + nl; p++){
        if (*p!=1){free(hist);return 0;}
    }
    free(hist);
    return 1;
}

int estLatin(int** mat, int n){
    int i;
    for ( i = 0; i < n; i++){
        if ( testeLigne(mat,n,n,i) != 1 || testeColonne(mat,n,n,i)!=1){
            return 0;
        }
    }
    return 1;
}



int ** engendreCarree( int n ){
    int ** carree; int i,j;
    carree=alloueMatrice(n,n);
    for ( i = 0; i < n; i++ ){
        for ( j = 0; j < n; j++){
            carree[i][j]=(i+j)%n;
        }
    }
    return carree;

}

void sauveTexte(char* nomfic, int** mat, int n){
    FILE *fp;
    fp=fopen(nomfic,"w");
    fprintf(fp, "%d\n", n);
    int i,j;
    for ( i = 0; i < n; i++ ){
        for ( j = 0; j < n; j++ ){
            fprintf(fp,"%d",mat[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int** chargeBinaire(char* nomfic, int* pn){
    int ** carre;
    FILE * fp;
    fp=fopen(nomfic,"rb");
    if (fp == NULL){ return NULL;}
    fread(pn,1,sizeof(*pn),fp);
    printf("ici");
    carre=alloueMatrice(*pn,*pn);
    int i,j;
    for ( i = 0; i < *pn; i++){
      for ( j = 0; j < *pn; j++){
        fread(carre[i]+j,1,sizeof(carre[i][j]),fp);
      }
    }
    fclose(fp);
    return carre;
}

int** chargeCarre(char* nomfichier, int* pn) { int i,j;
FILE* fp;
int** carre;
if ( (fp=fopen(nomfichier,"rb")) == NULL) return NULL;
fread(pn,1,sizeof(*pn),fp);
if ( (carre=alloueMatrice(*pn,*pn)) == NULL) return NULL;
fread(*carre,*pn * *pn,sizeof(**carre),fp);
fclose(fp);
return carre;
}

int main (){
    int nl=4,nc=4,n;
    int ** mat;
    mat=chargeBinaire("test.txt",&n);
    affiche(mat,n,n);


}
