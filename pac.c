
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>





void SDL_ExitWithError(const char *message);

int main(int argc, char **args){
    /*--------------*/
    //constantes
    const char *title = "GRAVITE";
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /*-------------*/

    /*----------------------------*/
    //initialisation

    /*--------------------------*/

    //Gestion erreur
    /*window = SDL_CreateWindow("Pemiere fenetre sdl 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,800, 0);*/


    if(SDL_Init(SDL_INIT_VIDEO) !=0)
    {
          SDL_Log("Erreur : Initilisation SDL > %s\n" , SDL_GetError());
          exit(EXIT_FAILURE );
    }



    if(SDL_CreateWindowAndRenderer(800,600,0,&window, &renderer)!= 0){
        SDL_ExitWithError("CREA FENETRE ECHOUEE");
    }

    SDL_SetWindowTitle(window, title);

    if(SDL_SetRenderDrawColor(renderer, 112, 166, 237, SDL_ALPHA_OPAQUE)!=0){
        SDL_ExitWithError("pas de couleur impossible a charger hahahahahhahahahahahahaha");
    }

    if(SDL_RenderDrawPoint(renderer, 200, 400)!=0){
        SDL_ExitWithError("Impossible de dessiner un point");
    }

    if(SDL_RenderDrawLine(renderer, 50, 50, 500, 500)!=0){
        SDL_ExitWithError("Impossible de dessiner une ligne");
    }

   /********************* RECT*/
    SDL_Rect rectangle;
    rectangle.x= 300;
    rectangle.y=300;
    rectangle.w=200;
    rectangle.h=180;

    if(SDL_RenderDrawRect(renderer, &rectangle)!=0){
        SDL_ExitWithError("Impossible de dessiner une rect");
    }

 
     
    

    /*--------------------------------------------------------------------------------------------*/
    if(window==NULL){
        SDL_ExitWithError("CREA FENETRE ECHOUEE");
    }

    

  /*  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);*/

    /*------------------------------------------------------------------------*/
    if(renderer==NULL){
        SDL_ExitWithError("CREA RENDJU ECHOUEE");
    }


    if(SDL_RenderClear(renderer)!=0)
        SDL_ExitWithError("ERREUR CLEAR RENDU");

    
    /*-------------------------------------------------------*/

/**************************************************/

SDL_Surface *image = NULL;
SDL_Texture *texture = NULL;

/*************************************************/







/**************************************************/
SDL_bool program_launched = SDL_TRUE;

/*SDL_Rect rect;
 rect.x= 300;
    rect.y=300;
    rect.w=1000;
    rect.h=1880;*/

while(program_launched){

    SDL_RenderPresent(renderer);
    SDL_Event event;

    while(SDL_PollEvent(&event)){
        switch(event.type){

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_b:
                    printf("hey; \n");
                        
                        rectangle.x++;
                        rectangle.y++;
                        rectangle.w++;
                        rectangle.h++;
                         if(SDL_RenderDrawRect(renderer, &rectangle)!=0){ SDL_ExitWithError("Impossible de dessiner une rect");}
                        continue;

                default:
                    continue;
                }
            



            case SDL_QUIT:
                program_launched = SDL_FALSE;
                break;

            default:
                break;

             
        }
           
    }
   
}





/*                                                  */





    //Fin du Programme

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

   return 0 ; 
}

void SDL_ExitWithError(const char *message){
    SDL_Log("erreur : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}