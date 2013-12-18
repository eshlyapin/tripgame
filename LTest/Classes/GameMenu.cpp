#include "GameMenu.h"
#include "GameScreen.h"
#include "Log.h"
using namespace cocos2d;
using namespace std;

GameMenu::~GameMenu()
{
}

bool GameMenu::init()
{
	CCMenuItem *buttonStart = CCMenuItemFont::create("Start", this, menu_selector(GameMenu::startGameCallBack));
	CCMenuItem *buttonClose = CCMenuItemFont::create("Close", this, menu_selector(GameMenu::endGameCallBack));
	
	//buttonStart->setPosition(200, 280);
	
	CCMenu *menu = CCMenu::create(buttonStart, buttonClose, NULL);
	
	menu->alignItemsVertically();
	addChild(menu, 1);
	return true;
}

void GameMenu::startGameCallBack(CCObject* pSender)
{
	CCScene *pScene = GameScreen::create(); 
	CCDirector::sharedDirector()->replaceScene(pScene);	
}
void GameMenu::endGameCallBack(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
	exit(0);
}