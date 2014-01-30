#include "GameObjectLoader.h"

using namespace std;
using namespace pugi;
using namespace cocos2d;

GameObjectLoader::GameObjectLoader(xml_document& doc)
	:mDocument(doc)
{		

}

bool GameObjectLoader::Load()
{	
	for(xml_node xmlState = mDocument.child("state"); xmlState; xmlState = xmlState.next_sibling("state"))
	{
		CCSprite* sprite = ReadStateSprite(xmlState);
		string name = ReadStateName(xmlState);
		vector<CCRect> bboxs = ReadStateBBoxes(xmlState);

		if ((sprite == 0) || (name.empty()))
			return false;

		ObjectState state(name, sprite, bboxs);
		mObjectStates.push_back(state);
	}
	return true;
}

CCSprite* GameObjectLoader::ReadStateSprite(xml_node& node)
{
	string imagePath = node.child("image").text().as_string();
	if (imagePath.empty())
		return 0;
	
	return CCSprite::create(imagePath.c_str());
}

string GameObjectLoader::ReadStateName(xml_node& node)
{
	return node.child("name").text().as_string();
}

vector<CCRect> GameObjectLoader::ReadStateBBoxes(xml_node& node)
{
	vector<CCRect> bboxes;
	
	for(xml_node xmlBox = node.child("bbox"); xmlBox; xmlBox = xmlBox.next_sibling("bbox"))
	{
		float x = xmlBox.attribute("x").as_float();
		float y = xmlBox.attribute("y").as_float();
		float width = xmlBox.attribute("w").as_float();
		float height = xmlBox.attribute("h").as_float();
		bboxes.push_back(CCRect(x, y, width, height));
	}
	return bboxes;
}


vector<ObjectState> GameObjectLoader::GetObjectStates()
{
	return mObjectStates;
}


