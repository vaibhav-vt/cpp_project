#include"TextureManager.hpp"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

SDL_Texture*  TextManager:: LoadTexture(const char* texture)
{
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer,tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}

void TextManager:: Draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer,tex,&src,&dest);
}