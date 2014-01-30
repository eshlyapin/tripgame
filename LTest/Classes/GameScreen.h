#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "GameScene.h"
#include "GameObject.h"
#include "ScreenFactory.h"
#include <vector>
#include "structObject.h"
class GameScreen;
typedef std::vector<GameScreen*> ScreenArray;

class GameScreen : public GameScene
{
	bool LoadObjects(std::vector<structObject>& objects, const std::string& backgroundPath);	
protected:
	GameObjectArray mObjectsArray;
	cocos2d::CCLayer* mBackgroundLayer;
	virtual bool init(std::vector<structObject>& objects, const std::string& backgroundPath);  

public:    

	virtual ~GameScreen() = 0;
	
	GameObjectArray				GetObjectArrayByName(const std::string& name);
	GameObject*					GetObjectByName(const std::string& name);
	void						SetStrategyToGroup(GameObjectArray& group, ObjectStrategy* strategy);
	void						SetStrategyToGroup(const std::string& name, ObjectStrategy* strategy);
};

#endif