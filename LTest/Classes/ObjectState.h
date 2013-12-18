#ifndef OBJECTSTATE_H
#define OBJECTSTATE_H

#include "cocos2d.h"
#include <string>

struct ObjectState
{
	std::string mName;
	cocos2d::CCSprite* mSprite;
	std::vector<cocos2d::CCRect> mBoundingBoxList;


	ObjectState(const std::string& name, cocos2d::CCSprite* sprite,  const std::vector<cocos2d::CCRect>& bboxes);
	void AddBox(cocos2d::CCRect rect);
};

#endif