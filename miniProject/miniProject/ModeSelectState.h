#pragma once

#include "GameState.h"

class ModeSelectState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_modeSelectID; }

	static ModeSelectState* Instance();
private:
	ModeSelectState() {};

	static void s_menuToTutorial();
	static void s_menuToMaker();

	static const std::string s_modeSelectID;
	static ModeSelectState* s_pInstance;

};

