#include "MakerManager.h"
#include "MakerState.h"
#include "InputHandler.h"
#include "SDLGameObject.h"

#include "Enemy.h"
#include "Flag.h"
#include "Floor.h"
#include "Sign.h"

MakerManager* MakerManager::s_pInstance = 0;

void MakerManager::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_TAB))
	{
		uiSwitch();
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		scrollLeft();
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		scrollRight();
	}
}

MakerManager * MakerManager::Instance()
{
	if (s_pInstance == 0)
	{
		s_pInstance = new MakerManager();
		return s_pInstance;
	}
	return s_pInstance;
}

MakerManager::MakerManager() : s_position(0.0f, 0.0f)
{
	InputCheck = SDL_GetTicks();
	InputTime = SDL_GetTicks();
}

void MakerManager::make_enemy_flower()
{
	GameObject* flower = new Enemy(new LoaderParams(0, 0, 50, 50, "flower"), 2);

	MakerState::Instance()->m_gameObjects.push_back(flower);
}

void MakerManager::make_enemy_dragonfly()
{
	GameObject* dragonfly = new Enemy(new LoaderParams(0, 0, 49, 34, "dragonfly"), 2);

	MakerState::Instance()->m_gameObjects.push_back(dragonfly);
}

void MakerManager::make_floor_short()
{
	GameObject* floor = new Floor(new LoaderParams(0, 0, 33, 100, 100, 100, "floor"), 2);

	MakerState::Instance()->m_gameObjects.push_back(floor);
}

void MakerManager::make_floor_middle()
{
	GameObject* floor = new Floor(new LoaderParams(0, 0, 33, 100, 500, 100, "floor"), 2);

	MakerState::Instance()->m_gameObjects.push_back(floor);
}

void MakerManager::make_floor_long()
{
	GameObject* floor = new Floor(new LoaderParams(0, 0, 33, 100, 1500, 100, "floor"), 2);

	MakerState::Instance()->m_gameObjects.push_back(floor);
}

void MakerManager::make_etc_sign()
{
	GameObject* sign = new Sign(new LoaderParams(0, 0, 54, 66, "sign"), 2);

	MakerState::Instance()->m_gameObjects.push_back(sign);
}

void MakerManager::make_etc_flag()
{
	GameObject* flag = new Flag(new LoaderParams(0, 0, 60, 60, "flag"), 2);

	MakerState::Instance()->m_gameObjects.push_back(flag);
}

void MakerManager::uiSwitch()
{
	InputTime = SDL_GetTicks();
	if (InputTime - InputCheck > delayInput)
	{
		if (onUI)
		{
			onUI = false;
		}
		else if (!onUI)
		{
			onUI = true;
		}
		InputCheck = SDL_GetTicks();
	}
}

void MakerManager::scrollLeft()
{
	Vector2D moveVelo(5, 0);
	if (s_position.GetX() <= 0)
	{
		return;
	}
	s_position -= moveVelo;
	for (int i = 0; i < MakerState::Instance()->m_gameObjects.size(); i++)
	{
		dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->getPosition() += moveVelo;
	}

}

void MakerManager::scrollRight()
{
	Vector2D moveVelo(5, 0);
	/*if (s_position.GetX() <= 0)
	{
		return;
	}*/
	s_position += moveVelo;
	for (int i = 0; i < MakerState::Instance()->m_gameObjects.size(); i++)
	{
		dynamic_cast<SDLGameObject*>(MakerState::Instance()->m_gameObjects[i])->getPosition() -= moveVelo;
	}
}
