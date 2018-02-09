#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>


struct Display {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Color clear_color;
    SDL_bool display_close;
};

struct Display* Display_Init(const char*, int, int, Uint32, int);
void Display_PollEvents(struct Display*, SDL_Event*);
void Display_Clear(struct Display*, SDL_Color*);
void Display_Present(struct Display*);
void Display_Quit(struct Display*);

#endif