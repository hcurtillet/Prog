#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

unsigned char ** alloueImage(int nligne, int ncol) {
  unsigned char i,j; unsigned char **p ;
  p = calloc(nligne,sizeof(*p));
  for (i = 0; i < nligne; i++) {
        p[i] = calloc(ncol,sizeof (**p));
  }
  return p;
}

int main() {
  printf("Nom du fichier?\n");
  char *fic;
  scanf("%s",fic);
  FILE* fp,*fs; int i,j;
  char str[512];
  fp = fopen(fic,"rb");
  fs = fopen("test.pgm","wb");
  if (fp == NULL) puts("Ouverture impossible");
  fgets(str,3,fp);
  if(strcmp(str,"P5")==0){printf("Ça fonctionne\n");}
  printf("%s\n",str);
  printf("on écrit\n");
  fprintf(fs,"%s\n",str);
  fgets(str,511,fp);
  fgets(str,511,fp);
  printf("On a un comm:%s\n",str);
  fprintf(fs,"%s",str);
  unsigned nbligne, nbcol,inten;
  fscanf(fp,"%d %d %d\n",&nbcol,&nbligne,&inten);
  printf("%d %d %d\n", nbcol,nbligne,inten);
  fprintf(fs,"%d %d\n%d\n", nbcol,nbligne,inten);
  unsigned char ** image;
  unsigned char ** image2;
  image=alloueImage(nbligne,nbcol);
  for(i=0;i<nbligne;i++){
    for(j=0;j<nbcol;j++){
      fread(image[i]+j,sizeof(image[i][j]),sizeof(image[i][j]),fp);
      printf("Coordonnée (%d;%d):%c\n",i,j,*(image[i]+j));
    }
  }
  for(i=0;i<nbligne;i++){
    for(j=0;j<nbcol;j++){
      fwrite(image[i]+j,sizeof(image[i][j]),sizeof(image[i][j]),fs);
    }
  }
  fclose(fp);
  fclose(fs);
}

/* ICI TOUTES LES FOLIES INFORMATIQUES SONT PERMISES */
