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
	vector<GameObject*> list_floors;

private:

	PlayState() {};
	static const std::string s_playID;
	static PlayState* s_pInstance;

};

