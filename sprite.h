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


struct Sprite* CreateSprite(int, int, int, int, const char*);
void DrawSprite(struct Sprite*, SDL_Renderer*);
void FreeSprite(struct Sprite*);

#endif