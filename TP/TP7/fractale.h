typedef struct coordonnee{
  double x;
  double y;
} T_coordonnees;

void fractale(T_coordonnees ma, T_coordonnees mb,int n);

#define R 2/(1+sqrt(5))
#define COS cos(M_PI/4)
#define SIN sin(M_PI/4)
