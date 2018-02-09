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
	struct Display* Game_Display = Display_Init(title, WIDTH, HEIGHT, RENDER_FLAGS, IMG_FLAGS);
	Display_Clear(Game_Display, &ClearColor);
	Display_Present(Game_Display);
	SDL_Delay(2000);

	Display_Quit(Game_Display);
	
	exit(EXIT_SUCCESS);
}




