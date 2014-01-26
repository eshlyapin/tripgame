#ifndef _CLICKABLESTRATEGY_H
#define _CLICKABLESTRATEGY_H
#include "c:\cocos2d-x-2.2\projects\ltest\classes\objectstrategy.h" //0_o
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