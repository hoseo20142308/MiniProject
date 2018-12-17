#pragma once

#include <iostream>
#include <SDL_image.h>
#include <map>


typedef struct t_saveformat
{
	int posX;
	int posY;
	int s_width;
	int s_height;
	int d_width;
	int d_height;
	int type;

} SaveFormat;

class TextureManager
{
public:

	std::map<std::string, SDL_Texture*> m_textureMap;

	bool load(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height, int dst_width, int dst_height, 
		SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height, int dst_width, int dst_height, 
		int currentRow, int currentFrame,
		SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawTile(std::string id, int x, int y, int width, int height, int dst_width, int dst_height,
		int currentRow, int currentFrame,
		SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	// �Լ� �߰�
	static TextureManager* Instance();

	void clearFromTextureMap(std::string id);

	//���ϰ�ü ������������ ���� �ڵ� ����, ���� �ڵ� �� ���ʿ��� �ڵ� ���� 
	//  ������ ���� 
private:
	TextureManager() {}


};

// type  �߰�
typedef TextureManager TheTextureManager;