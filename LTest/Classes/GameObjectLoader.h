#ifndef GAMEOBJECTLOADER_H
#define GAMEOBJECTLOADER_H

#include <string>
#include "cocos2d.h"
#include <pugixml.hpp>
#include "ObjectState.h"

class GameObjectLoader
{
	std::string mBehavior;
	std::vector<ObjectState> mObjectStates;

	pugi::xml_document& mDocument;

	std::string			ReadObjectBehavior();
	cocos2d::CCSprite*	ReadStateSprite(pugi::xml_node& node);
	std::string			ReadStateName(pugi::xml_node& node);
	std::vector<cocos2d::CCRect> ReadStateBBoxes(pugi::xml_node& node);

public:
	GameObjectLoader(pugi::xml_document& doc);
	bool Load();

	std::vector<ObjectState> GetObjectStates();
	std::string GetObjectBehavior();
};

#endif