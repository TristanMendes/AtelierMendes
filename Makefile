programme:main.o  enigmesansfichier.o
	gcc  main.o enigmesansfichier.o -o programme -lSDL  -lSDL_image  -lSDL_ttf -g
main.o:main.c
	gcc -c main.c  -lSDL -lSDL_image -lSDL_ttf  -g
enigmesansfichier.o:enigmesansfichier.c
	gcc -c enigmesansfichier.c -lSDL -lSDL_image  -lSDL_ttf -g

