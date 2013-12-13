#ifndef HUD_H
#define HUD_H

#include "cocos2d.h"
#include <vector>

class HUD : public cocos2d::CCLayer
{
	HUD();

	std::vector<cocos2d::CCSprite*> mCells;
	void CreateInventory();
public:

	static HUD& GetInstance();

	void update(float delta);
	void BackCallBack(CCObject* pSender);
};

#endif