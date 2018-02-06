#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "sprite.h"
#define DEFAULTSPEED 5

struct Character{
    struct Sprite* sprite;
    int speed;
    SDL_bool moveIdle, moveUp, moveDown, moveLeft, moveRight;
};

struct Character* CreateCharacter(int, int, int, int, const char*);
void DrawCharacter(struct Character*);
void PollKeyEvents(struct Character*, SDL_Event*);
void Movement(struct Character*);
void FreeCharacter(struct Character*);

#endif