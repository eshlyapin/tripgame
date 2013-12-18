#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "cocos2d.h"
//#include <CCMenuItem.h>

class GameMenu : public cocos2d::CCScene//, public cocos2d::CCStandardTouchDelegate
{
protected:
	GameMenu(){}
	void startGameCallBack(CCObject* pSender);
	void endGameCallBack(CCObject* pSender);
public:
	bool init();
	virtual ~GameMenu();


	CREATE_FUNC(GameMenu);
};
#endif
