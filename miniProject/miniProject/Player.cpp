#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw();	// we now use SDLGameObject
	setRect();	// 렉트 값 설정
}
void Player::update()
{
	setSprite();
	
	onGravity();
	handleInput();	// add our function

	setFrame();
	
	SDLGameObject::update();
}

void Player::setRect()
{
	switch (state)
	{
	case Player::RUNNING:
		rect.x = m_position.GetX() + 35;
		rect.y = m_position.GetY() + 15;
		rect.w = 65;
		rect.h = 100;
		break;
	case Player::JUMPING:
		rect.x = m_position.GetX() + 25;
		rect.y = m_position.GetY() + 10;
		rect.w = 65;
		rect.h = 80;
		break;
	case Player::FALLING:
		rect.x = m_position.GetX() + 20;
		rect.y = m_position.GetY() + 50;
		rect.w = 65;
		rect.h = 80;
		break;
	case Player::HOVERING:
		break;
	case Player::HURT:
		break;
	default:
		break;
	}
}

void Player::setSprite()
{
	if (isStateChange)
	{
		switch (state)
		{
		case Player::RUNNING:
			m_textureID = "animate_dekulink_running";
			break;
		case Player::JUMPING:
			m_textureID = "animate_dekulink_jumping";
			break;
		case Player::FALLING:
			m_textureID = "animate_dekulink_falling";
			break;
		case Player::HOVERING:
			break;
		case Player::HURT:
			break;
		default:
			break;
		}
	}
}

void Player::setFrame()
{
	switch (state)
	{
	case Player::RUNNING:
		m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
		break;
	case Player::JUMPING:
		m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
		break;
	case Player::FALLING:
		m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
		break;
	case Player::HOVERING:
		break;
	case Player::HURT:
		break;
	default:
		break;
	}

}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
}

void Player::onGravity()
{
	switch (state)
	{
	case Player::RUNNING:
		m_velocity.setX(0);
		m_velocity.setY(0);
		break;
	case Player::JUMPING:
		m_velocity.setX(0);
		m_velocity.setY(0);
		break;
	case Player::FALLING:
		m_velocity.setX(0);
		m_velocity.setY(5);
		break;
	case Player::HOVERING:
		m_velocity.setX(0);
		m_velocity.setY(2);
		break;
	case Player::HURT:
		m_velocity.setX(0);
		m_velocity.setY(0);
		break;
	default:
		m_velocity.setX(0);
		m_velocity.setY(0);
		break;
	}
}
