#ifndef _CLICKABLESTRATEGY_H
#define _CLICKABLESTRATEGY_H
#include "objectstrategy.h"
#include "inventory.h"
#include "Sample\SampleScene.h"


class ClickableStrategy : public ObjectStrategy
{
	GameScene *ownerScene;
public:
	ClickableStrategy(GameScene *screen);
	void OnClicked(GameObject* owner, const cocos2d::CCPoint& point);
	virtual ~ClickableStrategy(){}
};
#endif