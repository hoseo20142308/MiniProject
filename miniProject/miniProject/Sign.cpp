#include "Sign.h"

Sign::Sign(const LoaderParams * p_Params) : SDLGameObject (p_Params)
{
	m_velocity.setX(-moveSpeed);
}

Sign::Sign(const LoaderParams * p_Params, int type) : SDLGameObject(p_Params)
{
	m_velocity.setX(-moveSpeed);
	this->type = type;
}
