#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longueurChaineInt(char* s) {
  int n=0;
  while (*(s+n)!='\0') {
    n++;
  }
  return n;
}

int main() {
    char chaine[512];
    scanf("%[^\n]", chaine);
    printf("%s\n", chaine);
    printf("La longueur de la chaine est %d\n", longueurChaineInt(chaine));
}
