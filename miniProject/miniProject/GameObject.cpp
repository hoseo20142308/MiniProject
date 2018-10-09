#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet)
{
	
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = 0;
	ypos = 0;

	srcRect.h = NULL;
	srcRect.w = NULL;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;

	srcRect.h = 1536;
	srcRect.w = 3072;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 640;
	destRect.h = 480;

}

void GameObject::Update()
{
	destRect.x--;

	if (destRect.x <= -640)destRect.x = 640;

}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}