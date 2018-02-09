#include "sprite.h"

const char* _placeHolder = "res/placeholder_sprite.png";

struct Sprite* CreateSprite(SDL_Renderer* renderer, int x, int y, int w, int h, const char* filename)
{
    struct Sprite* tmpSprite = (struct Sprite*)malloc(sizeof(struct Sprite));
    tmpSprite->x = x;
	tmpSprite->y = y;
	tmpSprite->w = w;
	tmpSprite->h = h;
    tmpSprite->filename = filename;

    SDL_Surface* surface = IMG_Load(tmpSprite->filename);

    if(surface == NULL){
        fprintf(stderr, "IMG_LOAD returned NULL, IMG_Error: %s\n", IMG_GetError());
        surface = IMG_Load(_placeHolder);
        if(surface == NULL){
            fprintf(stderr,"placeholder_sprite also failed to load, IMG_Error: %s\n", IMG_GetError());
        }
    }

    tmpSprite->texture = SDL_CreateTextureFromSurface(renderer, surface);

    if(tmpSprite->texture == NULL){
        fprintf(stderr, "Failed to create texture from surface! SDL_Error: %s\n", SDL_GetError());
    }

    SDL_FreeSurface(surface);

    return tmpSprite;
}

void DrawSprite(struct Sprite* sprite, SDL_Renderer* renderer)
{
	SDL_Rect tmpRect = { sprite->x, sprite->y, sprite->w, sprite->h };
	SDL_RenderCopy(renderer, sprite->texture, NULL, &tmpRect);
	return;
}

void FreeSprite(struct Sprite* sprite)
{
    SDL_DestroyTexture(sprite->texture);
    free(sprite);

    return;
}