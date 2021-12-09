#pragma once

#include "Game.hpp"
#include "Gameobject.hpp"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<vector>
#include<utility>

class Animate : public Gameobject
{
    public:
        Animate(const char* texturesheet,int x,int y,int factor,int factory,int moveflag) : Gameobject(texturesheet,x, y,factor, factory,moveflag)
        {
            ;
        }
        // void update(std :: vector< std :: pair<int,int>>& images);

};