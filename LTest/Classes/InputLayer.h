#ifndef INPUT_LAYER_H
#define INPUT_LAYER_H

#include "cocos2d.h"
#include "GameObject.h"
#include <vector>

class ObjectLayer : public cocos2d::CCLayer
{
	std::vector<GameObject*> mObjects;
public:

	virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
	void addChild(GameObject* child);

	CREATE_FUNC(ObjectLayer);
};

#endif