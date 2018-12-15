#include "Player.h"
#include "PlayState.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	inputSuccessTime = SDL_GetTicks();
}
void Player::draw()
{
	SDLGameObject::draw();	// we now use SDLGameObject
}
void Player::update()
{
	setSprite();
	
	
	onFloor();
	
	handleInput();	// add our function
	
	move();

	setFrame();
	
	SDLGameObject::update();
}

void Player::setSprite()
{
	if (isStateChange)
	{
		switch (state)
		{
		case Player::RUNNING:
			m_textureID = "dekulink_running";
			break;
		case Player::JUMPING:
			m_textureID = "dekulink_jumping";
			break;
		case Player::FALLING:
			m_textureID = "dekulink_falling";
			break;
		case Player::HOVERING:
			m_textureID = "dekulink_hovering";
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
		m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
		break;
	case Player::HURT:
		m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
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
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		jump();
	}
}

void Player::move()
{
	switch (state)
	{
	case Player::RUNNING:
		jumpDist = 0;		// 점프 거리를 초기화
		m_velocity.setX(0);
		m_velocity.setY(0);
		break;
	case Player::JUMPING:
		if (jumpDist >= jumpLimit)	// 최대 점프거리에 도달하면
		{
			state = FALLING;	// 상태를 떨어짐 상태로	
		}
		m_velocity.setX(0);
		m_velocity.setY(-jumpSpeed);
		jumpDist += jumpSpeed;
		break;
	case Player::FALLING:	
		m_velocity.setX(0);
		m_velocity.setY(10);
		break;
	case Player::HOVERING:
		m_velocity.setX(0);
		m_velocity.setY(1);
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

void Player::onFloor()
{
	if(state == RUNNING || state == FALLING || state == HOVERING)
		for (int i = 0; i < PlayState::Instance()->list_floors.size(); i++)
		{
			if (checkCollision_to_Floor(dynamic_cast<SDLGameObject*>(PlayState::Instance()->list_floors[i])))
			{
				setState(RUNNING);
			}
			else if(!checkCollision_to_Floor(dynamic_cast<SDLGameObject*>(PlayState::Instance()->list_floors[i])) && state == RUNNING)
			{
				setState(FALLING);
			}
		}

}

void Player::jump()
{
	inputTime = SDL_GetTicks();
	if (inputTime - inputSuccessTime > delay_Input)
	{
		switch (state)
		{
		case Player::RUNNING:
			setState(JUMPING);
			break;
		case Player::JUMPING:
			setState(HOVERING);
			break;
		case Player::FALLING:
			setState(HOVERING);
			break;
		case Player::HOVERING:
			setState(FALLING);
			break;
		case Player::HURT:
			break;
		default:
			break;
		}

		inputSuccessTime = SDL_GetTicks();
	}
}

bool Player::checkCollision(SDLGameObject * coll)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = m_position.GetX();
	rightA = m_position.GetX() + m_dst_width;
	topA = m_position.GetY();
	bottomA = m_position.GetY() + m_dst_height;

	//Calculate the sides of rect B
	leftB = coll->getPosition().GetX();
	rightB = coll->getPosition().GetX() + coll->getWidth();
	topB = coll->getPosition().GetY();
	bottomB = coll->getPosition().GetY() + coll->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}

bool Player::checkCollision_to_Floor(SDLGameObject * coll)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = m_position.GetX();
	rightA = m_position.GetX() + m_dst_width;
	topA = m_position.GetY() + m_dst_height - 10;
	bottomA = m_position.GetY() + m_dst_height;

	//Calculate the sides of rect B
	leftB = coll->getPosition().GetX();
	rightB = coll->getPosition().GetX() + coll->getWidth();
	topB = coll->getPosition().GetY();
	bottomB = coll->getPosition().GetY() + 10;

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}
