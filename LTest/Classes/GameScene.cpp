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

void GameScene::ShowTooltip(const std::string& message,const CCPoint &point)
{
	cocos2d::CCSprite *image = CCSprite::create("tooltip.png");	
	image->setPosition(point);		
	addChild(image);
	
	CCLabelTTF *label = CCLabelTTF::create("", "Arial", 16, CCSizeMake(image->getContentSize().width/1.2, image->getContentSize().height/1.8), kCCTextAlignmentCenter);
	label->setPosition(ccp((image->getContentSize().width - label->getContentSize().width)/2, (image->getContentSize().height - label->getContentSize().height)/2)); 
	label->setColor(ccc3(0,0,0));	
	label->setString(message.c_str());

	image->addChild(label);	

	int actualDuration = 4;

	CCFiniteTimeAction* actionMove = CCJumpTo::create((float)actualDuration, ccp(getJumpWidth(point.x), 0), getJumpHeight(point.y, image->getContentSize().height), 1);
	CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create(this, callfuncN_selector(GameScene::spriteMoveFinished));
	image->runAction(CCSequence::create(actionMove, actionMoveDone, NULL));
}
void GameScene::spriteMoveFinished(CCNode* sender)
{
  CCSprite *tooltip = (CCSprite *)sender;
  this->removeChild(tooltip, true);
}
int GameScene::getJumpHeight(int y, int imageHeight)
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	if(y < visibleSize.height - imageHeight)
		return 150;
	return imageHeight - 10;
}
int GameScene::getJumpWidth(int x)
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	if(x < visibleSize.width/2)
		return x + 200;
	return x - 200;
}