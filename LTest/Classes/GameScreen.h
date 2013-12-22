#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "GameScene.h"
#include "GameObject.h"
#include "InputLayer.h"

#include "cocos2d.h"
#include <vector>
#include "pugixml.hpp"

class GameScreen;
typedef std::vector<GameScreen*> ScreenArray;

class GameScreen : public GameScene
{
	std::vector<GameObject*> listOfObjects;
	bool LoadObjects(const std::string& name);	
protected:
	cocos2d::CCLayer* mBackgroundLayer;
	ObjectLayer* mObjectLayer;

	GameScreen() {}	
public:    

	virtual bool init();  
	virtual ~GameScreen();

	CREATE_FUNC(GameScreen);
};

#endif