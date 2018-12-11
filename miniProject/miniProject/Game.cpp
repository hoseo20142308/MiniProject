#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"

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

		m_pGameStateMachine = new GameStateMachine;
		m_pGameStateMachine->changeState(MenuState::Instance());

		m_bRunning = true;

		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

		if (!allTextureLoad())
		{
			return false;
		}
		
		// 플레이어 객체 생성
		player = new Player(new LoaderParams(100, 100, 108, 123, "animate_dekulink_running"));

		// 배경 생성
		m_backgrounds.push_back(new BackGround(new LoaderParams(0, 0, 640, 480, "background")));
		m_backgrounds.push_back(new BackGround(new LoaderParams(640, 0, 640, 480, "background")));

		// 출력할 배열에 플레이어 저장
		m_gameObjects.push_back(player);

		m_gameObjects.push_back(new Floor(new LoaderParams(100, 400, 80, 50, "floor")));
		


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
	
	// 배경 출력
	/*for (std::vector<GameObject*>::size_type i = 0;
		i != m_backgrounds.size(); i++)
	{
		m_backgrounds[i]->draw();
	}
	
	// 게임오브젝트 출력
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}*/

	m_pGameStateMachine->render();




	SDL_RenderPresent(m_pRenderer);	// 화면 제시하기
}

void Game::update()
{
	// 배경 업데이트
	/*for (std::vector<GameObject*>::size_type i = 0;
		i != m_backgrounds.size(); i++)
	{
		m_backgrounds[i]->update();
	}

	// 게임오브젝트 업데이트
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}*/

	m_pGameStateMachine->update();
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

bool Game::allTextureLoad()
{
	if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
		"animate", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resource/DekuLink_Running.png",
		"animate_dekulink_running", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resource/DekuLink_Jumping.png",
		"animate_dekulink_jumping", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resource/DekuLink_Falling.png",
		"animate_dekulink_falling", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resource/BackGround.png",
		"background", m_pRenderer))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resource/Floor.png",
		"floor", m_pRenderer))
	{
		return false;
	}


	return true;
}
