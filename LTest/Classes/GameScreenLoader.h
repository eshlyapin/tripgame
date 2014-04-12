#ifndef GAMESCREENLOADER_H
#define GAMESCREENLOADER_H

#include <string>
#include "cocos2d.h"
#include <pugixml.hpp>
#include "structObject.h"

class GameScreenLoader
{
	std::vector<structObject> mObjects;
	std::vector<std::pair<std::string, pugi::xml_text>> mParameters;
	pugi::xml_document& mDocument;

	std::string			ReadObjectState(pugi::xml_node& node);
	cocos2d::CCPoint	ReadObjectPosition(pugi::xml_node& node);
	std::string			ReadObjectName(pugi::xml_node& node);	
	std::pair<std::string, pugi::xml_text> ReadParameter(pugi::xml_node & node);
public:
	GameScreenLoader(pugi::xml_document& doc);
	bool Load();

	std::vector<structObject> GetObjects() const;
	std::string	GetBackgroundPath() const;
	std::vector<std::pair<std::string, pugi::xml_text>> GetParameters() const;
};
#endif
