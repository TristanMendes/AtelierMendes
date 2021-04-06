
#include <stdlib.h>
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigmesansfichier.h"

int main()
{
	SDL_Surface *screen=NULL;
	
Enigme e; 
e = generer();
  afficher_Enigme(e,screen);


}
