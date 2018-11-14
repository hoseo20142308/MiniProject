#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject
{
	enum CharacterState
	{
		RUNNING,
		JUMPING,
		FALLING,
		HOVERING,
		HURT
	};
public:
	Player(const LoaderParams* p_Params);
	//void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw();
	virtual void update();
	virtual void clean() {};
private:
	bool isStateChange = true;		// ���°� �ٲ������ �˱� ���� ����

	float value_Gravity = 5;		// �߷� ��
	CharacterState state = FALLING;	// ĳ������ ����
	void setSprite();		// ���º� ��������Ʈ �̹��� �缳��
	void setFrame();		// ��������Ʈ �̹��� �� ��� ������ �ٸ��⿡ currentFrame �缳��
	void handleInput();		// �Է� �̺�Ʈ
	void onGravity();		// �߷�
};