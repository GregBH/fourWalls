#include "window.h"
#include "sprite.h"
#include "character.h"

#define FPS  60
#define FRAME_DELAY  1000/FPS

const char* title 	= "SDL_C";
const int WIDTH 	= 1280;
const int HEIGHT 	= 768;
Uint32 RENDER_FLAGS = (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
int IMG_FLAGS 		= IMG_INIT_PNG;
SDL_Color ClearColor = {0xff, 0xff, 0xff, 0xff};

Uint32 frameStart;
int frameTime;


int main()
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		fprintf(stderr, "SDL coulde not initialize, SDL_ERROR: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	struct Display* Game_Display = Display_Init(title, WIDTH, HEIGHT, RENDER_FLAGS, IMG_FLAGS);
	SDL_bool done = SDL_FALSE;
	SDL_Event event;
	struct Character* player = Character_Create(Game_Display->renderer, 0, 0, 64, 64, "res/placeholder_sprite.png");

	while(Game_Display->display_close != SDL_TRUE){

		frameStart = SDL_GetTicks();

		if(SDL_PollEvent(&event)){
			Character_PollEvents(player, &event);
			Display_PollEvents(Game_Display, &event);
		}

		Character_Update(player);
		Display_Clear(Game_Display, &ClearColor);
		Character_Draw(player, Game_Display->renderer);
		Display_Present(Game_Display);

		frameTime = SDL_GetTicks() - frameStart;
		if(FRAME_DELAY > frameTime){
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	
	} 
	Display_Quit(Game_Display);

	SDL_Quit();
	
	exit(EXIT_SUCCESS);
}




