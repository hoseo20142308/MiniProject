#pragma once

#include "GameState.h"

class GameStateMachine
{
public:
	void changeState(GameState* pState);
	void popState();
	void pushState(GameState* pState);

	void update();
	void render();
private:
	vector<GameState*> m_gameStates;
	GameState* m_currentState;
	GameState* m_prevState;
};

