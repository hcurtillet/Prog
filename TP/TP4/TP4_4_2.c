#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    char chaine[512];
    fgets(chaine,511,stdin);
    if (chaine[strlen(chaine)-1]=='\n') {
      chaine[strlen(chaine)-1]='\0';
    }
    printf("%s\n", chaine);
    printf("Le nombre d'espaces est %d\n", ChaineInt(chaine));
}
