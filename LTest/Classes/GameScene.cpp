#include "GameScene.h"

using namespace cocos2d;

cocos2d::CCLayer* GameScene::LoadBackground(const std::string& file)
{
	CCLayer* background = CCLayer::create();
	CCSprite* image = CCSprite::create(file.c_str());
	background->addChild(image);

	
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	
    image->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	return background;
}

std::string GameScene::GetBackgroundPath(const pugi::xml_document& doc)
{
	return doc.child("background").child("name").text().as_string();
}