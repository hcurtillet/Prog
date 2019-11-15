#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP5_1.h"
#include "TP5_2.h"

T_chanson rechercheCHANSON(FILE* fe, int id){
  T_chanson chanson;
  fseek(fe,id*sizeof(chanson),SEEK_SET);
  fread(&chanson,sizeof(chanson),1,fe);
  return chanson;
}

int main(){
    FILE* playlistf, *filebin; T_chanson chanson; T_playlist playlist;
    filebin = fopen("mesmusiques.bin", "r+b");
    playlistf = fopen("mesplaylists.txt", "rt");
    chanson=rechercheCHANSON(filebin, 3212);
    printf("%d %s",chanson.id, chanson.titre);


}
