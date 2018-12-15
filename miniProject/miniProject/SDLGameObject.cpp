
#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams),
m_position(pParams->getX(), pParams->getY()),
m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_dst_width = pParams->getDstWidth();
	m_dst_height = pParams->getDstHeight();


	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 0;

	type = 1;
}

SDLGameObject::SDLGameObject(const LoaderParams* pParams, int type) : GameObject(pParams),
m_position(pParams->getX(), pParams->getY()),
m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_dst_width = pParams->getDstWidth();
	m_dst_height = pParams->getDstHeight();

	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 0;

	this->type = type;
}

void SDLGameObject::draw()
{
	//if (m_velocity.GetX() > 0)
	//{
	//	TextureManager::Instance()->drawFrame(m_textureID,
	//		(Uint32)m_position.GetX(), (Uint32)m_position.GetY(),
	//		m_width, m_height, m_dst_width, m_dst_height, m_currentRow, m_currentFrame,
	//		TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	//}
	//else
	//{
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.GetX(), (Uint32)m_position.GetY(),
			m_width, m_height, m_dst_width, m_dst_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer());
	//}
}

void SDLGameObject::update()
{
	if (type == 1)
	{
		m_velocity += m_acceleration;
		m_position += m_velocity;
	}
	else if (type == 2)
	{
		Vector2D* pMousePos = TheInputHandler::Instance()->GetMousePosition();
		if (pMousePos->GetX() < (m_position.GetX() + m_dst_width)
			&& pMousePos->GetX() > m_position.GetX()
			&& pMousePos->GetY() < (m_position.GetY() + m_dst_height)
			&& pMousePos->GetY() > m_position.GetY())
		{
			if (TheInputHandler::Instance()->getMouseButtonState(InputHandler::LEFT))
			{
				m_position.setX(pMousePos->GetX() - m_dst_width / 2);
				m_position.setY(pMousePos->GetY() - m_dst_height / 2);
			}
		}
	}
}

void SDLGameObject::clean()
{
}


