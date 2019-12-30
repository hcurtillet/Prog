DIRSDL=/users/prog1a/C/librairie/SDL2_Phelma

CFLAGS= -c -g  -I$(DIRSDL)/include  -Wall
LDFLAGS= -L$(DIRSDL)/lib -lSDL2 -lSDL2_gfx -lSDL2_ttf -lSDL2_image -lSDL2_phelma -lm -lSDL_sound

programmeR : Rotation.o RotationF.o Interpol.o AllocLectureEcriture.o
	clang $(LDFLAGS) Rotation.o RotationF.o Interpol.o AllocLectureEcriture.o -o programmeR

programmeZ : Zoom.o ZoomF.o Interpol.o AllocLectureEcriture.o
	clang $(LDFLAGS) Zoom.o ZoomF.o Interpol.o AllocLectureEcriture.o -o programmeZ

programmeQ : Qualite.o PSNR.o RotationF.o Interpol.o AllocLectureEcriture.o
	clang $(LDFLAGS) Qualite.o PSNR.o RotationF.o Interpol.o AllocLectureEcriture.o -o programmeQ

Rotation.o : Rotation.c
	clang $(CFLAGS) Rotation.c

Qualite.o : Qualite.c
	clang $(CFLAGS) Qualite.c

Zoom.o : Zoom.c
	clang $(CFLAGS)	Zoom.c

RotationF.o : RotationF.c
	clang $(CFLAGS) RotationF.c

ZoomF.o : ZoomF.c
	clang $(CFLAGS) ZoomF.c

PSNR.o : PSNR.c
	clang $(CFLAGS) PSNR.c

Interpol.o : Interpol.c
	clang $(CFLAGS) Interpol.c

AllocLectureEcriture.o : AllocLectureEcriture.c
	clang $(CFLAGS) AllocLectureEcriture.c
