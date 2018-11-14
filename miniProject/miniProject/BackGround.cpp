#include "BackGround.h"



BackGround::BackGround(const LoaderParams* p_Params) : SDLGameObject(p_Params)
{
}


BackGround::~BackGround()
{
}

void BackGround::update()
{
	move_bg();

	SDLGameObject::update();
}

void BackGround::move_bg()
{
	m_velocity.setX(-moveSpeed);
}

void BackGround::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
