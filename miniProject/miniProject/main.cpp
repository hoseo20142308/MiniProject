#include "Game.h"

Game* g_game = 0;	// our Game object

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	g_game = new Game();
	g_game->init("MiniProject", 100, 100, 640, 480, false);

	while (g_game->running())
	{
		frameStart = SDL_GetTicks();
		g_game->handleEvents();
		g_game->update();
		g_game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	
	g_game->clean();
	
	return 0;
}