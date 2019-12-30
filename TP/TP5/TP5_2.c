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
    while (feof(fpl)==0) {
      fscanf(fpl,"%d",&(pl.id));
      if ((pl.id)== id){
          break;
      }
      else {
          char str[100];
          fgets(str,sizeof(str),fpl);

      }
    }
    if ((pl.id) != id){
        printf("La playliste n'existe pas");
        return 0;
    }
    fscanf(fpl,"%d",&(pl.nb));
    int i;
    for ( i = 0; i < pl.nb; i++){
        fscanf(fpl, "%d", &(pl.liste[i]));
    }
    T_chanson chanson;
    FILE * filebin;
    filebin = fopen("mesmusiques.bin", "r+b");
    printf("La playlist numéro %d existe et contient %d chanson(s) qui sont:\n",pl.id,pl.nb);
    for ( i = 0; i < pl.nb; i++){
      chanson=rechercheCHANSON(filebin, pl.liste[i]);
      printf("%d %s\n",pl.liste[i], chanson.titre);
    }

    return 1;

}

T_chanson rechercheCHANSON(FILE* fe, int id){
  T_chanson chanson;
  fseek(fe,id*sizeof(chanson),SEEK_SET);
  fread(&chanson,sizeof(chanson),1,fe);
  return chanson;
}


int fdeletePlaylistNumber (char* fichier_playliste, int id){
    FILE* fpl; T_playlist pl;
    fpl = fopen("mesplaylists.txt", "rt");
    if (fscanfPlaylistNumber(fpl, pl, id) == 0){
        return 0;
    }
    FILE *playlisttmp;
    playlisttmp = fopen("Mesplaylists.tmp","wt");
    if (playlisttmp == NULL) puts("Ouverture impossible");
    int oldid=NULL;
    while (1) {
      fscanf(fpl,"%d",&(pl.id));
      if ((pl.id)== id){
          char str[100];
          fgets(str,sizeof(str),fpl);
      }
      else if (pl.id == oldid) {
          break;
      }
      else{
        oldid=pl.id;
      fprintf(playlisttmp, "%d",pl.id);
      fscanf(fpl,"%d",&(pl.nb));
      fprintf(playlisttmp, " %d",pl.nb);
      printf("%d %d\n",pl.id,pl.nb);
      int i;
      for ( i = 0; i < pl.nb; i++){
          fscanf(fpl, "%d", &(pl.liste[i]));
          fprintf(playlisttmp, " %d",pl.liste[i]);
      }
      fprintf(playlisttmp, "\n");
      fseek(fpl,1,SEEK_CUR);
      }

    }
    fclose(fpl);
    fclose(playlisttmp);

    return 1;
}


int main(){
    /*
    FILE* playlistf, *filebin; T_chanson chanson; T_playlist playlist;
    filebin = fopen("mesmusiques.bin", "r+b");
    playlistf = fopen("mesplaylists.txt", "rt");
    chanson=rechercheCHANSON(filebin, 8);
    printf("%d %s\n",chanson.id, chanson.titre);
    int res;
    fclose(filebin);
    fclose(playlistf);
    */
    int res;
    res = fdeletePlaylistNumber("test.txt",5);


}
