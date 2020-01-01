#include <stdio.h>
#include <stdlib.h>

struct structure
{
    int valeur_1;
    float valeur_2;
    char chain[8];
};
int main()
{
    char txt[255];
    FILE *fichier=NULL;
    fichier= fopen("mesplaylists.txt", "r+t");
    if(fichier != NULL)
    {
      while (fgets(txt,sizeof(txt),fichier)!=NULL) {
        fseek(fichier, -sizeof(txt),SEEK_CUR);
        fgets(txt,sizeof(txt),fichier);
        printf("%s\n",txt);
      }
    }

    else
        printf("l'ouverture a echoue");
}
