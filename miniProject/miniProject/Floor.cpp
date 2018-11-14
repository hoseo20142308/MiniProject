#include "Floor.h"



Floor::Floor(const LoaderParams* p_Params) : SDLGameObject(p_Params)
{
	m_currentFrame = 0;
}


Floor::~Floor()
{
}

void Floor::update()
{
	move_floor();
	
	playerOnGround();

	SDLGameObject::update();
}

void Floor::playerOnGround()
{
	if (checkCollision(rect, TheGame::Instance()->PlayerIns()->getRect()))
	{
		TheGame::Instance()->PlayerIns()->setState(Player::RUNNING);
	}
}

void Floor::setRect()
{
	rect.x = m_position.GetX();
	rect.y = m_position.GetY();
	rect.w = m_width;
	rect.h = m_height;
}

bool Floor::checkCollision(SDL_Rect rect1, SDL_Rect rect2)
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
}

void Floor::move_floor()
{
	m_velocity.setX(0);
}

void Floor::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
	setRect();
}