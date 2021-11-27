#pragma once
#include "Game.h"

class GameObject {

public:
	GameObject(const char* texsheet, int x, int y);
	~GameObject();

	void Update();
	void UpdateBg();
	void Render();

private:
	int xpos;
	int ypos;
	SDL_Texture* objtex;
	SDL_Rect srcR, desR;


};