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
	for(xml_node xmlObject = mDocument.child("object"); xmlObject; xmlObject = xmlObject.next_sibling("object"))
	{		
		string name = ReadObjectName(xmlObject);
		string state = ReadObjectState(xmlObject);
		CCPoint point = ReadObjectPosition(xmlObject);

		if ((state.empty()) || (name.empty()) || point.equals(CCPoint()))
			return false;

		structObject object (name, state, point);
		mObjects.push_back(object);
	}
	for(xml_node xmlParameter = mDocument.child("parameters").child("parameter"); xmlParameter; xmlParameter = xmlParameter.next_sibling("parameter"))
	{
		pair<string, pugi::xml_text> parameter = ReadParameter(xmlParameter);
		if(parameter.first.empty() || parameter.second.empty())
			return false;
		mParameters.push_back(parameter);
	}

	return true;
}

std::string	GameScreenLoader::ReadObjectState(pugi::xml_node& node)
{
	return  node.child("state").text().as_string();
}

cocos2d::CCPoint GameScreenLoader::ReadObjectPosition(pugi::xml_node& node)
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
std::string GameScreenLoader::GetBackgroundPath() const
{
	return mDocument.child("background").child("name").text().as_string();
}

std::vector<structObject> GameScreenLoader::GetObjects() const
{
	return mObjects;
}

std::vector<std::pair<std::string, pugi::xml_text>> GameScreenLoader::GetParameters() const
{
	return mParameters;
}
pair<string, xml_text> GameScreenLoader::ReadParameter(xml_node &node)
{
	string name = node.attribute("name").as_string();
	xml_text val = node.text();
	
	if(name.empty() || val.empty())
		return pair<string, xml_text>("", xml_text());
	return pair<string, xml_text>(name, val);
}