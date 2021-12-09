#pragma one

#include"Game.hpp"

class Map
{
    public:
        Map();
        ~Map();

        void LoadMap(int arr[20][32]);
        void DrawMap();
    private:

        SDL_Rect src,dest;

        SDL_Texture* soil;
        SDL_Texture* grass;

        int map[20][32];
};