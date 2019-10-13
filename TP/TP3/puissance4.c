#include <stdio.h>
#include <stdlib.h>


void afficher(int *tab){
  printf("  1   2   3   4   5   6   7\n");
  int i,j;
  for(i=0;i<6;i++){
  printf("-----------------------------\n");
  for(j=0;j<7;j++){
    if (tab[7*i+j]==0){
      printf("|   ");
    }
    else if(tab[7*i+j]==1){
      printf("| X ");
    }
    else{
      printf("| O ");
    }
  }
  printf("|\n");
  }
  printf("-----------------------------\n");
}

void newtab(int *tab){
  int i,j;
  for(i=0;i<6;i++){
    for(j=0;j<7;j++){
      tab[7*i+j]=0;
    }
  }
}

void play(int joueur, int *tab){
  int col,i=0;
  do {
    printf("Au tour du joueur %d\n", joueur);
    printf("Sur quelle colone voulez vous déposer votre pièce?\n");
    scanf("%d",&col);
  }
  while ( col < 1 || col > 7 );
  while(tab[7*(5-i)+col-1]!=0){
    i++;
  }
  tab[7*(5-i)+col-1]=joueur;
}

int hwin(int *tab){
  int i,j,affile;
  for(i=0;i<6;i++){
    affile=1;
    for(j=0;j<6;j++){
      if ( (tab[7*i+j] == tab[7*i+j+1]) && (tab[7*i+j] != 0) ) {
        affile++;
        if ( affile == 4 ) {
          return 1;
        }
      } else {
        affile= 1;
      }
    }
  }
  return 0;
}

int vwin(int *tab){
  int i, j, affile;
  for(j=0; j<7; j++) {
    affile=1;
    for(i=0; i<5; i++) {
      if ( (tab[7*i+j] == tab[7*(i+1)+j]) && (tab[7*i+j] != 0) ) {
        affile++;
        if ( affile == 4 ) {
          return 1;
        }
      } else {
        affile= 1;
      }
    }
  }
}

int diagDownRightWin(int *tab){
  int i=0, j=0, k=0, affile=1;
  for(i=0;i<3;i++){
    affile=1;
    for(j=0;j<4;j++){
      for(k=1; k<4; k++) {
        if ( (tab[7*i+j] == tab[7*(i+k)+j+k]) && (tab[7*i+j] != 0) ) {
          affile++;
          if ( affile == 4 ) {
            return 1;
          }
        } else {
          affile= 1;
        }
      }
    }
  }
  return 0;
}

int diagDownLeftWin(int *tab){
    int i=0, j=0, k=0, affile=1;
    for(i=0;i<3;i++){
      affile=1;
      for(j=3;j<7;j++){
        for(k=1; k<4; k++) {
          if ( (tab[7*i+j] == tab[7*(i+k)+j-k]) && (tab[7*i+j] != 0) ) {
            affile++;
            if ( affile == 4 ) {
              return 1;
            }
          } else {
            affile= 1;
          }
        }
      }
    }
    return 0;
  }

int testWin(int *tab) {
  return hwin(tab) + vwin(tab) + diagDownLeftWin(tab) + diagDownRightWin(tab);
}


int main(){
  int grille[6*7],joueur,win=0;
  newtab(grille);
  while (win==0){
    afficher(grille);
    joueur=1;
    play(joueur,grille);
    win=testWin(grille);
    if ( win != 0) {
      break;
    }
    afficher(grille);
    joueur=2;
    play(joueur,grille);
    win=testWin(grille);
  }
  afficher(grille);
  printf("Le gagnant est le joueur %d!!!\\", joueur);
}
