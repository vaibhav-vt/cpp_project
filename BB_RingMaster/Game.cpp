//Header
#include"Gameobject.hpp"
#include"Map.hpp"
#include<math.h>
#include<time.h>
#include<iostream>
#include<vector>
#define PI 3.141592654

//Objects for Background 
Gameobject* stadium;
Gameobject* rim;
Gameobject* bush;

//Mutliple images for same object in motion
Gameobject* player1;
Gameobject* player2;
Gameobject* player3;

Gameobject* ball1;
Gameobject* ball2;
Gameobject* ball3;

//Objects for Horizontal Movement
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

//Object for Jump Movement
Gameobject* j;
Gameobject* j2;
Gameobject* j3;
Gameobject* j4;
Gameobject* j5;
Gameobject* j6;
Gameobject* j7;
Gameobject* j8;

//Arrow object indicating different angles
Gameobject* ang_0;
Gameobject* ang_15;
Gameobject* ang_30;
Gameobject* ang_45;
Gameobject* ang_60;
Gameobject* ang_75;
Gameobject* ang_90;

//Object indicating states of speed bar 
Gameobject* speed_0;
Gameobject* speed_1;
Gameobject* speed_2;
Gameobject* speed_3;
Gameobject* speed_4;

//List containing all object for angle and speed object
std :: vector<Gameobject*> ang ;
std :: vector<Gameobject*> power;

//Numerical value for angles and velocity of ball(while shooting) corresponding to objects in the list
int ang_Arr[] = {0,15,30,45,60,75,90};
int power_Arr[] = {15,19,21,23,25};

//Object for indicating lives remaining
Gameobject* lives_3;
Gameobject* lives_2;
Gameobject* lives_1;

Gameobject* life;

//List containing all object for Lives
std :: vector<Gameobject*> lives;

//Object indicating score -> All digits from 0-9
Gameobject* score_0;
Gameobject* score_1;
Gameobject* score_2;
Gameobject* score_3;
Gameobject* score_4;
Gameobject* score_5;
Gameobject* score_6;
Gameobject* score_7;
Gameobject* score_8;
Gameobject* score_9;
Gameobject* score;

//List containing all object for Scores
std :: vector<Gameobject*> scores;

Gameobject* Gameover;

//Flags for game object
int k = 0;
int factor = 0;
int mflag = 0;
int enter = 0;
int enter_shoot = 0;
int shoot = 0;
double vel =0;
double theata =0;


int ball_x = 0;
int ball_y = 0;

time_t t_init;
int t_flag = 0;

int success = 0;
int back = 0;
int angle = 0;
int angle_index = 2;
int power_index = 2;
int speed = 0;
int stop = 0;
int lives_remain = 3;
int current_score = 0;
int game_over = 0;

Map* map ;

SDL_Renderer* Game::renderer = nullptr;

//Constructor
Game:: Game()
{

}

//Destructor
Game :: ~Game()
{
    
}

