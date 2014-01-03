#include "MessageBox.h"

using namespace cocos2d;

bool MBox::initWithText(const std::string& str)
{	
	if(!MBox::init())
		return false;

	addChild(LoadBackground("MBox/bg.png"));

	//set font and size
	cocos2d::CCSprite *image = CCSprite::create("MBox/book-cover-textures.png");	
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();	
    image->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));		
	addChild(image);
	
	//set button
	cocos2d::CCMenuItemImage* okButton = CCMenuItemImage::create("MBox/button_ok.png", "MBox/button_ok.png", this, menu_selector(MBox::OKCallBack));
	cocos2d::CCMenu* menu = CCMenu::create(okButton, NULL);	
	menu->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height - image->getContentSize().height + origin.y));		
	addChild(menu, 1);

	//set Label
	label = CCLabelTTF::create("", "Arial", 25, CCSizeMake(image->getContentSize().width - 30, image->getContentSize().height - 50), kCCTextAlignmentLeft);
	label->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y)); 
	label->setColor(ccc3(0,0,0));
	addChild(label);

	//add on stack
	cocos2d::CCDirector::sharedDirector()->pushScene(this);
	showText(str);
	return true;
}
MBox::~MBox()
{
}
void MBox::OKCallBack(CCObject* pSender)
{
	label->setString("");	
	cocos2d::CCDirector::sharedDirector()->popScene();
}

void MBox::showText(const std::string& str)
{
	label->setString(str.c_str());		
}

MBox* MBox::createWithText(const std::string& str)
{
	MBox* pRet = new MBox();
    
	if( pRet && pRet->initWithText(str) )
    {
        pRet->autorelease();
        return pRet;
    }

    CC_SAFE_DELETE( pRet );
    return NULL;
}