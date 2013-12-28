#ifndef _OBJECT_STRATEGY_H
#define _OBJECT_STRATEGY_H

#include "cocos2d.h"
class GameObject;

class ObjectStrategy
{
public:
	ObjectStrategy()
	{
	}

	virtual void OnClicked(GameObject* owner, const cocos2d::CCPoint& point) = 0;

	//The following methods are same...
	//virtual void OnMoved() = 0;
};

class ToggleStrategy : public ObjectStrategy
{
public:
	ToggleStrategy();
	void OnClicked(GameObject* owner, const cocos2d::CCPoint& point);
};

class CollectStrategy : public ObjectStrategy
{
public:
	CollectStrategy();
	void OnClicked(GameObject* owner, const cocos2d::CCPoint& point);
};

#endif