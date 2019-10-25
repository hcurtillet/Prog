#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copieChainePtr(char* s, char* sCopy) {
  int n=0;
  while (*(s+n)!='\0') {
    *(sCopy+n)=*(s+n);
    n++;
  }

  *(sCopy+n)=*(s+n);
}

int main() {
    char chaine[512], chaineCopy[512];
    chaineCopy[0]='\0';
    fgets(chaine,511,stdin);
    if (chaine[strlen(chaine)-1]=='\n') {
      chaine[strlen(chaine)-1]='\0';
    }
    printf("%s\n", chaine);
    printf("%s\n", chaineCopy);
    copieChainePtr(chaine, chaineCopy);
    printf("%s\n", chaine);
    printf("%s\n", chaineCopy);
}
