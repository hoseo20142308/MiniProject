#include "MenuButton.h"
#include "InputHandler.h"
#include "Vector2D.h"

MenuButton::MenuButton(const LoaderParams * pParams) : SDLGameObject(pParams)
{
}

void MenuButton::draw()
{
	SDLGameObject::draw();	// use hte base class drawing
}

void MenuButton::update()
{
	SDLGameObject::update();

	Vector2D* pMousePos = TheInputHandler::Instance()->GetMousePosition();
	if (pMousePos->GetX() < (m_position.GetX() + m_width)
		&& pMousePos->GetX() > m_position.GetX()
		&& pMousePos->GetY() < (m_position.GetY() + m_height)
		&& pMousePos->GetY() > m_position.GetY())
	{
		if (TheInputHandler::Instance()->getMouseButtonState(InputHandler::LEFT) && m_bReleased) 
		{
			m_currentFrame = CLICKED;
			m_callback(); // call our callback function
			m_bReleased = false;
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(InputHandler::LEFT)) 
		{
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}
	}
	else {
		m_currentFrame = MOUSE_OUT;
	}

}

void MenuButton::clean()
{
	SDLGameObject::clean();
}

MenuButton::MenuButton(const LoaderParams * pParams, void(*callback)()) : SDLGameObject(pParams), m_callback(callback)
{
}
