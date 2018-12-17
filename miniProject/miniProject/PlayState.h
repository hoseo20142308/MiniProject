#pragma once

#include "GameState.h"
#include "GameObject.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }

	static PlayState* Instance();

	// 게임오브젝트 배열
	vector<GameObject*> m_gameObjects;
	vector<GameObject*> list_floor;
	vector<GameObject*> list_enemy;
	vector<GameObject*> list_flag;
	vector<GameObject*> list_background;

private:

	PlayState() {};
	static const std::string s_playID;
	static PlayState* s_pInstance;

	bool allTextureLoad();
	void allTextureClear();

	// stage load
	void Load_Stage_Tutorial();
	void Load_Stage_Maker();

};

