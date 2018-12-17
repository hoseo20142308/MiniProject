#pragma once

#include "MakerState.h"
#include "Vector2D.h"

class MakerManager
{
public:

	void update();

	static MakerManager* Instance();

	bool getOnUI() { return onUI; }

	// 게임 오브젝트 생성 함수
	static void make_enemy_flower();
	static void make_enemy_dragonfly();
	static void make_floor_short();
	static void make_floor_middle();
	static void make_floor_long();
	static void make_etc_sign();
	static void make_etc_flag();

	// 플레이 버튼 클릭 시
	static void play();

	Vector2D get_sPosition() { return s_position; }
	void set_sPosition(Vector2D* vec) { s_position.setX(vec->GetX()); s_position.setY(vec->GetY()); }

private:

	Vector2D s_position;

	MakerManager();

	bool onUI;

	Uint32 InputTime;
	Uint32 InputCheck;
	float delayInput = 500.0f;

	static MakerManager* s_pInstance;

	// UI 온 오프 함수
	void uiSwitch();
	void scrollLeft();
	void scrollRight();
};

