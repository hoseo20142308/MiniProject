#include "Player.h"
#include "PlayState.h"
#include "GameOverState.h"
#include "ModeSelectState.h"
#include "Game.h"

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
	collisionEnemy();
	collisionFlag();
	
	handleInput();	// add our function
	
	move();		// ������Ʈ�� ���� ������ ó��
	fall();		// �߶��� ���ӽ�����Ʈ ����

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
	default:
		break;
	}

}

void Player::handleInput()
{
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
		jumpDist = 0;		// ���� �Ÿ��� �ʱ�ȭ
		m_velocity.setX(0);
		m_velocity.setY(0);
		break;
	case Player::JUMPING:
		if (jumpDist >= jumpLimit)	// �ִ� �����Ÿ��� �����ϸ�
		{
			state = FALLING;	// ���¸� ������ ���·�	
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
	default:
		m_velocity.setX(0);
		m_velocity.setY(0);
		break;
	}
}

void Player::onFloor()
{
	if(state == RUNNING || state == FALLING || state == HOVERING)
		for (int i = 0; i < PlayState::Instance()->list_floor.size(); i++)
		{
			if (checkCollision_to_Floor(dynamic_cast<SDLGameObject*>(PlayState::Instance()->list_floor[i])))
			{
				setState(RUNNING);
				printf("floor collision true\n");
				break;
			}
			else if (!checkCollision_to_Floor(dynamic_cast<SDLGameObject*>(PlayState::Instance()->list_floor[i])) && state == RUNNING)
			{
				setState(FALLING);
			}			
		}
}

void Player::collisionEnemy()
{
	for (int i = 0; i < PlayState::Instance()->list_enemy.size(); i++)
	{
		if (checkCollision(dynamic_cast<SDLGameObject*>(PlayState::Instance()->list_enemy[i])))
		{
			TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}
	}
}

void Player::collisionFlag()
{
	for (int i = 0; i < PlayState::Instance()->list_flag.size(); i++)
	{
		if (checkCollision(dynamic_cast<SDLGameObject*>(PlayState::Instance()->list_flag[i])))
		{
			TheGame::Instance()->getStateMachine()->changeState(ModeSelectState::Instance());
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
		default:
			break;
		}

		inputSuccessTime = SDL_GetTicks();
	}
}

void Player::fall()
{
	if (m_position.GetY() >= 640)
	{
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
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
