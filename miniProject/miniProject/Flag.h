#pragma once

#include "SDLGameObject.h"
#include "Game.h"

class Flag : public SDLGameObject
{
public:
	Flag(const LoaderParams* p_Params);
	Flag(const LoaderParams* p_Params, int type);
	//virtual void draw();
	virtual void update();
	virtual void clean() {};

private:

	int moveSpeed = 10;

	void setSprite();

};

