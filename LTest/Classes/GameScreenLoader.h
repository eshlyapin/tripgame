#ifndef GAMESCREENLOADER_H
#define GAMESCREENLOADER_H

#include <string>
#include "cocos2d.h"
#include <pugixml.hpp>
#include "structObject.h"

class GameScreenLoader
{
	std::vector<structObject> mObjects;

	pugi::xml_document& mDocument;

	std::string			ReadObjectState(pugi::xml_node& node);
	cocos2d::CCPoint&	ReadObjectPosition(pugi::xml_node& node);
	std::string			ReadObjectName(pugi::xml_node& node);	

public:
	GameScreenLoader(pugi::xml_document& doc);
	bool Load();

	std::vector<structObject> GetObjects();
	std::string GetBackgroundPath();
};
#endif