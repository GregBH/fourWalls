#include "character.h"

struct Character* CreateCharacter(int x, int y, int w, int h, const char* filename)
{
    struct Character* tmpCharacter = (struct Character*)malloc(sizeof(struct Character));
    tmpCharacter->sprite    = CreateSprite( x, y, w, h, filename);
    tmpCharacter->moveIdle  = SDL_TRUE;
    tmpCharacter->moveUp    = SDL_FALSE;
    tmpCharacter->moveDown  = SDL_FALSE;
    tmpCharacter->moveLeft  = SDL_FALSE;
    tmpCharacter->moveRight = SDL_FALSE;   
    tmpCharacter->speed     = 8;

    return tmpCharacter;
}

void DrawCharacter(struct Character* obj)
{
    DrawSprite(obj->sprite, Win_Rend.renderer);
    return;
}

void PollKeyEvents(struct Character* obj, SDL_Event* event)
{
    //TODO: Smoother Movement, Decide between Fluid or Step
    switch(event->type){
        case SDL_KEYDOWN:
            printf("KEYDONW\n");
            switch(event->key.keysym.sym){
                case SDLK_UP:
                    obj->moveUp = SDL_TRUE;
                    break;
                case SDLK_DOWN:
                    obj->moveDown = SDL_TRUE;
                    break;
                case SDLK_LEFT:
                    obj->moveLeft = SDL_TRUE;
                    break;
                case SDLK_RIGHT:
                    obj->moveRight = SDL_TRUE;
                    break;
            }
            break;

        case SDL_KEYUP:
            printf("KEYUP\n");
            switch(event->key.keysym.sym){
                case SDLK_UP:
                    obj->moveUp = SDL_FALSE;
                    break;
                case SDLK_DOWN:
                    obj->moveDown = SDL_FALSE;
                    break;
                case SDLK_LEFT:
                    obj->moveLeft = SDL_FALSE;
                    break;
                case SDLK_RIGHT:
                    obj->moveRight = SDL_FALSE;
                    break;
            }
            break;
    }   

    return;
}

void Movement(struct Character* obj)
{
    if(obj->moveUp == SDL_TRUE){
        obj->sprite->y -= obj->speed;
        obj->moveUp = SDL_FALSE;
    }
    if(obj->moveDown == SDL_TRUE){
        obj->sprite->y += obj->speed;
        obj->moveDown = SDL_FALSE;
    }
    if(obj->moveLeft == SDL_TRUE){
        obj->sprite->x -= obj->speed;
        obj->moveLeft = SDL_FALSE;
    }
    if(obj->moveRight == SDL_TRUE){
        obj->sprite->x += obj->speed;
        obj->moveRight = SDL_FALSE;
    }

    return;
}

void FreeCharacter(struct Character* obj)
{
    FreeSprite(obj->sprite);
    free(obj);

    return;
}