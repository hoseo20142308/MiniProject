#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

		//m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
			"animate", m_pRenderer))
		{
			return false;
		}

		m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		
		m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));


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
	SDL_RenderClear(m_pRenderer);	// draw color로 render 지우기
									// 원본 사각형과 대상 사각형의 위치와 크기에 따라 화면에 다르게 나타남...
									//SDL_RenderCopy(m_pRenderer, m_pTexture,
									//	&m_sourceRectangle, &m_destinationRectangle);
	
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}




	SDL_RenderPresent(m_pRenderer);	// 화면 제시하기
}

void Game::update()
{

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Game::clean()
{
	TheInputHandler::Instance()->clean();
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}

Game* Game::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new Game();
		return s_pInstance;
	}

	return s_pInstance;
}