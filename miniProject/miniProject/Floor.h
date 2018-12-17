#pragma once

#include "SDLGameObject.h"
#include "Game.h"

class Floor : public SDLGameObject
{
public:
	Floor(const LoaderParams* p_Params);
	Floor(const LoaderParams* p_Params, int type);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

private:

	int moveSpeed = 10;

	void check_Pass();
};

