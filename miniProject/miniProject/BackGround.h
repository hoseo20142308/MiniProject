#pragma once

#include "SDLGameObject.h"

class BackGround : public SDLGameObject
{
public:
	BackGround(const LoaderParams* p_Params);
	~BackGround();
	virtual void draw();
	virtual void update();
	virtual void clean() {};

	void setSpeed(int value) { moveSpeed = value; }
	int getSpeed() { return moveSpeed; }
private:
	int moveSpeed = 5;
	bool isOutWindow = false;
	void move_bg();
	void change_position();
};

