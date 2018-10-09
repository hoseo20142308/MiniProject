#include "Game.h"
#include "TextureManager.h"
#include "ECS.h"
#include "Components.h"
#include "GameObject.h"

Manager manager;
GameObject* backGround1;
GameObject* backGround2;

auto& player(manager.addEntity());
//auto& enemy(manager.addEntity());

SDL_Renderer* Game::renderer = nullptr;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		Window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);

		if (Window != 0)
		{
			renderer = SDL_CreateRenderer(Window, -1, 0);

		}

		isRunning = true;

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		backGround1 = new GameObject("Assets/bg.png", 0, 0);
		backGround2 = new GameObject("Assets/bg.png", 640, 0);

		player.addComponent<PositionComponent>(100, 340);
		player.addComponent<SpriteComponent>("Assets/animate-alpha.png");
		

		//enemy.addComponent<PositionComponent>(300, 100);
		//enemy.addComponent<SpriteComponent>("Assets/animate.png");



		
	}
	else
	{
		return false;	// sdl could not initialize
	}
	



	return true;
}

void Game::render()
{

	// clear the renderer to the draw color
	SDL_RenderClear(renderer);	
									
	backGround1->Render();
	backGround2->Render();
	manager.draw();
	
	SDL_RenderPresent(renderer);	
}

void Game::update()
{
	backGround1->Update();
	backGround2->Update();
	manager.update();
	
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			player.getComponent<PositionComponent>().addPos(3, 0);
			break;
		default:
			break;
		}
	}
}