#include "Flag.h"
#include "PlayState.h"
#include "Game.h"

Flag::Flag(const LoaderParams * p_Params) : SDLGameObject(p_Params)
{
	m_currentFrame = 0;
	m_velocity.setX(-moveSpeed);
}

Flag::Flag(const LoaderParams * p_Params, int type) : SDLGameObject(p_Params)
{
	m_currentFrame = 0;
	m_velocity.setX(-moveSpeed);
	this->type = type;
}

void Flag::update()
{
	setSprite();

	SDLGameObject::update();
}

void Flag::setSprite()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
}


