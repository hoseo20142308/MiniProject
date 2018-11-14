#pragma once

#include <iostream>
#include <SDL_image.h>
#include "SDL.h"
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
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

private:
	Game() {};

	// create the s_pInstance member variable
	static Game* s_pInstance;

	bool allTextureLoad();

	SDL_Window * m_pWindow;

	SDL_Renderer* m_pRenderer;

	// 주요 게임오브젝트
	Player* player;

	std::vector<SDLGameObject*> m_gameObjects;

	TextureManager* m_textureManager;

	bool m_bRunning;
};

// create the typedef
typedef Game TheGame;