#include "GameScreen.h"
#include <vector>
#include "ObjectFactory.h"
#include "inventory.h"
#include "utils.h"
#include "Log.h"
#include "HUD.h"

using namespace std;
using namespace cocos2d;
using namespace pugi;

bool GameScreen::init(vector<structObject>& objects, const string& backgroundPath)
{
	if( !CCScene::init() )
		return false;
	

	if(!LoadObjects(objects, backgroundPath))
		Logger.log(Log::Prioritiy_ERROR, "Can't load game object!");

	return true;
}

GameScreen::~GameScreen()
{
}

bool GameScreen::LoadObjects(vector<structObject>& objects, const string& backgroundPath)
{
	if(backgroundPath == "")
	{
		Logger.log(Log::Prioritiy_ERROR, "Can't load background");
		return false;
	}
	else
	{
		mBackgroundLayer = LoadBackground(backgroundPath);
		addChild(mBackgroundLayer);
	}
	
	addChild(HUD::create());

	for(size_t i = 0; i < objects.size(); ++i)
	{
		GameObject *ob = ObjectFactory::Create(objects[i].name, objects[i].state);
		addChild(ob);
		ob->setPosition(objects[i].point);
		mObjectsArray.push_back(ob);
	}
	return true;
}

std::vector<GameObject*> GameScreen::GetObjectArrayByName(const std::string& name)
{
	GameObjectArray retArray;
	for(size_t i = 0; i < mObjectsArray.size(); ++i)
	{
		if(mObjectsArray[i]->GetName() == name)
			retArray.push_back(mObjectsArray[i]);
	}
	return retArray;
}

GameObject* GameScreen::GetObjectByName(const std::string& name)
{
	for(size_t i = 0; i < mObjectsArray.size(); ++i)
	{
		if(mObjectsArray[i]->GetName() == name)
			return mObjectsArray[i];
	}
	return 0;
}

void GameScreen::SetStrategyToGroup(GameObjectArray& group, ObjectStrategy* strategy)
{
	for(size_t i = 0; i < group.size(); ++i)
	{
		group[i]->SetStrategy(strategy);
	}
}

void GameScreen::SetStrategyToGroup(const std::string& name, ObjectStrategy* strategy)
{
	GameObjectArray retArray = GetObjectArrayByName(name);
	if(!retArray.empty())
		SetStrategyToGroup(retArray, strategy);
	else
		Logger.log(Log::Prioritiy_ERROR, "Can't get array of objects");
}
