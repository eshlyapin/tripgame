#include "GameScreen.h"
#include <vector>
#include "ObjectFactory.h"
#include "utils.h"
#include "Log.h"
#include "HUD.h"

using namespace std;
using namespace cocos2d;
using namespace pugi;

bool GameScreen::init(const string& scenename)
{
	if( !CCScene::init() )
		return false;
	

	if(!LoadObjects(scenename))
		Logger.log(Log::Prioritiy_ERROR, "Can't load game object!");

	return true;
}

GameScreen::~GameScreen()
{

}

bool GameScreen::LoadObjects(const std::string& name)
{
	string xmlPath = GetXmlPath(name);
	if(xmlPath == "")
		return false;

	xml_document doc;
	CreateXmlDocument(xmlPath.c_str(), doc);

	string backgroundPath = GetBackgroundPath(doc);

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
	
	//FFFUUUUuu~
	addChild(&HUD::GetInstance());

	for(xml_node object = doc.child("object"); object; object = object.next_sibling("object"))
	{
		string objectName = object.child("name").text().as_string();
		string objectState = object.child("state").text().as_string();
		
		xml_text x = object.child("xpos").text();
		xml_text y = object.child("ypos").text();
		
		if(objectName == "" || objectState == "" || x == NULL || y == NULL)
		{
			Logger.log(Log::Prioritiy_ERROR, "Can't load object " + objectName);
			mObjectsArray.clear();
			removeAllChildrenWithCleanup(true);
			return false;
		}
		else
		{
			GameObject *ob = ObjectFactory::Create(objectName, objectState);
			addChild(ob);
			ob->setPosition(x.as_int(), y.as_int());
			mObjectsArray.push_back(ob);
		}
		
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
	SetStrategyToGroup(GetObjectArrayByName(name), strategy);
}