//Intializing Game
void Game::init(const char* title,int xpos,int ypos,int width,int height, bool fullscreen)
{
    //Creating Window
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title,xpos,ypos,width,height,0);
    }

    renderer = SDL_CreateRenderer(window,-1,0);
    if(renderer)
    {
        SDL_SetRenderDrawColor(renderer,0,255,255,255);
        isrunning = true;
    }
    else
    {
        isrunning = false;
    }


    //Creating Sprite Objects
    stadium = new Gameobject("sprites/stadium2.jpg",0,0,16,9,0);
    Gameover = new Gameobject("sprites/gameover.jpeg",50,50,1,1,0);
    rim = new Gameobject("sprites/bowl.png",780,300,3,2,0);

    player1 = new Gameobject("player/p1.png",150,413,2,3,0);
    player2 = new Gameobject("player/p2.png",150,413,2,3,0);
    player3 = new Gameobject("player/p3.png",150,413,2,3,0);

    ball1 = new Gameobject("ball/ball1.png",245,480,1,1,0);
    ball2 = new Gameobject("ball/ball2.png",245,517,1,1,0);
    ball3 = new Gameobject("ball/ball3.png",245,555,1,1,0);

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

    ang_0 = new Gameobject("angle/angle_0.png",player1->get_xpos(),player1->get_ypos(),1,1,0);
    ang_15 = new Gameobject("angle/angle_15.png",player1->get_xpos(),player1->get_ypos(),1,1,0);
    ang_30 = new Gameobject("angle/angle_30.png",player1->get_xpos(),player1->get_ypos(),1,1,0);
    ang_45 = new Gameobject("angle/angle_45.png",player1->get_xpos(),player1->get_ypos(),1,1,0);
    ang_60 = new Gameobject("angle/angle_60.png",player1->get_xpos(),player1->get_ypos(),1,1,0);
    ang_75 = new Gameobject("angle/angle_75.png",player1->get_xpos(),player1->get_ypos(),1,1,0);
    ang_90 = new Gameobject("angle/angle_90.png",player1->get_xpos(),player1->get_ypos(),1,1,0);


    speed_0 = new Gameobject("speedbar/speed_0.jpeg",50,50,1,3,0);
    speed_1 = new Gameobject("speedbar/speed_1.jpeg",50,50,1,3,0);
    speed_2 = new Gameobject("speedbar/speed_2.jpeg",50,50,1,3,0);
    speed_3 = new Gameobject("speedbar/speed_3.jpeg",50,50,1,3,0);
    speed_4 = new Gameobject("speedbar/speed_4.jpeg",50,50,1,3,0);

    lives_1 = new Gameobject("lives/lives_1.png",150,100,3,1,0);
    lives_2 = new Gameobject("lives/lives_2.png",150,100,3,1,0);
    lives_3 = new Gameobject("lives/lives_3.png",150,100,3,1,0);
    life = new Gameobject("lives/life.jpeg",150,30,3,1,0);

    score_0 = new Gameobject("score/score_0.png",850,10,1,1,0);
    score_1 = new Gameobject("score/score_1.png",850,10,1,1,0);
    score_2 = new Gameobject("score/score_2.png",850,10,1,1,0);
    score_3 = new Gameobject("score/score_3.png",850,10,1,1,0);
    score_4 = new Gameobject("score/score_4.png",850,10,1,1,0);
    score_5 = new Gameobject("score/score_5.png",850,10,1,1,0);
    score_6 = new Gameobject("score/score_6.png",850,10,1,1,0);
    score_7 = new Gameobject("score/score_7.png",850,10,1,1,0);
    score_8 = new Gameobject("score/score_8.png",850,10,1,1,0);
    score_9 = new Gameobject("score/score_9.png",850,10,1,1,0);
    score = new Gameobject("score/score.png",720,10,2,1,0);

    //Adding Sprite Objects in Angle/Power/Lives/Score Vector
    ang.push_back(ang_0);
    ang.push_back(ang_15);
    ang.push_back(ang_30);
    ang.push_back(ang_45);
    ang.push_back(ang_60);
    ang.push_back(ang_75);
    ang.push_back(ang_90);

    power.push_back(speed_0);
    power.push_back(speed_1);
    power.push_back(speed_2);
    power.push_back(speed_3);
    power.push_back(speed_4);

    lives.push_back(lives_1);
    lives.push_back(lives_2);
    lives.push_back(lives_3);

    scores.push_back(score_0);
    scores.push_back(score_1);
    scores.push_back(score_2);
    scores.push_back(score_3);
    scores.push_back(score_4);
    scores.push_back(score_5);
    scores.push_back(score_6);
    scores.push_back(score_7);
    scores.push_back(score_8);
    scores.push_back(score_9);

    map = new Map();

}

//User Control -> Assigning functions to Buttons on keyboard
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
                if(angle == 0 && speed == 0)
                {
                    k = -15;
                    mflag = 1;
                }
                break;
            }
            if(keystates[SDL_SCANCODE_RIGHT])
            {
                if(angle == 0 && speed == 0)
                {
                    k = +15;
                    mflag = 1;
                }
                break;
            } 
            if( keystates[SDL_SCANCODE_UP] )
            {
                mflag = 2;
                if(enter_shoot == 1)
                {
                    shoot = 1;
                }
                break;
            }
            if( keystates[SDL_SCANCODE_KP_ENTER] )
            {
                enter = 1;
                angle = 1;
                break;
            }
            if(keystates[SDL_SCANCODE_D])
            {
                if(angle == 1)
                {
                    if(angle_index < 6)
                    {
                        angle_index += 1;
                    }
                    else
                    {
                        angle_index = 6;
                    }
                }
                if(speed == 1)
                {
                    if(power_index < 4)
                    {
                        power_index += 1;
                    }
                    else
                    {
                        power_index = 4;
                    }
                }
            }
            if(keystates[SDL_SCANCODE_A])
            {
                if(angle == 1)
                {
                    if(angle_index > 0)
                    {
                        angle_index -= 1;
                    }
                    else
                    {
                        angle_index = 0;
                    }
                }
                if(speed == 1)
                {
                    if(power_index > 0)
                    {
                        power_index -= 1;
                    }
                    else
                    {
                        power_index = 0;
                    }
                }
                
            }
            if(keystates[SDL_SCANCODE_S])
            {
                if(angle == 1)
                {
                    angle = 0;
                    speed = 1;
                }
            }
            if(keystates[SDL_SCANCODE_W])
            {
                if(speed == 1)
                {
                    speed = 0;
                    shoot = 1;
                }
            }
        
        case SDL_KEYUP:
            k = 0;
            mflag = 0;
            break;
        default:
            break;
    }

}

