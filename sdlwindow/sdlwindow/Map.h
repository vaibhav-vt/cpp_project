#pragma once

#include "Game.h"

class Map {

public:

	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:

	SDL_Rect srcR, desR;
	SDL_Texture* concr;
	SDL_Texture* hoop;
	SDL_Texture* wood;

	int map[20][25];
};