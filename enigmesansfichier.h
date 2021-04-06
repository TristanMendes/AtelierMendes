#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

#include "enigmesansfichier.h"
#include <time.h>
#include <math.h>


typedef struct 
{
    char ques[100];
    char rp1[100];
    char rp2[100];
    char rp3[100];
    int reponse;	
}Enigme;

Enigme generer ();
void afficher_Enigme(Enigme e, SDL_Surface *screen);

#endif // HEADER_H_INCLUDED