//Updating Sprite Object in the factor through which they move -> (x, y)
void Game::update()
{
    stadium->update(0,0);
    Gameover->update(0,0);
    rim -> update(0,0);
    player1->update(factor,0);
    player2->update(factor,0);
    player3->update(factor,0); 
    factor = 0;

    ball1->update(k+ball_x,0+ball_y);
    for(auto it : ang)
    {
        it -> update(k,0);
    }
    ball2->update(k,0);
    ball3->update(k,0);

    for(auto it : power)
    {
        it -> update(0,0);
    }

    m1 -> update(k,0);
    m2 -> update(k,0);
    m3 -> update(k,0);
    m4 -> update(k,0);
    m5 -> update(k,0);
    m6 -> update(k,0);
    m7 -> update(k,0);
    m8 -> update(k,0);
    m9 -> update(k,0);
    m10 -> update(k,0);
    m11 -> update(k,0);
    m12->update(k,0);
    m13->update(k,0);
    m14->update(k,0);
    m15->update(k,0);
    m16->update(k,0);

    j->update(k,0);
    j2->update(k,0);
    j3->update(k,0);
    j4->update(k,0);
    j5->update(k,0);
    j6->update(k,0);
    j7->update(k,0);
    j8->update(k,0);

    if(lives_remain !=0)
    {
        lives[lives_remain -1] -> update(0,0);
        life->update(0,0);
    }

    for(auto it: scores)
    {
        it->update(0,0);
    }
    score -> update(0,0);

    
}

//Renderring object from renderer
void Game::render()
{
    SDL_RenderClear(renderer);

    //New Game will be created after ending existing game
    if(game_over == 1)
    {
        SDL_Delay(1000);
        Gameover->render();
        game_over = 0;
        lives_remain = 3;
        current_score = 0;
    }

    //Operations when the current game is alive
    if(game_over == 0){
    stadium->render();
    map->DrawMap();
    rim -> render();
    scores[current_score%10]->render();
    score -> render();
    if(lives_remain != 0)
    {
        lives[lives_remain -1] -> render();
        life->render();
    }

    //Animation for dribbling
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

    // Animation for Moving Horizontally
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

    //Animation for jumping
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

    //Fixing the Position of the Player 
    else if(enter == 1)
    {
        player1->render();
        enter_shoot = 1;
        for(auto it : ang)
        {
            (it) -> set_pos(ball1->get_xpos()+25,ball1->get_ypos()-20);
        }
        ball1->render();
        
        SDL_Delay(50);
    }

    //Displaying the angle selected
    if(angle == 1)
    {
        if(stop != 0)
        {
            ang[angle_index] ->render();
        }
        stop = 1;
    }

    //Displaying Speed
    if(speed == 1)
    {
        power[power_index] -> render();
    }
  
    //Shooting 
    if(shoot == 1 && angle == 0)
    {
        angle = 0;
        if(t_flag == 0)
        {
            t_init = time(NULL);
            t_flag = 1;
        }
        time_t inst_time = time(NULL) - t_init;
        player1->render();
        ball1->render();
        vel = power_Arr[power_index];

        theata = (PI*ang_Arr[angle_index])/180;


        ball_x = vel*cos(theata);

        double p = 10*pow(inst_time, 1.25);
        ball_y = - vel*sin(theata) + p;

        
        if(ball1 -> get_xpos() > 750 && ball1 -> get_xpos() < 790 && ball1->get_ypos() > 245)
        {
            success=1;
            lives_remain--;
            back = 1;
        }
        else if(ball1 -> get_ypos() > 575 && ball1->get_xpos() < 770)
        {
            success = 1;
            lives_remain--;
            back = 1;
        }

        else if(ball1->get_xpos() > 770 && ball1 -> get_xpos() < 910)
        {
            if(success != 1 && ball1->get_ypos() > 245 && ball1->get_ypos() < 375)
            {
                success = 2;
                back = 1;
                ball_x = 0;
                ball_y = 0;
                rim->render();
                current_score++;
            }
        }

        else if(ball1->get_xpos() > 900 && ball1->get_ypos() < 245)
        {
            success = 1;
            lives_remain--;
            back = 1;
        }
 

        if(ball1->get_ypos() > 580 || ball1->get_xpos() > 1000 || back == 1)
        {
            enter = 0;
            mflag = 0;
            shoot = 0;
            enter_shoot = 0;
            ball_x = 0;
            ball_y = 0;
            t_flag = 0;
            success = 0;
            back = 0;
            angle = 0;
            angle_index = 2;
            stop = 0;
            speed = 0;
            power_index = 2;
            ball1->set_pos(ball2->get_xpos(),480);
        }
        }
        if(lives_remain == 0)
        {
            game_over = 1;
        }
    }
    SDL_RenderPresent(renderer);
}

//Closing(Destroying) the Window and Quiting the game
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

//Game Completed!!