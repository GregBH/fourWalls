#include "character.h"

int _speed = 6;

struct Character* Character_Create(SDL_Renderer* renderer, int x, int y, int w, int h, const char* filename)
{
    struct Character* tmpCharacter = (struct Character*)malloc(sizeof(struct Character));
    tmpCharacter->sprite    = CreateSprite(renderer, x, y, w, h, filename);
    tmpCharacter->moveIdle  = SDL_TRUE;
    tmpCharacter->moveUp    = SDL_FALSE;
    tmpCharacter->moveDown  = SDL_FALSE;
    tmpCharacter->moveLeft  = SDL_FALSE;
    tmpCharacter->moveRight = SDL_FALSE;   
    tmpCharacter->speed     = _speed;

    return tmpCharacter;
}

void Character_Draw(struct Character* obj, SDL_Renderer* renderer)
{
    DrawSprite(obj->sprite, renderer);
    
    return;
}

void Character_PollEvents(struct Character* obj, SDL_Event* event)
{
    //TODO: Smoother Movement, Decide between Fluid or Step
    if(event->type == SDL_KEYDOWN){
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
    
    }
    if(event->type == SDL_KEYUP){
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
    }   

    return;
}

void Character_Update(struct Character* obj)
{
    if(obj->moveUp == SDL_TRUE){
        obj->sprite->y -= obj->speed;
        //obj->moveUp = SDL_FALSE;
    }
    if(obj->moveDown == SDL_TRUE){
        obj->sprite->y += obj->speed;
        //obj->moveDown = SDL_FALSE;
    }
    if(obj->moveLeft == SDL_TRUE){
        obj->sprite->x -= obj->speed;
        //obj->moveLeft = SDL_FALSE;
    }
    if(obj->moveRight == SDL_TRUE){
        obj->sprite->x += obj->speed;
        //obj->moveRight = SDL_FALSE;
    }

    return;
}

void Character_Free(struct Character* obj)
{
    FreeSprite(obj->sprite);
    free(obj);

    return;
}