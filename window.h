#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

struct WindowAndRenderer {
    SDL_Window* window;
    SDL_Renderer* renderer;
}Win_Rend;

void init(const char*, int, int, Uint32, int);
void quit();

#endif