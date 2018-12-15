#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	Enemy(const LoaderParams* pParams, int type);
	//virtual void draw();
	virtual void update();
	virtual void clean() {};
private:
	int moveSpeed = 5;

	void setSprite();
};