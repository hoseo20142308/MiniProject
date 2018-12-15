#pragma once

#include "GameState.h"

class StageSelectState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_stageSelectID; }

	static StageSelectState* Instance();
private:
	StageSelectState() {};

	static void s_menuToPlay();
	static void s_menuToMake();

	static const std::string s_stageSelectID;
	static StageSelectState* s_pInstance;

};

