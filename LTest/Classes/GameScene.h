#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "cocos2d.h"
#include "pugixml.hpp"

class GameScene : public cocos2d::CCScene
{		
protected:
	GameScene(){}
	std::string GetBackgroundPath(const pugi::xml_document& doc);
	cocos2d::CCLayer* LoadBackground(const std::string& file);
public:    
	virtual ~GameScene(){}

	CREATE_FUNC(GameScene);
};

#endif