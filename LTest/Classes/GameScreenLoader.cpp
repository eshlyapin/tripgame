#include "GameScreenLoader.h"
#include "ObjectFactory.h"

using namespace std;
using namespace pugi;
using namespace cocos2d;

GameScreenLoader::GameScreenLoader(pugi::xml_document& doc)
	:mDocument(doc)
{
}

bool GameScreenLoader::Load()
{
	for(xml_node xmlState = mDocument.child("object"); xmlState; xmlState = xmlState.next_sibling("object"))
	{		
		string name = ReadObjectName(xmlState);
		string state = ReadObjectState(xmlState);
		CCPoint point = ReadObjectPosition(xmlState);

		if ((state.empty()) || (name.empty()) || point.equals(CCPoint()))
			return false;

		structObject object;
		object.name = name;
		object.state = state;
		object.point = point;

		mObjects.push_back(object);
	}
	return true;
}

std::string	GameScreenLoader::ReadObjectState(pugi::xml_node& node)
{
	return  node.child("state").text().as_string();
}

cocos2d::CCPoint& GameScreenLoader::ReadObjectPosition(pugi::xml_node& node)
{
	xml_text x = node.child("xpos").text();
	xml_text y = node.child("ypos").text();
	if (x == NULL || y == NULL)
		return CCPoint();
	return CCPoint(x.as_int(), y.as_int());
}
std::string	GameScreenLoader::ReadObjectName(pugi::xml_node& node)
{
	 return node.child("name").text().as_string();
}
std::string GameScreenLoader::GetBackgroundPath()
{
	return mDocument.child("background").child("name").text().as_string();
}

std::vector<structObject> GameScreenLoader::GetObjects()
{
	return mObjects;
}