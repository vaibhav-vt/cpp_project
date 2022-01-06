#include"Gameobject.hpp"
#include"TextureManager.hpp"


Gameobject::Gameobject(const char* textsheet,int x,int y,float factor,float factory,int moveflag)
{
    // renderer = ren;
    objTexture = TextManager::LoadTexture(textsheet);
    xpos = x;
    ypos = y;
    f = factor;
    fy = factory;
    mf = moveflag;
}

void Gameobject :: update(int k,int p)
{
    xpos = xpos +k;
    ypos = ypos + p;

    srcRect.h = 64;
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w *f;
    destRect.h = srcRect.h *fy;
}

int Gameobject :: get_xpos()
{
    return xpos;
}

int Gameobject :: get_ypos()
{
    return ypos;
}

void Gameobject :: set_pos(int x,int y)
{
    xpos = x;
    ypos = y;
}

void Gameobject :: render()
{
    SDL_RenderCopy(Game :: renderer, objTexture,NULL,&destRect);
}