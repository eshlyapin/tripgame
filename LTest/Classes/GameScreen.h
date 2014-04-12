#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "GameScene.h"
#include "GameObject.h"
#include "ScreenFactory.h"
#include <vector>
#include "structObject.h"
#include "DataManager.h"

class GameScreen : public GameScene
{
	bool LoadObjects(const std::string& backgroundPath);	
protected:	
	bool IsUpdate;
	virtual bool init(const std::string& backgroundPath);  

public:    

	virtual ~GameScreen() = 0;
};

#endif