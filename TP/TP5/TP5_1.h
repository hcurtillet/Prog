#define MAX_CHAINE 80
#define MAX_FORMAT 12
typedef struct chanson {
int id;
char format[MAX_FORMAT];
double note;
char titre[MAX_CHAINE];
char auteur[MAX_CHAINE]; } T_chanson;
