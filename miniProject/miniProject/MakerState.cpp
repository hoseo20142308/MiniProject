#include "MakerState.h"
#include "MakerManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "BackGround.h"
#include <iostream>

const std::string MakerState::s_MakerID = "MAKER";

MakerState* MakerState::s_pInstance = 0;

void MakerState::update()
{
	MakerManager::Instance()->update();

	for (int i = 0; i < list_background.size(); i++)
	{
		list_background[i]->update();
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	if (MakerManager::Instance()->getOnUI())
	{
		for (int i = 0; i < list_UI.size(); i++)
		{
			list_UI[i]->update();
		}
	}
}

void MakerState::render()
{
	for (int i = 0; i < list_background.size(); i++)
	{
		list_background[i]->draw();
	}
	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	if (MakerManager::Instance()->getOnUI())
	{
		for (int i = 0; i < list_UI.size(); i++)
		{
			list_UI[i]->draw();
		}
	}
}

bool MakerState::onEnter()
{
	m_gameObjects.clear();
	MakerManager::Instance()->set_sPosition(new Vector2D(0, 0));

	if(!allTextureLoad())
	{
		TheGame::Instance()->quit();
	}

	GameObject* panel = new SDLGameObject(new LoaderParams(0, 0, 640, 480, "makerpanel"));
	
	GameObject* enemymakebutton1 = new MenuButton(new LoaderParams(420, 10, 60, 60, "flowermakebutton"), MakerManager::Instance()->make_enemy_flower);
	GameObject* enemymakebutton2 = new MenuButton(new LoaderParams(490, 10, 60, 60, "dragonflymakebutton"), MakerManager::Instance()->make_enemy_dragonfly);

	GameObject* floormakebutton1 = new MenuButton(new LoaderParams(420, 100, 60, 60, "floormakebutton"), MakerManager::Instance()->make_floor_short);
	GameObject* floormakebutton2 = new MenuButton(new LoaderParams(490, 100, 60, 60, "floormakebutton"), MakerManager::Instance()->make_floor_middle);
	GameObject* floormakebutton3 = new MenuButton(new LoaderParams(560, 100, 60, 60, "floormakebutton"), MakerManager::Instance()->make_floor_long);

	GameObject* etcmakebutton1 = new MenuButton(new LoaderParams(420, 200, 60, 60, "signmakebutton"), MakerManager::Instance()->make_etc_sign);
	GameObject* etcmakebutton2 = new MenuButton(new LoaderParams(490, 200, 60, 60, "flagmakebutton"), MakerManager::Instance()->make_etc_flag);

	GameObject* savebutton = new MenuButton(new LoaderParams(480, 420, 100, 25, "playbutton"), MakerManager::Instance()->play);



	GameObject* background1 = new BackGround(new LoaderParams(0, 0, 640, 410, 640, 480, "background"), 3);
	GameObject* background2 = new BackGround(new LoaderParams(640, 0, 640, 410, 640, 480, "background"), 3);

	list_UI.push_back(panel);
	list_UI.push_back(enemymakebutton1);
	list_UI.push_back(enemymakebutton2);
	list_UI.push_back(floormakebutton1);
	list_UI.push_back(floormakebutton2);
	list_UI.push_back(floormakebutton3);
	list_UI.push_back(etcmakebutton1);
	list_UI.push_back(etcmakebutton2);
	list_UI.push_back(savebutton);

	list_background.push_back(background1);
	list_background.push_back(background2);

	std::cout << "entering StageSelectState\n";
	return true;
}

bool MakerState::onExit()
{
	/*for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();*/

	for (int i = 0; i < list_background.size(); i++)
	{
		list_background[i]->clean();
	}
	list_background.clear();

	for (int i = 0; i < list_UI.size(); i++)
	{
		list_UI[i]->clean();
	}
	list_UI.clear();

	allTextureClear();

	std::cout << "exiting StageSelectState\n";
	return true;
}

MakerState * MakerState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new MakerState();

		return s_pInstance;
	}
	return s_pInstance;
}

void MakerState::s_menuToSave()
{
	TheGame::Instance()->quit();
	std::cout << "Maker button clicked" << endl;
	/*TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
	std::cout << "Play button clicked" << endl;*/
}

bool MakerState::allTextureLoad()
{
	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/background.png", "background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/button_make_dragonfly.png", "dragonflymakebutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/button_make_flag.png", "flagmakebutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/button_make_floor.png", "floormakebutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/button_make_flower.png", "flowermakebutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/button_make_sign.png", "signmakebutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/button_play.png", "playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/dragonfly.png", "dragonfly", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/flag.png", "flag", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/floor.png", "floor", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/flower.png", "flower", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/sign.png", "sign", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/MakerState/ui_makerpanel.png", "makerpanel", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	return true;
}

void MakerState::allTextureClear()
{
	TheTextureManager::Instance()->clearFromTextureMap("background");
	TheTextureManager::Instance()->clearFromTextureMap("dragonflymakebutton");
	TheTextureManager::Instance()->clearFromTextureMap("flagmakebutton");
	TheTextureManager::Instance()->clearFromTextureMap("floormakebutton");
	TheTextureManager::Instance()->clearFromTextureMap("flowermakebutton");
	TheTextureManager::Instance()->clearFromTextureMap("signmakebutton");
	TheTextureManager::Instance()->clearFromTextureMap("savebutton");
	TheTextureManager::Instance()->clearFromTextureMap("dragonfly");
	TheTextureManager::Instance()->clearFromTextureMap("flag");
	TheTextureManager::Instance()->clearFromTextureMap("floor");
	TheTextureManager::Instance()->clearFromTextureMap("flower");
	TheTextureManager::Instance()->clearFromTextureMap("sign");
	TheTextureManager::Instance()->clearFromTextureMap("makerpanel");
}
