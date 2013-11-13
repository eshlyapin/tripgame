#include "GameObject.h"

using namespace cocos2d;

GameObject::GameObject()
{
	mSprite = CCSprite::create("SmileFace.png");

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	
    mSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
}

GameObject::~GameObject()
{
}

cocos2d::CCSprite* GameObject::GetSprite() const
{
	return mSprite;
}

