#include"Gameobject.hpp"
#include"Map.hpp"
#include"Animate.hpp"


Gameobject* stadium;
Gameobject* rim;
Gameobject* bush;

Gameobject* player1;
Gameobject* player2;
Gameobject* player3;

Gameobject* ball1;
Gameobject* ball2;
Gameobject* ball3;

int k = 0;

Map* map ;

SDL_Renderer* Game::renderer = nullptr;

Game:: Game()
{

}

Game :: ~Game()
{

}


void Game::init(const char* title,int xpos,int ypos,int width,int height, bool fullscreen)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title,xpos,ypos,width,height,0);
    }

    renderer = SDL_CreateRenderer(window,-1,0);
    if(renderer)
    {
        SDL_SetRenderDrawColor(renderer,255,0,255,255);
        isrunning = true;
    }
    else
    {
        isrunning = false;
    }

    stadium = new Gameobject("stadium2.jpg",0,0,16,9,0);
    rim = new Gameobject("rim.png",680,150,6,7,0);
    bush = new Gameobject("bush.png",940,530,1,1,0);
    player1 = new Gameobject("p1.png",150,413,2,3,0);
    player2 = new Gameobject("p2.png",150,413,2,3,0);
    player3 = new Gameobject("p3.png",150,413,2,3,0);
    ball1 = new Gameobject("ball1.png",245,480,1,1,0);
    ball2 = new Gameobject("ball2.png",245,517,1,1,0);
    ball3 = new Gameobject("ball3.png",245,555,1,1,0);

    map = new Map();

}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    switch (event.type)
    {
        case SDL_QUIT:
            isrunning = false;
            break;
        case SDL_KEYDOWN:
            /*switch (event.key.keysym.sym)
            {
                case SDLK_RIGHT:
                    k = 4;
                    break;
                case SDLK_LEFT:
                    k = -4;
                    break;
                default:
                    break;
            }
            break;*/
            if(keystates[SDL_SCANCODE_LEFT])
                {
                    k = -4;
                    break;
                }
   
            if(keystates[SDL_SCANCODE_RIGHT])
                {
                    k = +4;
                    break;
                } 
        /*case keystates[SDL_SCANCODE_LEFT]:
            k = -4;
            break;
        case keystates[SDL_SCANCODE_RIGHT]:
            k = 4;
            break;*/
        case SDL_KEYUP:
            k = 0;
            break;
        default:
            break;
    }
    /*if(keystates[SDL_SCANCODE_LEFT])
    {
        k = -4;
        break;
    }
   
    if(keystates[SDL_SCANCODE_RIGHT])
    {
        k = +4;
        break;
    }*/
}

void Game::update()
{
    stadium->update(0);
    rim -> update(0);
    bush->update(0);
    player1->update(k);
    player2->update(k);
    player3->update(k); 
    ball1->update(k);
    ball2->update(k);
    ball3->update(k);
}
void Game::render()
{
    SDL_RenderClear(renderer);
    stadium->render();
    map->DrawMap();
    rim -> render();
    bush->render();
    if(SDL_GetTicks()%5 == 0)
    {
        player1->render();
        ball1->render();
        SDL_Delay(50);
    }
    else if(SDL_GetTicks()%5 == 1)
    {
        player2->render();
        ball2->render();
        SDL_Delay(50);
    }
    else if(SDL_GetTicks()%5 == 2)
    {
        player3->render();
        ball3->render();
        SDL_Delay(50);
    }
    else if(SDL_GetTicks()%5 == 3)
    {
        player2->render();
        ball2->render();
        SDL_Delay(50);
    }
    else
    {
        player1->render();
        ball1->render();
        SDL_Delay(50);
    }

    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}



