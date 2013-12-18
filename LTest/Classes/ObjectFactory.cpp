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
	if(xmlPath == "")
		return 0;

	xml_document doc;
	CreateXmlDocument(xmlPath.c_str(), doc);

	GameObjectLoader loader(doc);
	if (!loader.Load())
		LOG_ERR("Can't load object " + name);
	

	vector<ObjectState> states = loader.GetObjectStates();

	GameObject* gameObject = new GameObject(name, states, curState);

	string behavior = loader.GetObjectBehavior();
	ObjectStrategy* strategy = 0;
	if(behavior == "toggle")
		strategy = new ToggleStrategy(gameObject);
	else if(behavior == "collect")
		strategy = new CollectStrategy(gameObject);

	gameObject->SetStrategy(strategy);

	return gameObject;	
}