#include "StageSelectState.h"
#include "MakerState.h"
#include "PlayState.h"
#include "Game.h"
#include "MenuButton.h"
#include <iostream>

const std::string StageSelectState::s_stageSelectID = "STAGESELECT";

StageSelectState* StageSelectState::s_pInstance = 0;

void StageSelectState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void StageSelectState::render()
{
	// nothing for now
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool StageSelectState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/Resources/StageSelectState/button_play.png", "playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/StageSelectState/button_make.png", "makebutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/StageSelectState/button_back.png", "backbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Resources/StageSelectState/ui_stageselect.png", "stageselectwindow", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(180, 380, 100, 25, "playbutton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(280, 380, 100, 25, "makebutton"), s_menuToMake);
	GameObject* button3 = new MenuButton(new LoaderParams(380, 380, 100, 25, "backbutton"), s_menuToMake);
	GameObject* ui = new SDLGameObject(new LoaderParams(180, 30, 300, 400, "stageselectwindow"));

	m_gameObjects.push_back(ui);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	m_gameObjects.push_back(button3);

	std::cout << "entering StageSelectState\n";
	return true;
}

bool StageSelectState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("makebutton");
	TheTextureManager::Instance()->clearFromTextureMap("backbutton");
	TheTextureManager::Instance()->clearFromTextureMap("stageselectwindow");

	std::cout << "exiting StageSelectState\n";
	return true;
}

StageSelectState * StageSelectState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new StageSelectState();

		return s_pInstance;
	}
	return s_pInstance;
}

void StageSelectState::s_menuToPlay()
{
	TheGame::Instance()->quit();
	std::cout << "Maker button clicked" << endl;
	/*TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
	std::cout << "Play button clicked" << endl;*/
}

void StageSelectState::s_menuToMake()
{
	TheGame::Instance()->getStateMachine()->changeState(MakerState::Instance());
	std::cout << "Make button clicked" << endl;
}
