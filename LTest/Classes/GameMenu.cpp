#include "GameMenu.h"
#include "Sample\SampleScene.h"
#include "Log.h"
#include "inventory.h"
using namespace cocos2d;
using namespace std;

GameMenu::~GameMenu()
{
}

bool GameMenu::init()
{
	CCMenuItem *buttonStart = CCMenuItemFont::create("Start", this, menu_selector(GameMenu::startGameCallBack));
	CCMenuItem *buttonClose = CCMenuItemFont::create("Close", this, menu_selector(GameMenu::endGameCallBack));

	addChild(LoadBackground("HelloWorld.png"));

	//add check, that scene manager has saved game
	
	CCMenuItem *buttonContinue = CCMenuItemFont::create("Continue", this, menu_selector(GameMenu::ContinueGameCallBack));
	CCMenu *menu = CCMenu::create(buttonContinue, buttonStart, buttonClose, NULL);
	
	menu->alignItemsVertically();
	addChild(menu, 1);
	return true;
}

void GameMenu::startGameCallBack(CCObject* pSender)
{
	CCScene *pScene = SampleScene::create();
	Inventory::GetInstance().Clear();
	CCDirector::sharedDirector()->replaceScene(pScene);	
}
void GameMenu::endGameCallBack(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
	exit(0);
}
void GameMenu::ContinueGameCallBack(CCObject* pSender)
{
	//load saved game
}