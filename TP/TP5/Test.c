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
    struct structure t={12, 13.23, "bonjour"};
    FILE *fichier=NULL;
    fichier= fopen("fichier.bin", "w+b");
    if(fichier != NULL)
    {
        fwrite(&t,sizeof(t),1,fichier);
        fseek(fichier, sizeof(t), SEEK_SET);
        fwrite(&t,sizeof(t),1,fichier);
    }

    else
        printf("l'ouverture a echoue");
}
