
#include<iostream>

#include"RenderWindow.hpp"
#include<SDL2/SDL_image.h>


void RenderWindow :: Renderwindow(char const* title,int width,int height)
{
    window = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

}

void RenderWindow :: cleanup()
{
    SDL_DestroyWindow(window);
}

SDL_Texture* RenderWindow :: LoadTexture(const char* fi)
{
    SDL_Texture * texture = IMG_LoadTexture(renderer,fi);
    // IMG_LoadTexture()
    return texture;
 
}