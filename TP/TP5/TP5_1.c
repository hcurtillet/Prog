#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP5_1.h"

int main() {
  FILE* filetxt, *filebin; T_chanson chanson;
  filetxt = fopen("mesmusiques.txt", "rt");
  filebin = fopen("mesmusiques.bin", "w+b");
  if (filetxt==NULL || filebin==NULL) puts("Ouverture impossible");
  else {
    int n=1;
    int oldSongId=0;
    while (1){
        oldSongId=chanson.id;
        fscanf(filetxt,"%d %[^\t] %[^\t] %[^\t] %lf ",&(chanson.id), chanson.format,chanson.titre,chanson.auteur,&(chanson.note));
        if (oldSongId==chanson.id) {
            break;
        }
        fseek(filebin,chanson.id*sizeof(chanson),SEEK_SET);
        printf("chanson n %d :%d  %s \n",n, chanson.id,chanson.titre);
        fwrite(&chanson, sizeof(chanson),5,filebin);
        n++;
    }
  }
}
