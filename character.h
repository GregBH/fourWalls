#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "sprite.h"
#define DEFAULTSPEED 5

struct Character{
    struct Sprite* sprite;
    int speed;
    SDL_bool moveIdle, moveUp, moveDown, moveLeft, moveRight;
};

struct Character* Character_Create(SDL_Renderer*, int, int, int, int, const char*);
void Character_Draw(struct Character*, SDL_Renderer*);
void Character_PollEvents(struct Character*, SDL_Event*);
void Character_Update(struct Character*);
void Character_Free(struct Character*);

#endif