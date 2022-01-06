#include "SDL.h"
#include <iostream>
#include "SDL_ttf.h"


int showmenu(SDL_Surface* screen, TTF_Font* font)
{
    //Uint32 time;
    int x, y;
    const int NUMMENU = 2;
    const char* labels[NUMMENU] = { "PLAY","Exit" };
    SDL_Surface* menus[NUMMENU];
    bool selected[NUMMENU] = { 0,0 };
    SDL_Color color[2] = { {0,204,153},{57,255,20} };

    menus[0] = TTF_RenderText_Solid(font, labels[0], color[0]);


    menus[1] = TTF_RenderText_Solid(font, labels[1], color[0]);
    SDL_Rect pos[NUMMENU];
    pos[0].x = screen->clip_rect.w / 2 - menus[0]->clip_rect.w / 2;
    pos[0].y = screen->clip_rect.h / 2 - menus[0]->clip_rect.h;
    pos[1].x = screen->clip_rect.w / 2 - menus[0]->clip_rect.w / 2;
    pos[1].y = screen->clip_rect.h / 2 + menus[0]->clip_rect.h;

    SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));
   

   


    SDL_Event event;
    while (1)
    {
        // time = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                SDL_FreeSurface(menus[0]);
                SDL_FreeSurface(menus[1]);

                return 1;
            case SDL_MOUSEMOTION:
                x = event.motion.x;
                y = event.motion.y;
                for (int i = 0; i < NUMMENU; i++)
                {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        if (!selected[i])
                        {
                            selected[i] = 1;
                            SDL_FreeSurface(menus[i]);
                            menus[i] = TTF_RenderText_Solid(font, labels[i], color[1]);
                        }
                    }
                    else
                    {
                        if (selected[i])
                        {
                            selected[i] = 0;
                            SDL_FreeSurface(menus[i]);
                            menus[i] = TTF_RenderText_Solid(font, labels[i], color[0]);
                        }
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                x = event.button.x;
                y = event.button.y;
                for (int i = 0; i < NUMMENU; i += 1)
                {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        SDL_FreeSurface(menus[0]);
                        SDL_FreeSurface(menus[1]);
                        return i;
                        break;
                    }
                }
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    SDL_FreeSurface(menus[0]);
                    SDL_FreeSurface(menus[1]);
                    return 2;
                }
            }
        }

        for (int i = 0; i < NUMMENU; i += 1)
        {
            SDL_BlitSurface(menus[i], NULL, screen, &pos[i]);
        }
        

    }
}

int main(int argc, char* argv[])
{

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("BASKET_BALL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 748, 421, SDL_WINDOW_SHOWN);
    // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface* screen = SDL_GetWindowSurface(window);
    SDL_Rect dest1;
    dest1.x = 0;
    dest1.y = 0;
    dest1.w = 748;
    dest1.h = 420;
    SDL_Surface* image1 = SDL_LoadBMP("basket.bmp");
    SDL_BlitScaled(image1, NULL, screen, &dest1);


    

    bool isRunning = true;
    SDL_Event ev;
    TTF_Font* font;
    TTF_Init();
    font = TTF_OpenFont("game.ttf", 50);
    //int i = showmenu(screen, font);
    //if (i == 1)
      //isRunning = false;
    while (isRunning)
    {
        while (SDL_PollEvent(&ev))
        {
            switch (ev.type)
            {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:

                switch (ev.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    int i = showmenu(screen, font);

                    if (i == 1)
                        isRunning = false;
                    if (i == 0)
                    {
                        SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 255, 255, 0));
                       
                        SDL_UpdateWindowSurface(window);

                    }
                }
                break;
            }
            SDL_UpdateWindowSurface(window);
        }

    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}



