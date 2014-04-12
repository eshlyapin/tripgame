#include "ObjectFactory.h"
#include "GameObjectLoader.h"
#include "Log.h"
#include "utils.h"

using namespace cocos2d;
using namespace std;
using namespace pugi;

GameObject* ObjectFactory::Create(const string& name, const string& curState)
{
	string xmlPath = GetXmlPath(name);
	if(!IsFileAvailable(xmlPath))
		return 0;

	xml_document doc;
	CreateXmlDocument(xmlPath.c_str(), doc);

	GameObjectLoader loader(doc);
	if (!loader.Load())
		Logger.log(Log::Prioritiy_ERROR, "Can't load object " + name);
	

	vector<ObjectState> states = loader.GetObjectStates();
	return GameObject::create(name, states, curState);
}