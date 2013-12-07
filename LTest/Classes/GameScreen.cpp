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
	xml_node state = doc.child("background");
	mBackgroundLayer = LoadBackground(state.child("name").text().as_string());
	addChild(mBackgroundLayer);

	for(xml_node state = doc.child("object"); state; state = state.next_sibling("object"))
	{
		string objectName = state.child("name").text().as_string();
		string objectState = state.child("state").text().as_string();
		int x = state.child("xpos").text().as_int();
		int y = state.child("ypos").text().as_int();
		
		if(objectName == "" || objectState == "" || x == 0 || y == 0)
		{
			//mSpriteMap.clear();
			return false;
		}
		GameObject *ob = new GameObject(objectName, objectState);
		addChild(ob);
		ob->setPosition(x, y);
		
	}
	return true;
}