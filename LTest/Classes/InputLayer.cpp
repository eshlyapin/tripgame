#include "InputLayer.h"

using namespace cocos2d;

void ObjectLayer::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	CCTouch* touch = (CCTouch*)(touches->anyObject());
	CCPoint location = touch->getLocation();

	for(size_t i = 0; i < mObjects.size(); ++i)
		mObjects[i]->OnClicked(location);
}

void ObjectLayer::addChild(GameObject* child)
{
	CCLayer::addChild(child);
	mObjects.push_back(child);
}