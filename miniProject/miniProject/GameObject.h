#pragma once

#include "LoaderParams.h"
using namespace std;

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

	void setActive(bool active) { this->active = active; }
	bool getActive() { return this->active; }

protected:

	bool active = true;
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};