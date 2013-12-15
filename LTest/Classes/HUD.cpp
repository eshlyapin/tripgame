#include "HUD.h"
#include "inventory.h"
#include "CCScheduler.h"
#include <sstream>
using namespace cocos2d;
using namespace std;


HUD::HUD()
{
	CCMenuItemImage* backButton = CCMenuItemImage::create("HUD/BackButton.png","HUD/BackButton.png","HUD/BackButton.png", this, menu_selector(HUD::BackCallBack));

	CCMenu* menu = CCMenu::create(backButton, NULL);

	int menuX = backButton->getNormalImage()->getContentSize().width/2;
	int menuY = 50;

	menu->setPosition(menuX, menuY);

	addChild(menu);

	CreateInventory();
}

HUD::~HUD()
{
	removeAllChildrenWithCleanup(true);
	for(size_t i = 0; i < mCells.size(); ++i)
	{
		delete mCells[i];
		mCells[i] = 0;
	}
}

HUD& HUD::GetInstance()
{
	static HUD inst;
	return inst;
}

void HUD::BackCallBack(CCObject* pSender)
{
	//change scene
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
		CCSprite* cellSprt = CCSprite::create("HUD/invCell.png");

		float x = startX + cellSize * i;
		InventoryCell *cell = new InventoryCell(cellSprt);
		cell->setPosition(ccp(x, inventoryY));
		
		mCells.push_back(cell);

		addChild(cell);
	}
	scheduleUpdate();
}

void HUD::update(float delta)
{
	for(size_t i = 0; i < mCells.size(); ++i)
	{
		GameObjectList objs = Inventory::GetInstance().GetItem(i);
		mCells[i]->mCountElements = objs.size();

		if(objs.size() > 0)
		{			
			GameObjectList::iterator it = objs.begin();

			CCPoint pos = mCells[i]->getPosition();
			(*it)->setPosition(pos);
			it++;

			for(it; it != objs.end(); ++it)
				(*it)->setVisible(false);
		}
	}
}

InventoryCell::InventoryCell(CCSprite* sprite)
	:mCell(sprite),
	mCountElements(0)
{
	const int LABEL_OFFSET = -30;
	addChild(mCell);

	mLabel = CCLabelTTF::create(".","Arial", 20.f);
	mLabel->setPositionY(LABEL_OFFSET);
	addChild(mLabel);

	scheduleUpdate();
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