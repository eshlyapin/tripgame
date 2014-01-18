#ifndef HUD_H
#define HUD_H

#include "cocos2d.h"
#include <vector>

struct InventoryCell : public cocos2d::CCNode
{
	cocos2d::CCSprite* mCell;
	cocos2d::CCLabelTTF* mLabel;
	size_t mCountElements;

	InventoryCell();
	void update(float dt);

	bool init();

	CREATE_FUNC(InventoryCell);
};

class HUD : public cocos2d::CCLayer
{

	std::vector<InventoryCell*> mCells;
	void CreateInventory();
public:
	HUD();
	~HUD();

	bool init();
	void update(float delta);
	void BackCallBack(CCObject* pSender);

	CREATE_FUNC(HUD);
};

#endif