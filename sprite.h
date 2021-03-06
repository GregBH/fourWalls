#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "window.h"

const char* _placeHolder;

struct Sprite {
    int x, y;
    int w, h;
    SDL_Texture* texture;
    const char* filename;
};


struct Sprite* Sprite_Create(SDL_Renderer*, int, int, int, int, const char*);
void Sprite_Draw(struct Sprite*, SDL_Renderer*);
void Sprite_Free(struct Sprite*);

#endif