#pragma once

#include "SDLGameObject.h"
#include "Game.h"

class Sign : public SDLGameObject
{
public:
	Sign(const LoaderParams* p_Params);
	Sign(const LoaderParams* p_Params, int type);
	//virtual void draw();
	//virtual void update();
	virtual void clean() {};

private:

	int moveSpeed = 5;

};

