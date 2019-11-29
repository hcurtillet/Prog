#$@  	Le nom de la cible
#$< 	Le nom de la première dépendance
#$^ 	La liste des dépendances
#$* 	Le nom du fichier sans suffixe

DIRSDL=/users/prog1a/C/librairie/SDL2_Phelma

CFLAGS= -c -g  -I$(DIRSDL)/include  -Wall
LDFLAGS= -L$(DIRSDL)/lib -lSDL2 -lSDL2_gfx -lSDL2_ttf -lSDL2_image -lSDL2_phelma -lm -lSDL_sound

#compilateur g++
CC=clang

all: test1 test2 test3

test1: test1.o son.o 
	$(CC) -o $@ $^ $(LDFLAGS)

test2: test2.o son.o  
	$(CC) -o $@ $^ $(LDFLAGS)

test3: test3.o son.o  
	$(CC) -o $@ $^ $(LDFLAGS)




%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean :
	rm -f *.o test? 




