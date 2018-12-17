#include "Floor.h"
#include "TextureManager.h"


Floor::Floor(const LoaderParams* p_Params) : SDLGameObject(p_Params)
{
	m_currentFrame = 0;
	m_velocity.setX(-moveSpeed);
}

Floor::Floor(const LoaderParams * p_Params, int type) : SDLGameObject(p_Params)
{
	m_velocity.setX(-moveSpeed);
	this->type = type;
}

void Floor::draw()
{
	TextureManager::Instance()->drawTile(m_textureID,
		(Uint32)m_position.GetX(), (Uint32)m_position.GetY(),
		m_width, m_height, m_dst_width, m_dst_height, m_currentRow, m_currentFrame,
		TheGame::Instance()->getRenderer());
}

void Floor::update()
{
	check_Pass();

	SDLGameObject::update();
}

void Floor::check_Pass()
{
	if (m_position.GetX() - m_dst_width < m_dst_width && type != 2)
	{
		this->setActive(false);
	}
}

/*void Floor::playerOnGround()
{
	switch (TheGame::Instance()->PlayerIns()->getState())
	{
		case Player::RUNNING:
			break;
		case Player::JUMPING:
			break;
		case Player::HOVERING:
			break;
		case Player::FALLING :
			if (checkCollision(rect, TheGame::Instance()->PlayerIns()->getRect()))
			{
				TheGame::Instance()->PlayerIns()->setState(Player::RUNNING);
			}
			break;
		
	}

	
}*/

/*bool Floor::checkCollision(SDL_Rect rect1, SDL_Rect rect2)
{
	// �簢���� �� 
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	// rect A�� ���� ����մϴ�. 
	leftA = rect1.x; 
	rightA = rect1.x + rect1.w;
	topA = rect1.y;
	bottomA = rect1.y + rect1.h;
	// rect B�� ���� ����մϴ�. 
	leftB = rect2.x;
	rightB = rect2.x + rect2.w;
	topB = rect2.y;
	bottomB = rect2.y + rect2.h;
	// A�� �� �� B�� B �ۿ����� ���
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; } 
	if (rightA <= leftB) { return false; } 
	if (leftA >= rightB) { return false; } 
	// A�� ���� ��� �͵� B �ܺο� ������
	return true;
}*/
