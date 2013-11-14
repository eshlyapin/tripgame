#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "cocos2d.h"
#include <list>
#include <map>
#include <string>

class GameObject : public cocos2d::CCNode
{
	std::map<std::string, cocos2d::CCSprite*> mSpriteMap;
	std::string mCurrentState;
	std::string mName;

	bool LoadSprites(const std::string& name);
	void HideAll();
	void ShowCurrent();
public:
	GameObject(const std::string& name, const std::string& currentState);
	~GameObject();

	bool SetState(const std::string& name);

	cocos2d::CCSprite* GetCurrentSprite() const;
	std::vector<cocos2d::CCSprite*> GetSprites() const;
};

typedef std::list<GameObject*> GameObjectList;

#endif