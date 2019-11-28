#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP5_1.h"
#include "TP5_2.h"

int ChaineInt(char* s) {
  int n=0, nbespace=0;
  while (*(s+n)!='\0') {
    n++;
    if (*(s+n)==' ') {
      nbespace++;
    }
  }
  return nbespace;
}

void fprintfPlaylist(FILE* fpl, T_playlist* pl){
    fseek(fpl, 0,SEEK_END);
    fwrite(pl,sizeof(pl),1,fpl);
}

int fscanfPlaylistNumber(FILE* fpl, T_playlist pl, int id){
    FILE *ftmp;

    do{
      char song[80]; int nbDeChanson;
      fscanf(fpl, "%d %[^\n]",&(pl.id),song);
      nbDeChanson=ChaineInt(song);
      ftmp=fopen("ftmp.txt", w+t);
      fprintf(ftmp,song,"%s");
      int i;
      for (i=0 ; i<nbDeChanson ; i++ ){

      }
    } while((pl.id)!=id);
}

T_chanson rechercheCHANSON(FILE* fe, int id){
  T_chanson chanson;
  fseek(fe,id*sizeof(chanson),SEEK_SET);
  fread(&chanson,sizeof(chanson),1,fe);
  return chanson;
}

int existeCHANSON(FILE* fe, int id){

}

int main(){
    FILE* playlistf, *filebin; T_chanson chanson; T_playlist playlist;
    filebin = fopen("mesmusiques.bin", "r+b");
    playlistf = fopen("mesplaylists.txt", "rt");
    chanson=rechercheCHANSON(filebin, 3212);
    printf("%d %s",chanson.id, chanson.titre);


}
