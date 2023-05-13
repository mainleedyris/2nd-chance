/** 
* @file main.c 
* @brief Testing Program. 
* @author C Team 
* @version 0.1 
* @date Apr 01, 2015 
* 
* Testing program for background scrollilng 
* 
*/
/** 
* @file enigme.c 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
/** 
* @brief To initialize the enigme e . 
* @param e the enigme 
* @param url the url of the image 
* @return Nothing 
*/ 
void init_enigme(enigme * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;
}
/** 
* @brief To show the the enigme e. 
* @param scren the screen 
* @param e the enigme  
* @return Nothing 
*/

void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
      int test=*alea ;
      do
      {
         *alea = 1+ rand()%3;
      }while(*alea==test) ;

      sprintf(image ,"%d.png",*alea);
      e->img = IMG_Load(image);
      SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
      SDL_Flip(screen) ;
}
/** 
* @brief solution 
* @param image the char  
* @return int 
*/
int solution_e (char image [])
{
      int solution =0 ;
 	
      if(strcmp(image,"1.png")==0)
      {
            solution =1 ;
      }
      else if(strcmp(image,"2.png")==0)
      {
 	    solution =3;
      }
      else if(strcmp(image,"3.png")==0)
      {
 	   solution =3;	
      }
      return solution;
}
/** 
* @brief resolution 
* @param nothing 
* @return int 
*/
int resolutionclavier ()
{
     SDL_Event event ;
     int r=0 ;
     SDL_PollEvent(&event);
     switch(event.type)
     {

         case SDL_KEYDOWN : 
         switch( event.key.keysym.sym )
         {
	     case  SDLK_a: 
	         r= 1;
	     break ;
	     case  SDLK_z :
	         r= 2;
	     break;
	     case SDLK_e: 
		 r=3 ;
	     break;
	  }
          break ; 
              
      }
      return r ;
}
/** 
* @brief solution 
* @param scren the screen 
* @param en the enigme
* @param s the int
* @param r the int
* @return int 
*/
void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en)
{
 
     if (r==s)
     {
 	   en->img=IMG_Load("pass.jpg");
 	   SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
           SDL_Flip(screen);
     }
     else
     {
 	   en->img=IMG_Load("failed.jpg");
 	   SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
           SDL_Flip(screen);
     }
 }
/**
tache blanche
*/
void init_image(enigme * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;
}


void generate_afficher1 (SDL_Surface * screen  , char image [],enigme *e)
{ 
      
      e->img = IMG_Load("blanche1.png");
      SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
      SDL_Flip(screen) ;
}
int resolution1 ()
{
     SDL_Event event ;
     int r=0 ;
     SDL_PollEvent(&event);
     switch(event.type)
     {

         case SDL_KEYDOWN : 
         switch( event.key.keysym.sym )
         {
	     case  SDLK_c: 
	         r= 1;
	     break ;
	     case  SDLK_m :
	         r= 2;
	     break;
	  }
          break ; 
      }
      return r ;
}
int resolutionsouris ()
{
     SDL_Event event ;
     int r=0 ;
     SDL_PollEvent(&event);
     switch(event.type)
     {
          case SDL_MOUSEBUTTONDOWN:
          {
             if(event.button.x>87 && event.button.x<550 && event.button.y>227 &&event.button.y<364)
             {
                 r=1;
             }
                    
             if(event.button.x>87 && event.button.x<550 && event.button.y>475 &&event.button.y<613)
             {
                  r=2;
             }
                    
             if(event.button.x>87 && event.button.x<550 && event.button.y>704 &&event.button.y<839)
             {
                 r=3;
             } 
	   }			
	   break;
              
      }
      return r ;
}

void Enigme(SDL_Surface * screen  ){

	
	enigme  e,e1;
	int s,r,run =1,running=1,alea,i;
	char image[30]="";

	SDL_Event event;
        srand(time(NULL));


	 SDL_Init ( SDL_INIT_VIDEO ) ;



	 screen=SDL_SetVideoMode(850,662,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
	 init_enigme(&e);
	 init_image(&e1);

	 while (run)
	 {
	     running=1,r=0 ;
	     SDL_PollEvent(&event);
	   
           switch(event.type)
            {
              case SDL_QUIT:
                run = 0;
		break ;
            }
      generate_afficher1 (screen, image , &e1);
      i=resolution1 ();
if(i==1)
{
generate_afficher (screen  , image,&e,&alea);

      s=solution_e (image );
			do{
			r=resolutionclavier (&running,&run);
			}while((r>3 || r<1) && running!=0) ;


      while(running){

			afficher_resultat (screen,s,r,&e) ;
			 SDL_WaitEvent(&event);
                     switch(event.type)
                       {
					     case SDL_QUIT :
                              running =0 ;
						      run=0 ;
					     break ;
                         case SDL_KEYDOWN :

                             switch( event.key.keysym.sym )
                                  {
			                        case  SDLK_ESCAPE:
			                           running= 0 ;
			                        break ;
			                      }
						 break ;
                       }
                    }
}
else
if(i==2)
{

generate_afficher (screen  , image,&e,&alea);

      s=solution_e (image );
			do{
			r=resolutionsouris (&running,&run);
			}while((r>3 || r<1) && running!=0) ;


      while(running){

			afficher_resultat (screen,s,r,&e) ;
			if(r == s){
				running = 0;
				}
			 SDL_WaitEvent(&event);
                     switch(event.type)
                       {
					     case SDL_QUIT :
                              running =0 ;
						      run=0 ;
					     break ;
                         case SDL_KEYDOWN :

                             switch( event.key.keysym.sym )
                                  {
			                        case  SDLK_ESCAPE:
			                           running= 0 ;
			                        break ;
			                      }
						 break ;
                       }
                    }
}
}
      SDL_FreeSurface(screen);
      SDL_Quit();
	return 0;


}

