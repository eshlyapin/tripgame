#include "ObjectState.h"

using namespace cocos2d;
using namespace std;

ObjectState::ObjectState(const string& name, cocos2d::CCSprite* sprite, const std::vector<cocos2d::CCRect>& bboxes)
	:mName(name),
	mSprite(sprite),
	mBoundingBoxList(bboxes)
{
}

void ObjectState::AddBox(cocos2d::CCRect rect)
{
	mBoundingBoxList.push_back(rect);
}