#pragma once

#include "GameState.h"

class GameOverState : public GameState
{
public:
	
	//virtual void update();
	//virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_gameOverID; }

	static GameOverState* Instance();

private:

	GameOverState() {};

	static void s_gameOverToMain();
	static void s_restartPlay();
	static const std::string s_gameOverID;

	static GameOverState* s_pInstance;
};

