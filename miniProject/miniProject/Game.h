#pragma once

#include <iostream>
#include <SDL_image.h>
#include "SDL.h"

class Game
{
public:
	Game() {}
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return isRunning; }

	
	static SDL_Renderer* renderer;
private:
	
	SDL_Window * Window;
	bool isRunning;
};