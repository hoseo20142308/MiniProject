#pragma once

#include <SDL.h>
#include "Vector2D.h"
#include <vector>

class InputHandler
{
public:

	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};

	// mouse button events
	std::vector<bool> m_mouseButtonStates;

	// mouse motion event
	Vector2D* m_mousePosition;

	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear 
	bool isKeyDown(SDL_Scancode);
	bool getMouseButtonState(int);
	void onMouseMove(SDL_Event event);
	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
	void onKeyDown();
	void onKeyUp();
	void reset();
	Vector2D* GetMousePosition();

	const Uint8* m_keystates;
	
private:



	InputHandler();
	~InputHandler() {};
	static InputHandler* s_pInstance;
};


typedef InputHandler TheInputHandler;
