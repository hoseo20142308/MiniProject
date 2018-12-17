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
		HOVERING
	};

	Player(const LoaderParams* p_Params);
	
	virtual void draw();
	virtual void update();
	virtual void clean() {};

	void setState(CharacterState c_state) { state = c_state; }
	CharacterState getState() { return state; }

private:

	// �Է� ������ ó�� ����
	Uint32 inputTime, inputSuccessTime;
	float delay_Input = 300.0f;

	// ���� ���� ����
	int jumpLimit = 200;	// �ִ� ���� ����
	int jumpSpeed = 10;		// ���� �ӵ�
	int jumpDist = 0;		// ���� �Ÿ�

	// ȣ���� 


	bool isStateChange = true;		// ���°� �ٲ������ �˱� ���� ����

	float value_Gravity = 5;		// �߷� ��
	CharacterState state = FALLING;	// ĳ������ ����
	void setSprite();		// ���º� ��������Ʈ �̹��� �缳��
	void setFrame();		// ��������Ʈ �̹��� �� ��� ������ �ٸ��⿡ currentFrame �缳��
	void handleInput();		// �Է� �̺�Ʈ
	void move();			// ���¿� ���� �̵� ó�� �Լ�

	
	void jump();			// ���� �Լ�
	
	void fall();			// �߶� �Լ�


	void onFloor();			// ���� �浹üũ �Լ�
	void collisionEnemy();	// �� �浹üũ �Լ�
	void collisionFlag();	// ��� �浹üũ �Լ�

	bool checkCollision(SDLGameObject* coll);			// ���� ������Ʈ �浹üũ �˻� �Լ�
	bool checkCollision_to_Floor(SDLGameObject* coll);	// ���� �浹üũ �˻� �Լ�
};