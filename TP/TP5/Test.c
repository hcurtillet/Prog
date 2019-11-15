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
    struct structure t;
    FILE *fichier=NULL;
    fichier= fopen("fichier.bin", "r+b");
    if(fichier != NULL)
    {
        fread(&t,sizeof(t),2,fichier);
        printf("%d %f %s",t.valeur_1, t.valeur_2, t.chain);
    }

    else
        printf("l'ouverture a echoue");
}
