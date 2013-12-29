#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include "cocos2d.h"
class MBox : public cocos2d::CCLayer
{
	cocos2d::CCLabelTTF *label;	
protected:	
	void showText(const std::string &);
public: 
	void OKCallBack(CCObject* pSender);
	MBox(const std::string&); 		
	virtual ~MBox();
};

#endif