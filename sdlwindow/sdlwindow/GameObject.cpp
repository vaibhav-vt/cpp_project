#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texsheet, int x, int y)
{
	objtex = TextureManager::LoadTex(texsheet);

	xpos = x;
	ypos = y;

}

void GameObject::Update()
{

	xpos++;
	ypos++;
	
	srcR.h = 716;
	srcR.w = 784;
	srcR.x = 0;
	srcR.y = 0;

	desR.x = xpos;
	desR.y = ypos;
	desR.w = srcR.w/8;
	desR.h = srcR.h/8;



}

void GameObject::UpdateBg()
{
	srcR.h = 480;
	srcR.w = 640;
	srcR.x = 0;
	srcR.y = 0;

	desR.x = xpos;
	desR.y = ypos;
	desR.w = 800;
	desR.h = 640;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objtex, &srcR, &desR);
}