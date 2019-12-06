DIRSDL=/users/prog1a/C/librairie/SDL2_Phelma

CFLAGS= -c -g  -I$(DIRSDL)/include  -Wall
LDFLAGS= -L$(DIRSDL)/lib -lSDL2 -lSDL2_gfx -lSDL2_ttf -lSDL2_image -lSDL2_phelma -lm -lSDL_sound

programme : fractale.o programme.o
	clang $(LDFLAGS) fractale.o programme.o -o programme

fractale.o : fractale.c
	clang $(CFLAGS) fractale.c

programme.o : programme.c
	clang $(CFLAGS) programme.c
