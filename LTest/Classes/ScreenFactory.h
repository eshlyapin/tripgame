#ifndef SCREENFACTORY_H
#define SCREENFACTORY_H

#include <string>
#include "GameScreenLoader.h"
#include "structObject.h"
#include "GameScreen.h"
#include "utils.h"
#include "Log.h"

class GameScreen;
template<class T>
class ScreenFactory
{
	static T* CreateScreen(std::vector<structObject>& objects, std::string backgroundPath)
	{
		T* screen = new T();
		if(screen->init(objects, backgroundPath))
		{
			screen->autorelease();
			return screen;
		}
		else
		{
			delete screen;
			return 0;
		}
	}
public:
	static T* Create(const std::string& name)		
	{
		std::string xmlPath = GetXmlPath(name);
		if(xmlPath == "")
			return 0;

		pugi::xml_document doc;
		CreateXmlDocument(xmlPath.c_str(), doc);

		GameScreenLoader loader(doc);
		if (!loader.Load())		
			Logger.log(Log::Prioritiy_ERROR, "Can't load object " + name);	

		vector<structObject> objects = loader.GetObjects();
		string mBackground = loader.GetBackgroundPath();
		return CreateScreen(objects, mBackground);		
	}
};

#endif