typedef struct coordonnees{
  int x;
  int y;
} T_coordonnees;

typedef struct couple{
  T_coordonnees c1;
  T_coordonnees c2;
} T_couple;

void fractale(T_coordonnees ma, T_coordonnees mb, int n, T_couple* couple );

#define R 2/(1+sqrt(5))
#define COS cos(M_PI/4)
#define SIN sin(M_PI/4)
