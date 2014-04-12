#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include "cocos2d.h"
#include "GameScene.h"
class MBox : public GameScene
{
	cocos2d::CCLabelTTF *label;	
	void showText(const std::string &);
	void OKCallBack(CCObject* pSender);
	bool initWithText(const std::string& str);
	MBox(){}
public:
	static MBox* createWithText(const std::string& str);
	virtual ~MBox();
};

#endif