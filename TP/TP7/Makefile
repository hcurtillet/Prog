CFLAGS=-c -g -Wall

LDFLAGS=-lm

programme : fractale.o programme.o
	clang $(LDFLAGS) fractale.o programme.o -o programme

fractale.o : fractale.c
	clang $(CFLAGS) fractale.c

programme.o : programme.c
	clang $(CFLAGS) programme.c
