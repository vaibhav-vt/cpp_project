#pragma once

#include "Game.hpp"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

class Gameobject
{
    public:
        Gameobject(const char* texturesheet,int x,int y,float factor,int factory,int moveflag);
        ~Gameobject();

        void update(int k);
        void render();

        int xpos;
        int ypos;
        float f;
        int fy;
        int mf;

        SDL_Texture* objTexture;
        SDL_Rect srcRect,destRect;
        // SDL_Renderer* renderer;

};