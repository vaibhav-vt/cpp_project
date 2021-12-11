#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class RenderWindow
{
    public:
        void Renderwindow(char const * title,int width, int height);
        void cleanup();
        SDL_Texture* LoadTexture(const char* file_path);
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};
