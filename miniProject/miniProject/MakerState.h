#pragma once

#include "GameState.h"

class MakerState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_MakerID; }

	static MakerState* Instance();

	vector<GameObject*> list_UI;
	vector<GameObject*> list_background;


private:
	MakerState() {};

	static void s_menuToSave();

	static const std::string s_MakerID;
	static MakerState* s_pInstance;

	bool allTextureLoad();
	void allTextureClear();

};

