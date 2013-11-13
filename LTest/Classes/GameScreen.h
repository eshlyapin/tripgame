#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "GameObject.h"

#include "cocos2d.h"
#include <vector>

class GameScreen;
typedef std::vector<GameScreen*> ScreenArray;

class GameScreen : public cocos2d::CCScene
{
	GameObjectList mObjectList;
	GameScreen() {}
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