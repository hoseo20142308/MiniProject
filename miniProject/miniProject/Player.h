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

	// 점프 관련 변수
	int jumpLimit = 150;	// 최대 점프 높이
	int jumpSpeed = -8;		// 점프 속도
	int jumpDist = 0;		// 점프 거리

	SDL_Rect rect;	// 충돌체크를 위한 렉트

	void setRect();

	bool isStateChange = true;		// 상태가 바뀌었는지 알기 위한 변수

	float value_Gravity = 5;		// 중력 값
	CharacterState state = FALLING;	// 캐릭터의 상태
	void setSprite();		// 상태별 스프라이트 이미지 재설정
	void setFrame();		// 스프라이트 이미지 별 모션 갯수가 다르기에 currentFrame 재설정
	void handleInput();		// 입력 이벤트
	void onGravity();		// 중력
	void jump();
};