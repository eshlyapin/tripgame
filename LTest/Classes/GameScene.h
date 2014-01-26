#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "cocos2d.h"
#include "pugixml.hpp"

class GameScene : public cocos2d::CCScene
{		
	void spriteMoveFinished(CCNode* sender);
	int getJumpHeight(int y, int imageHeight);
	int getJumpWidth(int x);
protected:
	GameScene(){}
	std::string GetBackgroundPath(const pugi::xml_document& doc);
	cocos2d::CCLayer* LoadBackground(const std::string& file);
public:    
	virtual ~GameScene(){}
	void ShowTooltip(const std::string& message, const cocos2d::CCPoint &point);
	CREATE_FUNC(GameScene);
};

#endif