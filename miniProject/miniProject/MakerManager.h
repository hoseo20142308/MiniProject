#pragma once

#include "MakerState.h"
#include "Vector2D.h"

class MakerManager
{
public:

	void update();

	static MakerManager* Instance();

	bool getOnUI() { return onUI; }

	// ���� ������Ʈ ���� �Լ�
	static void make_enemy_flower();
	static void make_enemy_dragonfly();
	static void make_floor_short();
	static void make_floor_middle();
	static void make_floor_long();
	static void make_etc_sign();
	static void make_etc_flag();

private:

	Vector2D s_position;

	MakerManager();

	bool onUI;

	Uint32 InputTime;
	Uint32 InputCheck;
	float delayInput = 500.0f;

	static MakerManager* s_pInstance;

	// UI �� ���� �Լ�
	void uiSwitch();
	void scrollLeft();
	void scrollRight();
};
