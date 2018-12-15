#include "BackGround.h"



BackGround::BackGround(const LoaderParams* p_Params) : SDLGameObject(p_Params)
{
	m_currentFrame = 0;
}


BackGround::BackGround(const LoaderParams* p_Params, int type) : SDLGameObject(p_Params)
{
	m_currentFrame = 0;
	this->type = type;
}

void BackGround::update()
{
	move_bg();
	change_position();

	SDLGameObject::update();
}

void BackGround::move_bg()
{
	m_velocity.setX(-moveSpeed);
}

void BackGround::change_position()
{
	if (m_position.GetX() <= -640)
		m_position.setX(640);
}

void BackGround::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
