#include "ModeSelectState.h"
#include "MakerState.h"
#include "PlayState.h"
#include "Game.h"
#include "MenuButton.h"
#include <iostream>

const std::string ModeSelectState::s_modeSelectID = "MODESELECT";

ModeSelectState* ModeSelectState::s_pInstance = 0;

void ModeSelectState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void ModeSelectState::render()
{
	// nothing for now
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool ModeSelectState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/Resources/ModeSelectState/button_tutorial.png", "tutorialbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/Resources/ModeSelectState/button_maker.png", "makerbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "tutorialbutton"), s_menuToTutorial);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "makerbutton"), s_menuToMaker);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering MenuState\n";
	return true;
}

bool ModeSelectState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();


	PlayState::Instance()->list_background.clear();
	PlayState::Instance()->list_enemy.clear();
	PlayState::Instance()->list_floor.clear();
	PlayState::Instance()->list_flag.clear();
	PlayState::Instance()->m_gameObjects.clear();

	MakerState::Instance()->list_background.clear();
	MakerState::Instance()->list_UI.clear();
	MakerState::Instance()->m_gameObjects.clear();



	TheTextureManager::Instance()->clearFromTextureMap("tutorialbutton");
	TheTextureManager::Instance()->clearFromTextureMap("makerbutton");

	std::cout << "exiting MenuState\n";
	return true;
}

ModeSelectState * ModeSelectState::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new ModeSelectState();

		return s_pInstance;
	}
	return s_pInstance;
}

void ModeSelectState::s_menuToTutorial()
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
	std::cout << "Play button clicked" << endl;
}

void ModeSelectState::s_menuToMaker()
{
	TheGame::Instance()->getStateMachine()->changeState(MakerState::Instance());
	std::cout << "Maker button clicked" << endl;
}