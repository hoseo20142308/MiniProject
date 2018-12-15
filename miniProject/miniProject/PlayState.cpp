#include "PlayState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "Game.h"

const std::string PlayState::s_playID = "PLAY";

PlayState* PlayState::s_pInstance = 0;

void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			PauseState::Instance());
	}

}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/Resources/PlayState/DekuLink_Running.png",
		"dekulink_running", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resources/PlayState/DekuLink_Jumping.png",
		"dekulink_jumping", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resources/PlayState/DekuLink_Falling.png",
		"dekulink_falling", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resources/PlayState/DekuLink_Hovering.png",
		"dekulink_hovering", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resources/PlayState/BackGround.png",
		"background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resources/PlayState/Floor.png",
		"floor", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resources/PlayState/Flower.png",
		"flower", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resources/PlayState/Dragonfly.png",
		"dragonfly", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* background1 = new BackGround(new LoaderParams(0, 0, 640, 430, 640, 480, "background"));
	m_gameObjects.push_back(background1);

	GameObject* background2 = new BackGround(new LoaderParams(640, 0, 640, 430, 640, 480, "background"));
	m_gameObjects.push_back(background2);

	GameObject* player = new Player(new LoaderParams(100, 307, 108, 123, "dekulink_running"));
	m_gameObjects.push_back(player);

	GameObject* floor = new Floor(new LoaderParams(0, 430, 33, 100, 1000, 100, "floor"));
	m_gameObjects.push_back(floor);
	list_floors.push_back(floor);

	GameObject* enemy1 = new Enemy(new LoaderParams(2000, 380, 50, 50, "flower"));
	m_gameObjects.push_back(enemy1);

	GameObject* enemy2 = new Enemy(new LoaderParams(2500, 150, 49, 34, 98, 68, "dragonfly"));
	m_gameObjects.push_back(enemy2);

	
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("dekulink_running");
	TheTextureManager::Instance()->clearFromTextureMap("dekulink_jumping");
	TheTextureManager::Instance()->clearFromTextureMap("dekulink_falling");
	TheTextureManager::Instance()->clearFromTextureMap("dekulink_hovering");
	TheTextureManager::Instance()->clearFromTextureMap("background");
	TheTextureManager::Instance()->clearFromTextureMap("floor");
	TheTextureManager::Instance()->clearFromTextureMap("flower");
	TheTextureManager::Instance()->clearFromTextureMap("dragonfly");
	std::cout << "exiting PlayState\n";
	return true;
}

PlayState * PlayState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new PlayState();
		return s_pInstance;
	}
	return s_pInstance;
}
