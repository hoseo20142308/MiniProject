#pragma once

#include "SDLGameObject.h"
#include "Game.h"

class Floor : public SDLGameObject
{
public:
	Floor(const LoaderParams* p_Params);
	~Floor();
	virtual void draw();
	virtual void update();
	virtual void clean() {};

	void setSpeed(int value) { moveSpeed = value; }
	int getSpeed() { return moveSpeed; }



private:
	int moveSpeed = 2;

	SDL_Rect rect;

	void playerOnGround();

	void setRect();

	bool checkCollision(SDL_Rect rect1, SDL_Rect rect2);

	bool isActice = true;
	bool isOutWindow = false;
	void move_floor();
};

