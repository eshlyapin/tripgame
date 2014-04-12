#include "GameMenu.h"
#include "Sample\SampleScene.h"
#include "Log.h"
#include "inventory.h"
#include "ScreenFactory.h"
#include "DataManager.h"

using namespace cocos2d;
using namespace std;

GameMenu::~GameMenu()
{
}

bool GameMenu::init()
{
	CCMenuItem *buttonStart = CCMenuItemFont::create("Start", this, menu_selector(GameMenu::StartGameCallBack));
	CCMenuItem *buttonClose = CCMenuItemFont::create("Close", this, menu_selector(GameMenu::EndGameCallBack));

	addChild(LoadBackground("HelloWorld.png"));
	CCMenu *menu;
	DataManager mng = DataManager::GetInstance();
	if(mng.isStoredGame())
	{
		CCMenuItem *buttonContinue = CCMenuItemFont::create("Continue", this, menu_selector(GameMenu::ContinueGameCallBack));
		menu = CCMenu::create(buttonContinue, buttonStart, buttonClose, NULL);
	}
	else
		menu = CCMenu::create(buttonStart, buttonClose, NULL);
	
	menu->alignItemsVertically();
	addChild(menu, 1);
	return true;
}

void GameMenu::StartGameCallBack(CCObject* pSender)
{
	//clear all stored values from Data Manager (and all stored .xml)
	SampleScene *newScene = ScreenFactory::Create<SampleScene>("main");
	if(newScene)
		CCDirector::sharedDirector()->replaceScene(newScene);
	else 
		Logger.log(Log::Prioritiy_ERROR, "Can't create main scene");
}
void GameMenu::EndGameCallBack(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
	exit(0);
}
void GameMenu::ContinueGameCallBack(CCObject* pSender)
{
	DataManager mng = DataManager::GetInstance();
	CCDirector::sharedDirector()->replaceScene(ScreenFactory::Create<SampleScene>(mng.getSavedGame()));
}