#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "GameObject.h"
#include "InputLayer.h"

#include "cocos2d.h"
#include <vector>

class GameScreen;
typedef std::vector<GameScreen*> ScreenArray;

class GameScreen : public cocos2d::CCScene
{
protected:
	cocos2d::CCLayer* mBackgroundLayer;
	ObjectLayer* mObjectLayer;

	GameScreen() {}
	cocos2d::CCLayer* LoadBackground(const std::string& file);
public:    

	virtual bool init();  
	~GameScreen();
	
	//I'm not sure that following functions are need
	//the CCScene is already has same methods
	//and probably we can use it to implement
	//our structure of game scenes (like a tree)
	
/*private:
	ScreenArray mChildList;
	GameScreen* mParentScreen;
public:
	void AddChild(GameScreen* child);
	void GetParent() const;*/

	CREATE_FUNC(GameScreen);
};

#endif