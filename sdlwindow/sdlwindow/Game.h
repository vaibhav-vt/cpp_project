#pragma once

#ifndef Game_hpp

#define Game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>

class Game {

public:
	~Game();
	Game();

	void init(const char* title, int xpos, int ypos, int width, int height, int fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	static SDL_Renderer* renderer;

	bool running()
	{
		return isRunning;
	};

private:
	bool isRunning;
	SDL_Window *window;
	int count = 0; 


};

#endif // !Game_hpp

