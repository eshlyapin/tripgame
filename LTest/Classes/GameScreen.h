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
	bool LoadObjects(const std::string& name);	
protected:
	GameObjectArray mObjectsArray;
	cocos2d::CCLayer* mBackgroundLayer;
	GameScreen() {}	
public:    

	virtual bool init(const std::string& scenename);  
	virtual ~GameScreen() = 0;
	
	GameObjectArray				GetObjectArrayByName(const std::string& name);
	GameObject*					GetObjectByName(const std::string& name);
	void						SetStrategyToGroup(GameObjectArray& group, ObjectStrategy* strategy);
	void						SetStrategyToGroup(const std::string& name, ObjectStrategy* strategy);
};

#endif