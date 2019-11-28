#define NB_CH_LIST 10
typedef struct {
int liste[NB_CH_LIST];
int id;
int nb;
} T_playlist;

T_chanson rechercheCHANSON(
FILE* fe, int id) ;

void fprintfPlaylist(FILE* fpl, T_playlist* pl);
