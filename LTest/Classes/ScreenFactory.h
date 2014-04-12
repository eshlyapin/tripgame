#ifndef SCREENFACTORY_H
#define SCREENFACTORY_H

#include <string>
#include "GameScreenLoader.h"
#include "structObject.h"
#include "GameScreen.h"
#include "utils.h"
#include "Log.h"
#include "DataManager.h"

class GameScreen;

class ScreenFactory
{
	
	template<class T>
	static T* CreateScreen(std::string backgroundPath)
	{
		T* screen = new T();
		if(screen->init(backgroundPath))
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
	static pugi::xml_document doc;
public:
	template<class T>
	static T* Create(const std::string& name)		
	{
		std::string xmlPath = GetXmlPath(name);
		if(!IsFileAvailable(xmlPath))
			return 0;

		CreateXmlDocument(xmlPath.c_str(), doc);

		GameScreenLoader loader(doc);
		if (!loader.Load())		
			Logger.log(Log::Prioritiy_ERROR, "Can't load object " + name);	

		string mBackground = loader.GetBackgroundPath();
		DataManager::GetInstance().setValues(loader.GetObjects(), mBackground, loader.GetParameters());

		return CreateScreen<T>(mBackground);		
	}
};
#endif