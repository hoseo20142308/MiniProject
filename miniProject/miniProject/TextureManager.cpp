#include "TextureManager.h"

bool TextureManager::load(std::string fileName, std::string   id,
	SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0) {
		return false;
	}

	SDL_Texture* pTexture =
		SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture != 0) {
		m_textureMap[id] = pTexture;
		return true;
	}

	return false;
}

void TextureManager::draw(std::string id,
	int x, int y, int width, int height, int dst_width, int dst_height, 
	SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = width;
	srcRect.h = height;
	destRect.w = dst_width;
	destRect.h = dst_height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id],
		&srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y,
	int width, int height, int dst_width, int dst_height,  int currentRow, int currentFrame,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = width;
	srcRect.h = height;
	destRect.w = dst_width;
	destRect.h = dst_height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
		&destRect, 0, 0, flip);
}

void TextureManager::drawTile(std::string id, int x, int y, int width, int height, int dst_width, int dst_height, int currentRow, int currentFrame, SDL_Renderer * pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * 0;
	srcRect.y = height * 0;
	srcRect.w = width;
	srcRect.h = height;

	destRect.w = width;
	destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);

	srcRect.x = width * 1;
	srcRect.y = height * 0;
	srcRect.w = width;
	srcRect.h = height;

	for (int i = 0; i < dst_width - width * 2; i += width)
	{
		
		destRect.x += width;

		SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
	}

	srcRect.x = width * 2;
	srcRect.y = height * 0;
	srcRect.w = width;
	srcRect.h = height;

	destRect.x += width;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

TextureManager* TextureManager::Instance()
{
	static TextureManager* s_pInstance = 0;
	if (s_pInstance == 0)
	{
		s_pInstance = new TextureManager();
		return s_pInstance;
	}
	return s_pInstance;
}

void TextureManager::clearFromTextureMap(std::string id)
{
	m_textureMap.erase(id);
}
