#include"Gameobject.hpp"
#include"Map.hpp"


Gameobject* stadium;
Gameobject* rim;
Gameobject* bush;

Gameobject* player1;
Gameobject* player2;
Gameobject* player3;

Gameobject* ball1;
Gameobject* ball2;
Gameobject* ball3;


Gameobject* m1;
Gameobject* m2;
Gameobject* m3;
Gameobject* m4;
Gameobject* m5;
Gameobject* m6;
Gameobject* m7;
Gameobject* m8;
Gameobject* m9;
Gameobject* m10;
Gameobject* m11;
Gameobject* m12;
Gameobject* m13;
Gameobject* m14;
Gameobject* m15;
Gameobject* m16;

Gameobject* j;
Gameobject* j2;
Gameobject* j3;
Gameobject* j4;
Gameobject* j5;
Gameobject* j6;
Gameobject* j7;
Gameobject* j8;


int k = 0;
int factor = 0;
int mflag = 0;
int enter = 0;

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

    m1 = new Gameobject("movesprite/m1.png",156,413,2,3,0);
    m2 = new Gameobject("movesprite/m2.png",156,413,2,3,0);
    m3 = new Gameobject("movesprite/m3.png",156,413,2,3,0);
    m4 = new Gameobject("movesprite/m4.png",156,413,2,3,0);
    m5 = new Gameobject("movesprite/m5.png",156,413,2,3,0);
    m6 = new Gameobject("movesprite/m6.png",156,413,2,3,0);
    m7 = new Gameobject("movesprite/m7.png",156,413,2,3,0);
    m8 = new Gameobject("movesprite/m8.png",156,413,2,3,0);
    m9 = new Gameobject("movesprite/m9.png",156,413,2,3,0);
    m10 = new Gameobject("movesprite/m10.png",156,413,1.1,3,0);
    m11 = new Gameobject("movesprite/m11.png",156,413,1.2,3,0);
    m12 = new Gameobject("movesprite/m12.png",156,413,2,3,0);
    m13 = new Gameobject("movesprite/m13.png",156,413,2,3,0);
    m14 = new Gameobject("movesprite/m14.png",156,413,2,3,0);
    m15 = new Gameobject("movesprite/m15.png",156,413,2,3,0);
    m16 = new Gameobject("movesprite/m16.png",156,413,2,3,0);

    j = new Gameobject("jump/j1.png",156,413,2,3,0);
    j2 = new Gameobject("jump/j2.png",156,380,2,3,0);
    j3 = new Gameobject("jump/j3.png",156,340,2,3,0);
    j4 = new Gameobject("jump/j4.png",156,310,2,3,0);
    j5 = new Gameobject("jump/j5.png",156,290,2,3,0);
    j6 = new Gameobject("jump/j6.png",156,330,2,3,0);
    j7 = new Gameobject("jump/j7.png",156,380,1,3,0);
    j8 = new Gameobject("jump/j8.png",156,413,2,3,0);

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
            if(keystates[SDL_SCANCODE_LEFT])
            {
                k = -15;
                mflag = 1;
                break;
            }
            if(keystates[SDL_SCANCODE_RIGHT])
            {
                k = +15;
                mflag = 1;
                break;
            } 
            if( keystates[SDL_SCANCODE_UP] )
            {
                mflag = 2;
                break;
            }
            if( keystates[SDL_SCANCODE_KP_ENTER] )
            {
                enter = 1;
                break;
            }
        case SDL_KEYUP:
            k = 0;
            mflag = 0;
            break;
        default:
            break;
    }

}

void Game::update()
{
    stadium->update(0);
    rim -> update(0);
    bush->update(0);
    player1->update(factor);
    player2->update(factor);
    player3->update(factor); 
    factor = 0;

    ball1->update(k);
    ball2->update(k);
    ball3->update(k);

    m1 -> update(k);
    m2 -> update(k);
    m3 -> update(k);
    m4 -> update(k);
    m5 -> update(k);
    m6 -> update(k);
    m7 -> update(k);
    m8 -> update(k);
    m9 -> update(k);
    m10 -> update(k);
    m11 -> update(k);
    m12->update(k);
    m13->update(k);
    m14->update(k);
    m15->update(k);
    m16->update(k);

    j->update(k);
    j2->update(k);
    j3->update(k);
    j4->update(k);
    j5->update(k);
    j6->update(k);
    j7->update(k);
    j8->update(k);
}
void Game::render()
{
    SDL_RenderClear(renderer);
    stadium->render();
    map->DrawMap();
    rim -> render();
    bush->render();
    if(mflag == 0 && enter!= 1)
    {
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
    }
    else if(mflag == 1 && enter != 1)
    {
        if(SDL_GetTicks()%15 == 0)
        {
            m1->render();
            ball1 -> render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 1)
        {
            m2 ->render();
            ball2->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 2)
        {
            m3->render();
            ball3->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 3)
        {
            m4->render();
            ball2->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 4)
        {
            m5->render();
            ball1->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 5)
        {
            m6->render();
            ball2->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 6)
        {
            m7->render();
            ball3->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 7)
        {
            m8->render();
            ball2->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 8)
        {
            m9->render();
            ball1->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 9)
        {
            m10->render();
            ball2->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 10)
        {
            m11->render();
            ball3->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 11)
        {
            m12->render();
            ball2->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 12)
        {
            m13->render();
            ball1->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 13)
        {
            m14->render();
            ball2->render();
            SDL_Delay(100);
        }
        else if(SDL_GetTicks()%15 == 14)
        {
            m15->render();
            ball2->render();
            SDL_Delay(100);
        }
        factor += k;
    }
    else if(mflag == 2 && enter != 1)
    {
        if(SDL_GetTicks()%8 == 0)
        {
            j->render();
            SDL_Delay(50);
        }
        else if(SDL_GetTicks()%8 == 1)
        {
            j2->render();
            SDL_Delay(50);
        }
        else if(SDL_GetTicks()%8 == 2)
        {
            j3->render();
            SDL_Delay(50);
        }
        else if(SDL_GetTicks()%8 == 3)
        {
            j4->render();
            SDL_Delay(50);
        }
        else if(SDL_GetTicks()%8 == 4)
        {
            j5->render();
            SDL_Delay(50);
        }
        else if(SDL_GetTicks()%8 == 5)
        {
            j6->render();
            SDL_Delay(50);
        }
        else if(SDL_GetTicks()%8 == 6)
        {
            j7->render();
            SDL_Delay(50);
        }
        else
        {
            j8->render();
            SDL_Delay(50);
            mflag = 0;
        }
    }
    else if(enter == 1)
    {
        player1->render();
        ball1->render();
        SDL_Delay(1000);
    }
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}