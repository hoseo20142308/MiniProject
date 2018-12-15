#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setX(-moveSpeed);
}

Enemy::Enemy(const LoaderParams * pParams, int type) : SDLGameObject(pParams)
{
	this->type = type;
	m_velocity.setX(-moveSpeed);
}

/*void Enemy::draw()
{
	SDLGameObject::draw();
}*/

void Enemy::update()
{

	setSprite();

	SDLGameObject::update();

}

void Enemy::setSprite()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}
