

unsigned char ** alloueImage(int nligne, int ncol);

void libereImage (unsigned char ** im, int nligne);

void SkipComments(FILE *fp);

unsigned char ** lectureImagePgmBinaire (char* fic, int* pnbl, int* pnbc);

void sauvegardeImagePgmBinaire(char* fic, unsigned char** im, int nbl, int nbc);
