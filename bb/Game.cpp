// #include"Game.hpp"
#include"Gameobject.hpp"
#include"Map.hpp"
#include"Animate.hpp"


Gameobject* stadium;
Gameobject* rim;
Gameobject* bush;
Gameobject* player1;
Gameobject* player2;
Gameobject* player3;
// std :: vector<SDL_Texture*,SDL_Texture*> images_player2;

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
    player1 = new Gameobject("q1.png",150,413,2,3,0);
    player2 = new Gameobject("q2.png",150,413,2,3,0);
    player3 = new Gameobject("q3.png",150,413,2,3,0);


    map = new Map();

}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT)
    {
        isrunning = false;
    }
   
}

void Game::update()
{
    stadium->update();
    rim -> update();
    bush->update();
    player1->update();
    player2->update();
    player3->update(); 
}
void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_Delay(10);
    stadium->render();
    map->DrawMap();
    rim -> render();
    bush->render();
    player1->render();
    if(SDL_GetTicks()%5 == 0)
    {
        player1->render();
    }
    else if(SDL_GetTicks()%5 == 1)
    {
        player2->render();
        SDL_Delay(10);
    }
    else if(SDL_GetTicks()%5 == 2)
    {
        player3->render();
        SDL_Delay(10);
    }
    else if(SDL_GetTicks()%5 == 3)
    {
        player2->render();
        SDL_Delay(10);
    }
    else
    {
        player1->render();
    }

    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}



