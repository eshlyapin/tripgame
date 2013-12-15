#ifndef HUD_H
#define HUD_H

#include "cocos2d.h"
#include <vector>

struct InventoryCell : public cocos2d::CCNode
{
	cocos2d::CCSprite* mCell;
	cocos2d::CCLabelTTF* mLabel;
	size_t mCountElements;

	InventoryCell(cocos2d::CCSprite* sprite);
	void update(float dt);
};

class HUD : public cocos2d::CCLayer
{
	HUD();

	std::vector<InventoryCell*> mCells;
	void CreateInventory();
public:

	static HUD& GetInstance();

	void update(float delta);
	void BackCallBack(CCObject* pSender);
};

#endif