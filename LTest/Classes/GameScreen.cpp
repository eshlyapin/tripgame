#include "GameScreen.h"
#include <vector>
using namespace std;
using namespace cocos2d;

bool GameScreen::init()
{
	if( !CCScene::init() )
		return false;
	

	//it just for test!
	//not sure that the content should add here.

	//create background
	mBackgroundLayer = LoadBackground("HelloWorld.png");
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
	//ob->SetState("state1");
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