#pragma once

#include <iostream>
#include <SDL_image.h>
#include <map>


class TextureManager
{
public:

	std::map<std::string, SDL_Texture*> m_textureMap;

	bool load(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	// 함수 추가
	static TextureManager* Instance();

	//유일객체 디자인패턴을 위한 코드 수정, 기존 코드 중 불필요한 코드 제거 
	//  생성자 조정 
private:
	TextureManager() {}


};

// type  추가
typedef TextureManager TheTextureManager;