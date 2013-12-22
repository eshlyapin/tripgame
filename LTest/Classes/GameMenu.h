#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "GameScene.h"
#include "cocos2d.h"

class GameMenu : public GameScene
{
protected:
	GameMenu(){}
	void startGameCallBack(CCObject* pSender);
	void endGameCallBack(CCObject* pSender);
	void ContinueGameCallBack(CCObject* pSender);
public:
	bool init();
	virtual ~GameMenu();

	CREATE_FUNC(GameMenu);
};
#endif
