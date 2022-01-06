#pragma once

#include "Game.hpp"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>


class TextManager
{
    public:
        static SDL_Texture* LoadTexture(const char* filename);
        static void Draw(SDL_Texture*,SDL_Rect src,SDL_Rect dest);

};