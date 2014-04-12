#include "GameScreen.h"
#include <vector>
#include "ObjectFactory.h"
#include "inventory.h"
#include "Log.h"
#include "HUD.h"

using namespace std;
using namespace cocos2d;
using namespace pugi;

bool GameScreen::init(const string& backgroundPath)
{
	if( !CCScene::init() )
		return false;
	

	if(!LoadObjects(backgroundPath))
		Logger.log(Log::Prioritiy_ERROR, "Can't load game object!");
	IsUpdate = true;
	return true;
}

GameScreen::~GameScreen()
{
	DataManager::GetInstance().clearValues();
}

bool GameScreen::LoadObjects(const string& backgroundPath)
{
	if(backgroundPath == "")
	{
		Logger.log(Log::Prioritiy_ERROR, "Can't load background");
		return false;
	}
	else
	{
		addChild(LoadBackground(backgroundPath));
	}
	
	addChild(HUD::create());

	GameObjectArray ObjectsArray = DataManager::GetInstance().GetObjects();
	for(size_t i = 0; i < ObjectsArray.size(); ++i)
	{
		addChild(ObjectsArray[i]);		
	}
	return true;
}