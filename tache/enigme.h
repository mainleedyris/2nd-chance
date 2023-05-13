#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
/** 
* @struct Background 
* @brief struct for background 
*/
typedef struct 
{
	SDL_Surface * img;
	SDL_Rect p;
	
}enigme;

void init_enigme(enigme * e) ;
void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea) ;
int solution_e (char image []) ;
int resolution ();
void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en) ;
void Enigme(SDL_Surface * screen  );
