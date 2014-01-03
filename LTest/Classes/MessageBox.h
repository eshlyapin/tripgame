#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include "cocos2d.h"
#include "GameScene.h"
class MBox : public GameScene
{
	cocos2d::CCLabelTTF *label;	
protected:	
	void showText(const std::string &);
public: 
	void OKCallBack(CCObject* pSender);
	MBox(){}
	bool initWithText(const std::string& str);
	static MBox* createWithText(const std::string& str);
	virtual ~MBox();
};

#endif