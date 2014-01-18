#include "HUD.h"
#include "inventory.h"
#include "CCScheduler.h"
#include <sstream>
#include <GameMenu.h>
#include <Log.h>
using namespace cocos2d;
using namespace std;


HUD::HUD()
{
}

bool HUD::init()
{
	CCMenuItemImage* backButton = CCMenuItemImage::create("HUD/BackButton.png","HUD/BackButton.png","HUD/BackButton.png", this, menu_selector(HUD::BackCallBack));

	CCMenu* menu = CCMenu::create(backButton, NULL);

	int menuX = backButton->getNormalImage()->getContentSize().width/2;
	int menuY = 50;
	menu->setPosition(menuX, menuY);	
	addChild(menu, 1);

	CreateInventory();
	scheduleUpdate();
	return true;
}

HUD::~HUD()
{
	removeAllChildrenWithCleanup(true);
}


void HUD::BackCallBack(CCObject* pSender)
{
	//change scene
	CCScene *mMenu = GameMenu::create();
	CCDirector::sharedDirector()->replaceScene(mMenu);
}


void HUD::CreateInventory()
{
	const int inventoryY = 50;
	const int cellSize = 45;
	const size_t CellCount = Inventory::GetInstance().GetSize();
	const int inventoryWidth = CellCount * cellSize;
	
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();	
	int center = visibleSize.width/2;
	int startX = center - (inventoryWidth/2) + (cellSize/2);

	for(size_t i = 0; i < CellCount; ++i)
	{
		float x = startX + cellSize * i;
		InventoryCell *cell = InventoryCell::create();
		cell->setPosition(ccp(x, inventoryY));
		
		mCells.push_back(cell);

		addChild(cell);
	}
	//scheduleUpdate();
}

void HUD::update(float delta)
{
	for(size_t i = 0; i < mCells.size(); ++i)
	{
		GameObject* object = Inventory::GetInstance().GetItem(i);
		mCells[i]->mCountElements = Inventory::GetInstance().GetItemCount(i);

		if(object != 0)
		{
			if(object->getParent() == 0)
			{
				addChild(object);
			}
			CCPoint pos = mCells[i]->getPosition();
			object->setPosition(pos);
		}
	}
}

InventoryCell::InventoryCell()
	:mCountElements(0)
{

}

bool InventoryCell::init()
{	
	const int LABEL_OFFSET = -30;
	
	mCell = CCSprite::create("HUD/invCell.png");
	addChild(mCell);

	mLabel = CCLabelTTF::create(".","Arial", 20.f);
	mLabel->setPositionY(LABEL_OFFSET);
	addChild(mLabel);

	scheduleUpdate();
	return true;
}

void InventoryCell::update(float dt)
{
	if(mCountElements > 0)
	{
		stringstream stream;
		stream << mCountElements;
		mLabel->setString(stream.str().c_str());
		mLabel->setVisible(true);
	}
	else
	{
		mLabel->setVisible(false);
	}
}