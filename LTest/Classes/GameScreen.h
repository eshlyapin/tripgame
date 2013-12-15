#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "GameObject.h"
#include "InputLayer.h"

#include "cocos2d.h"
#include <vector>
#include "pugixml.hpp"

class GameScreen;
typedef std::vector<GameScreen*> ScreenArray;

class GameScreen : public cocos2d::CCScene
{
	std::vector<GameObject*> listOfObjects;
	bool LoadObjects(const std::string& name);
	std::string GetBackgroundPath(const pugi::xml_document& doc);
protected:
	cocos2d::CCLayer* mBackgroundLayer;
	ObjectLayer* mObjectLayer;

	GameScreen() {}
	cocos2d::CCLayer* LoadBackground(const std::string& file);
public:    

	virtual bool init();  
	virtual ~GameScreen();

	CREATE_FUNC(GameScreen);
};

#endif