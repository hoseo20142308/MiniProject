#pragma once

#include "SDLGameObject.h"
#include "Game.h"

class Floor : public SDLGameObject
{
public:
	Floor(const LoaderParams* p_Params);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

private:

	int moveSpeed = 5;

	void move();

	void check_Pass();
};

