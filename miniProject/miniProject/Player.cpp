/*#include "Game.h"
#include <SDL_image.h>

void Player::init()
{
	//if (SDL_Init(SDL_INIT_EVERYTHING) >= 1)
	//{

		SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");

		Texture_Player = SDL_CreateTextureFromSurface(Renderer_Player, pTempSurface);

		SDL_FreeSurface(pTempSurface);

		srcRectangle_P.w = 128;
		srcRectangle_P.h = 82;

		pos_x = 0;
		pos_y = 50;

		dstRectangle_P.x = pos_x;
		dstRectangle_P.y = pos_y;

		dstRectangle_P.w = srcRectangle_P.w;
		dstRectangle_P.h = srcRectangle_P.h;
	/*}
	else
		return false;

	return true;*/
//}