#include "GameScreen.h"
#include <vector>
#include "utils.h"
#include "Log.h"

using namespace std;
using namespace cocos2d;
using namespace pugi;

bool GameScreen::init()
{
	if( !CCScene::init() )
		return false;
	

	//it just for test!
	//not sure that the content should add here.

	//create background
	/*mBackgroundLayer = LoadBackground("HelloWorld.png");
	mObjectLayer = ObjectLayer::create();
	mObjectLayer->setTouchEnabled(true);
	
	addChild(mObjectLayer);
	//addChild(mBackgroundLayer);

	//create object
	GameObject *ob = new GameObject("smile","state2");
	//add to scene
	mObjectLayer->addChild(ob);
	//addChild(ob);
	ob->setPosition(240, 160);
	//we can change state.
	//ob->SetState("state1");*/
	if(!LoadObjects("main"))
		LOG_ERR("Can't load game object!");
	return true;
}

GameScreen::~GameScreen()
{

}

cocos2d::CCLayer* GameScreen::LoadBackground(const std::string& file)
{
	CCLayer* background = CCLayer::create();
	CCSprite* image = CCSprite::create(file.c_str());
	background->addChild(image);

	
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	
    image->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	return background;
}

bool GameScreen::LoadObjects(const std::string& name)
{
	string xmlPath = GetXmlPath(name);
	if(xmlPath == "")
		return false;

	xml_document doc;
	CreateXmlDocument(xmlPath.c_str(), doc);

	string backgroundLayer = doc.child("background").child("name").text().as_string();

	if(backgroundLayer == "")
	{
		LOG_ERR("Can't load background!");
		return false;
	}
	else
	{
		mBackgroundLayer = LoadBackground(backgroundLayer);
		addChild(mBackgroundLayer);
	}

	for(xml_node object = doc.child("object"); object; object = object.next_sibling("object"))
	{
		string objectName = object.child("name").text().as_string();
		string objectState = object.child("state").text().as_string();
		
		xml_text x = object.child("xpos").text();//.as_string();
		xml_text y = object.child("ypos").text();//.as_string();
		
		if(objectName == "" || objectState == "" || x == NULL || y == NULL)
		{
			LOG_ERR("Can't load object " + objectName);
			//return false;
		}
		else
		{
			GameObject *ob = new GameObject(objectName, objectState);
			addChild(ob);
			ob->setPosition(x.as_int(), y.as_int());
		}
		
	}
	return true;
}