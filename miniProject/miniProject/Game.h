#pragma once

#include <iostream>
#include <SDL_image.h>
#include "SDL.h"
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Floor.h"
#include "BackGround.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include <vector>



class Game
{
public:
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	bool running() { return m_bRunning; }

	static Game* Instance();

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

private:
	Game() {};

	GameStateMachine* m_pGameStateMachine;

	// create the s_pInstance member variable
	static Game* s_pInstance;

	SDL_Window * m_pWindow;

	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
};

// create the typedef
typedef Game TheGame;