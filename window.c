#include "window.h"

void init(const char* title, int width, int height, Uint32 render_flags, int image_flags)
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		fprintf(stderr, "SDL coulde not initialize, SDL_ERROR: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	Win_Rend.window = SDL_CreateWindow(title, 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_SHOWN);

	if(!Win_Rend.window){
		fprintf(stderr,"Window returned null, SDL_ERROR: %s\n", SDL_GetError());
		quit();
		exit(EXIT_FAILURE);
	}

	Win_Rend.renderer = SDL_CreateRenderer(Win_Rend.window, -1, render_flags);

	if(!Win_Rend.renderer){
		fprintf(stderr, "SDL could not create renderer, SDL_Error: %s\n", SDL_GetError());
		quit();
		exit(EXIT_FAILURE);
	}

    if(!(IMG_Init(image_flags) & image_flags)){
        fprintf(stderr, "SDL_image could not be initialized! IMG_Error: %s\n", IMG_GetError());
        quit();
        exit(EXIT_FAILURE);
    }

	return;
}

void quit()
{
	SDL_DestroyRenderer(Win_Rend.renderer);
	SDL_DestroyWindow(Win_Rend.window);
	SDL_Quit();

    return;
}