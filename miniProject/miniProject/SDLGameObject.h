#pragma once

#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	SDLGameObject(const LoaderParams* pParams, int type);
	virtual void draw();
	virtual void update();
	virtual void clean();

	Vector2D& getPosition() { return m_position; }
	int getWidth() { return m_dst_width; }
	int getHeight() { return m_dst_height; }


protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	// play, maker 구분 변수
	int type;

	int m_width;
	int m_height;
	int m_dst_width;
	int m_dst_height;
	int m_currentRow;
	int m_currentFrame;
	int m_numFrames;

	std::string m_textureID;
};