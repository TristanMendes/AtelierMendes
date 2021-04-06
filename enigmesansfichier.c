
#include "enigmesansfichier.h"


Enigme generer ()
{
      srand(time(NULL));
    float T,G;
    Enigme e;

    e.reponse= rand()%3;

    int a,b,i;
    float S;
    char operer[4] = "+-*/";
    i = rand()%4;
    a = rand()%101;
    b = 1+ rand()%101;


    if(i==0)
    {
        S= a+b;
        T= S+2;
        G= S-2;
        sprintf(e.ques,"quel est le resultat de cette operation: %d %c %d ",a,operer[i],b);
    }

    if(i==1)
    {
        S= a-b;
        T= S+2;
        G= S-2;
        sprintf(e.ques,"quel est le resultat de cette operation: %d %c %d ",a,operer[i],b);
    }

    if(i==2)
    {
        S= a*b;
        T= S+2;
        G= S-2;
        sprintf(e.ques,"quel est le resultat de cette operation: %d %c %d ",a,operer[i],b);
    }

    if(i==3)
    {
        S=(float)a/b;
        T= S+1;
        G= S-1;
        sprintf(e.ques,"quel est le resultat de cette operation: %d %c %d ",a,operer[i],b);
    }

    switch(e.reponse)
    {
    case 0:
        sprintf(e.rp1,"reponse 1: %0.1f\n",S);
        sprintf(e.rp2,"reponse 2: %0.1f\n",T);
        sprintf(e.rp3,"reponse 3: %0.1f\n",G);
        break;

    case 1:
        sprintf(e.rp1,"reponse 1: %0.1f\n",G);
        sprintf(e.rp2,"reponse 2: %0.1f\n",S);
        sprintf(e.rp3,"reponse 3: %0.1f\n",T);
        break;

    case 2:
        sprintf(e.rp1,"reponse 1: %0.1f\n",T);
        sprintf(e.rp2,"reponse 2: %0.1f\n",G);
        sprintf(e.rp3,"reponse 3: %0.1f\n",S);
        break;

    }
    return e;
}

void afficher_Enigme(Enigme e, SDL_Surface *screen)
{  
  SDL_Surface *fond = NULL, *Question=NULL, *resultat1, *resultat2, *resultat3, *reponvrai=NULL, *reponfaux=NULL;
    SDL_Surface *couche, *couche1;
    SDL_Event event;
    SDL_Rect positionscreen, positionQuestion, positionresultat1, positionresultat2, positionresultat3, positionvrai, positionfaux, positionrep;
    TTF_Font *police = NULL;
    int choix;
    int continuer = 1; 
    SDL_Color couleurNoir= {0,0,0};
    SDL_Init(SDL_INIT_VIDEO);



    if(TTF_Init() == -1)
{
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
}
    screen = SDL_SetVideoMode(900,800,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    
    SDL_WM_SetCaption("ENIGME ", NULL);
    
    fond = IMG_Load("fond3.jpg");

    couche= IMG_Load("1.png");
    couche1= IMG_Load("2.png");

  
    /* chargement de la police */
    police = TTF_OpenFont("Stay and Shine.ttf", 35);
    /*ecriture du texte dans la SDL_Surface texte en mode blender (optimal)*/
    TTF_SetFontStyle(police, TTF_STYLE_BOLD);
    /* Écriture du texte en italique */

    Question = TTF_RenderText_Blended(police,e.ques,couleurNoir);
    resultat1= TTF_RenderText_Blended(police,e.rp1,couleurNoir);
    resultat2= TTF_RenderText_Blended(police,e.rp2,couleurNoir);
    resultat3= TTF_RenderText_Blended(police,e.rp3,couleurNoir);
   


        positionscreen.x = 0;
        positionscreen.y = 0;
       

        positionQuestion.x = 10;
        positionQuestion.y = 100;

        positionresultat1.x = 70;
        positionresultat1.y = 200;

        positionresultat2.x = 70;
        positionresultat2.y = 300;

        positionresultat3.x = 70;
        positionresultat3.y = 400;

        positionvrai.x =270;
      

        positionfaux.x = 270;
        


        

        switch(e.reponse)
        {
            case 0:
            positionvrai.y= positionresultat1.y;
            break;
            case 1:
            positionvrai.y= positionresultat2.y;
            break;
            case 2:
            positionvrai.y= positionresultat3.y;
            break;
        }
        SDL_BlitSurface(fond, NULL, screen, &positionscreen);
        SDL_BlitSurface(Question, NULL, screen, &positionQuestion); /*Blit du texte*/
        SDL_BlitSurface(resultat1, NULL, screen, &positionresultat1);
        SDL_BlitSurface(resultat2, NULL, screen, &positionresultat2);
        SDL_BlitSurface(resultat3, NULL, screen, &positionresultat3);
        SDL_Flip(screen);


    while(continuer)
    {
          SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;

                case SDL_KEYDOWN:
                     switch(event.key.keysym.sym)
                     {
                        case SDLK_KP1:
                        choix =0;
                        positionfaux.y = positionresultat1.y;
                        if(choix==e.reponse)
                        {
                            positionrep= positionvrai;
                            //SDL_BlitSurface(couche, NULL, screen, &positionrep);
                            //SDL_Flip(screen);
                        }

                        else{
                            positionrep= positionfaux;
                            //SDL_BlitSurface(couche1, NULL, screen, &positionrep);
                            //SDL_Flip(screen);
                        }
                        continuer=0;
                        break;
                        
                        case SDLK_KP2:
                        choix =1;
                        positionfaux.y= positionresultat2.y;
                        if(choix==e.reponse)
                        {
                            positionrep= positionvrai;
                             SDL_BlitSurface(couche, NULL, screen, &positionrep);
                             //SDL_Flip(screen);
                        }

                        else{
                            positionrep= positionfaux;
                            //SDL_BlitSurface(couche1, NULL, screen, &positionrep);
                            //SDL_Flip(screen);
                        }
                           continuer=0;
                        break;

                        case SDLK_KP3:
                        choix =2;
                        positionfaux.y= positionresultat3.y;
                        if(choix==e.reponse)
                        {
                            positionrep= positionvrai;
                           // SDL_BlitSurface(couche, NULL, screen, &positionrep);
                              //SDL_Flip(screen);
                        }
                        else{
                            positionrep= positionfaux;
                            //SDL_BlitSurface(couche1, NULL, screen, &positionrep);
                         //SDL_Flip(screen);
                        }
                           continuer=0;
                        break;
                     }
        }

        //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,225, 255,255));

         

    }
        SDL_BlitSurface(fond, NULL, screen, &positionscreen); /*Blit du fond*/

        SDL_BlitSurface(Question, NULL, screen, &positionQuestion); /*Blit du texte*/
        SDL_BlitSurface(resultat1, NULL, screen, &positionresultat1);
        SDL_BlitSurface(resultat2, NULL, screen, &positionresultat2);
        SDL_BlitSurface(resultat3, NULL, screen, &positionresultat3);
        if(choix==e.reponse)
               SDL_BlitSurface(couche, NULL, screen, &positionrep);
          else
             SDL_BlitSurface(couche1, NULL, screen, &positionrep);  
              

        SDL_Flip(screen);
        SDL_Delay(3000);

   TTF_CloseFont(police);//
   TTF_Quit();

   SDL_FreeSurface(Question);
   SDL_FreeSurface(resultat1);
   SDL_FreeSurface(resultat2);
   SDL_FreeSurface(resultat3);
   SDL_Quit();
    
      
}
