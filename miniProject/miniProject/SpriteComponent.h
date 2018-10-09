#pragma once

#include "Components.h"
#include <SDL.h>

class SpriteComponent : public Component
{
private:
	PositionComponent * position;

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}

	void init() override
	{
		position = &entity->getComponent<PositionComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = 128;
		srcRect.h = 82;

		destRect.w = srcRect.w;
		destRect.h = srcRect.h;
	}

	void update() override
	{
		srcRect.x = 128 * int(((SDL_GetTicks() / 70) % 6));
		destRect.x = position->x();
		destRect.y = position->y();
	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}
};