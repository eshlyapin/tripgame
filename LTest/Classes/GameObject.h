#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "cocos2d.h"
#include <list>


class GameObject
{
	cocos2d::CCSprite* mSprite;
public:
	GameObject();
	~GameObject();

	cocos2d::CCSprite* GetSprite() const;
};

typedef std::list<GameObject*> GameObjectList;

#endif