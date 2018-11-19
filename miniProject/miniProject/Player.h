#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject
{
	
public:

	enum CharacterState
	{
		RUNNING,
		JUMPING,
		FALLING,
		HOVERING,
		HURT
	};

	Player(const LoaderParams* p_Params);
	//void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

	void setState(CharacterState c_state) { state = c_state; }
	CharacterState getState() { return state; }

	SDL_Rect getRect() { return rect; }

private:

	// ���� ���� ����
	int jumpLimit = 150;	// �ִ� ���� ����
	int jumpSpeed = -8;		// ���� �ӵ�
	int jumpDist = 0;		// ���� �Ÿ�

	SDL_Rect rect;	// �浹üũ�� ���� ��Ʈ

	void setRect();

	bool isStateChange = true;		// ���°� �ٲ������ �˱� ���� ����

	float value_Gravity = 5;		// �߷� ��
	CharacterState state = FALLING;	// ĳ������ ����
	void setSprite();		// ���º� ��������Ʈ �̹��� �缳��
	void setFrame();		// ��������Ʈ �̹��� �� ��� ������ �ٸ��⿡ currentFrame �缳��
	void handleInput();		// �Է� �̺�Ʈ
	void onGravity();		// �߷�
	void jump();
};