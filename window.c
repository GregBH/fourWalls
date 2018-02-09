#include "window.h"

struct Display* Display_Init(const char* title, int width, int height, Uint32 render_flags, int image_flags)
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		fprintf(stderr, "SDL coulde not initialize, SDL_ERROR: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	struct Display* tmpDisplay = (struct Display*)malloc(sizeof(struct Display));

	tmpDisplay->window = SDL_CreateWindow(title, 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_SHOWN);

	if(!tmpDisplay->window){
		fprintf(stderr,"Window returned null, SDL_ERROR: %s\n", SDL_GetError());
		Display_Quit(tmpDisplay);
		exit(EXIT_FAILURE);
	}

	tmpDisplay->renderer = SDL_CreateRenderer(tmpDisplay->window, -1, render_flags);

	if(!tmpDisplay->renderer){
		fprintf(stderr, "SDL could not create renderer, SDL_Error: %s\n", SDL_GetError());
		Display_Quit(tmpDisplay);
		exit(EXIT_FAILURE);
	}

    if(!(IMG_Init(image_flags) & image_flags)){
        fprintf(stderr, "SDL_image could not be initialized! IMG_Error: %s\n", IMG_GetError());
        Display_Quit(tmpDisplay);
        exit(EXIT_FAILURE);
    }

	return tmpDisplay;
}

void Display_Clear(struct Display* display, SDL_Color* clear_color)
{
	SDL_SetRenderDrawColor(display->renderer, clear_color->r, clear_color->g, clear_color->b, clear_color->a);
	SDL_RenderClear(display->renderer);

	return;
}

void Display_Present(struct Display* display)
{
	SDL_RenderPresent(display->renderer);

	return;
}

void Display_Quit( struct Display* display)
{
	SDL_DestroyRenderer(display->renderer);
	SDL_DestroyWindow(display->window);
	free(display);
	SDL_Quit();

    return;
}