#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int nombreMystere=0, nb=0, essaie=0;
    const int MAX = 1000, MIN = 0;
    srand(time(NULL));
    nombreMystere = rand() % MAX;
    do
    {
    printf("Choisi un nombre entre %d et %d\n",MIN,MAX);
    scanf("%d",&nb);
    essaie++;
    if (nb < nombreMystere)
    {
        printf("C'est plus\n\n");
    }
    else if (nb > nombreMystere)
    {
        printf("C'est moins\n\n");
    }
    else
    {
        printf("Le nombre mystere est %d \n", nb);
        printf("Trouve en %d essaie(s)\n",essaie);
    }
    } while(nb!=nombreMystere);
    return 0;
}
