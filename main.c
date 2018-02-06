#include "window.h"
#include "sprite.h"
#include "character.h"

const char* title 	= "SDL_C";
const int WIDTH 	= 1280;
const int HEIGHT 	= 768;
Uint32 RENDER_FLAGS = (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
int IMG_FLAGS 		= IMG_INIT_PNG;

void drawfloor(struct Sprite*);

int main()
{

	init(title, WIDTH, HEIGHT, RENDER_FLAGS, IMG_FLAGS);
	SDL_Event event;
	SDL_bool done = SDL_FALSE;
	struct Sprite* floor = CreateSprite(0, 0, 64, 64, "./res/floor_boards.png");
	struct Sprite* fridge = CreateSprite(0,0,64,128, "./res/fridge.png");
	struct Character* rando = CreateCharacter(256, 256, 64, 64, " ");

	while(!done){
		if(Win_Rend.renderer == 0){
			done = SDL_TRUE;
			break;
		}
		if(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					done = SDL_TRUE;
					break;
			}
			PollKeyEvents(rando, &event);
			Movement(rando);
		}

		SDL_SetRenderDrawColor(Win_Rend.renderer, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderClear(Win_Rend.renderer);
		drawfloor(floor);
		DrawSprite(fridge, Win_Rend.renderer);
		DrawCharacter(rando);
		SDL_RenderPresent(Win_Rend.renderer);
	}

	FreeSprite(floor);
	floor = NULL;

	quit();
	exit(EXIT_SUCCESS);
}

void drawfloor(struct Sprite* sprite)
{
	int x_grid_size = (WIDTH / sprite->w);
	int y_grid_size = (HEIGHT / sprite->h);

	for(int i = 0; i <= y_grid_size; i++){
		for(int j = 0; j < x_grid_size; j++){
			sprite->x = sprite->w * j;
			DrawSprite(sprite, Win_Rend.renderer);
		}
		sprite->x = 0;
		sprite->y = sprite->h * i;
	}

	sprite->y = 0;

	return;
}



