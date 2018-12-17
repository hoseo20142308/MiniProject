#include "PlayState.h"
#include "PauseState.h"
#include "MakerState.h"
#include "GameOverState.h"
#include "Game.h"
#include "Flag.h"
#include "Sign.h"

const std::string PlayState::s_playID = "PLAY";

PlayState* PlayState::s_pInstance = 0;

void PlayState::update()
{
	for (int i = 0; i < list_background.size(); i++)
	{
		list_background[i]->update();
	}

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
	for (int i = 0; i < list_background.size(); i++)
	{
		list_background[i]->draw();
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (!allTextureLoad())
	{
		printf("some Textue Loading is Failure\n");
	}

	// ¹è°æ »ðÀÔ

	GameObject* background1 = new BackGround(new LoaderParams(0, 0, 640, 410, 640, 480, "background"));
	GameObject* background2 = new BackGround(new LoaderParams(640, 0, 640, 410, 640, 480, "background"));
	list_background.push_back(background1);
	list_background.push_back(background2);

	if (MakerState::Instance()->m_gameObjects.size() >= 1)
	{
		Load_Stage_Maker();
	}
	else
	{
		Load_Stage_Tutorial();
	}

	GameObject* player = new Player(new LoaderParams(100, 207, 108, 123, "dekulink_running"));
	m_gameObjects.push_back(player);

	
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

	for (int i = 0; i < list_background.size(); i++)
	{
		list_background[i]->clean();
	}
	list_background.clear();

	allTextureClear();

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

bool PlayState::allTextureLoad()
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
	if (!TheTextureManager::Instance()->load("assets/Resources/PlayState/Flag.png",
		"flag", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resources/PlayState/Sign.png",
		"sign", TheGame::Instance()->getRenderer()))
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

	return true;
}

void PlayState::allTextureClear()
{

	TheTextureManager::Instance()->clearFromTextureMap("dekulink_running");
	TheTextureManager::Instance()->clearFromTextureMap("dekulink_jumping");
	TheTextureManager::Instance()->clearFromTextureMap("dekulink_falling");
	TheTextureManager::Instance()->clearFromTextureMap("dekulink_hovering");
	TheTextureManager::Instance()->clearFromTextureMap("background");
	TheTextureManager::Instance()->clearFromTextureMap("floor");
	TheTextureManager::Instance()->clearFromTextureMap("flower");
	TheTextureManager::Instance()->clearFromTextureMap("dragonfly");

}

void PlayState::Load_Stage_Tutorial()
{

	GameObject* floor1 = new Floor(new LoaderParams(0, 430, 33, 100, 2000, 100, "floor"));
	m_gameObjects.push_back(floor1);
	list_floor.push_back(floor1);

	GameObject* floor2 = new Floor(new LoaderParams(2200, 430, 33, 100, 3000, 100, "floor"));
	m_gameObjects.push_back(floor2);
	list_floor.push_back(floor2);

	GameObject* floor3 = new Floor(new LoaderParams(6000, 430, 33, 100, 4000, 100, "floor"));
	m_gameObjects.push_back(floor3);
	list_floor.push_back(floor3);

	GameObject* flower1 = new Enemy(new LoaderParams(2900, 380, 50, 50, "flower"));
	m_gameObjects.push_back(flower1);
	list_enemy.push_back(flower1);

	GameObject* flower2 = new Enemy(new LoaderParams(6500, 380, 50, 50, "flower"));
	m_gameObjects.push_back(flower2);
	list_enemy.push_back(flower2);

	GameObject* flower3 = new Enemy(new LoaderParams(7000, 380, 50, 50, "flower"));
	m_gameObjects.push_back(flower3);
	list_enemy.push_back(flower3);

	GameObject* flower4 = new Enemy(new LoaderParams(8000, 380, 50, 50, "flower"));
	m_gameObjects.push_back(flower4);
	list_enemy.push_back(flower4);

	GameObject* dragonfly1 = new Enemy(new LoaderParams(5800, 180, 49, 34, 98, 68, "dragonfly"));
	m_gameObjects.push_back(dragonfly1);
	list_enemy.push_back(dragonfly1);

	GameObject* dragonfly2 = new Enemy(new LoaderParams(7500, 150, 49, 34, 98, 68, "dragonfly"));
	m_gameObjects.push_back(dragonfly2);
	list_enemy.push_back(dragonfly2);

	GameObject* sign = new Sign(new LoaderParams(4900, 380, 50, 50, "sign"));
	m_gameObjects.push_back(sign);

	GameObject* flag = new Flag(new LoaderParams(9900, 370, 60, 60, "flag"));
	m_gameObjects.push_back(flag);
	list_flag.push_back(flag);



}

void PlayState::Load_Stage_Maker()
{

	for (int i = 0; i < MakerState::Instance()->m_gameObjects.size(); i++)
	{
		int posX = dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->getPosition().GetX();
		int posY = dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->getPosition().GetY();
		int srcWidth = dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->getrscWidth();
		int srcHeight = dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->getrscHeight();
		int dstWidth = dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->getWidth();
		int dstHeight = dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->getHeight();

		if (dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->get_textureID() == "dragonfly")
		{
			GameObject* enemy = new Enemy(new LoaderParams(posX, posY, srcWidth, srcHeight, dstWidth, dstHeight, "dragonfly"));

			m_gameObjects.push_back(enemy);
			list_enemy.push_back(enemy);
		}
		else if (dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->get_textureID() == "flower")
		{
			GameObject* enemy = new Enemy(new LoaderParams(posX, posY, srcWidth, srcHeight, dstWidth, dstHeight, "flower"));

			m_gameObjects.push_back(enemy);
			list_enemy.push_back(enemy);
		}
		else if (dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->get_textureID() == "floor")
		{
			GameObject* floor = new Floor(new LoaderParams(posX, posY, srcWidth, srcHeight, dstWidth, dstHeight, "floor"));

			m_gameObjects.push_back(floor);
			list_floor.push_back(floor);
		}
		else if (dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->get_textureID() == "flag")
		{
			GameObject* flag = new Flag(new LoaderParams(posX, posY, srcWidth, srcHeight, dstWidth, dstHeight, "flag"));

			m_gameObjects.push_back(flag);
			list_flag.push_back(flag);
		}
		else if (dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->get_textureID() == "sign")
		{
			GameObject* sign = new Sign(new LoaderParams(posX, posY, srcWidth, srcHeight, dstWidth, dstHeight, "sign"));

			m_gameObjects.push_back(sign);
		}
	}
}
