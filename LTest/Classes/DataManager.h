#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include "GameScreen.h"
#include "cocos2d.h"
#include "structObject.h"

typedef std::vector<std::pair<std::string, pugi::xml_text>>& ListOfParameters;
typedef std::vector<structObject>& ListOfObjects;
class DataManager
{
private:
	DataManager();
	GameObjectArray mObjectsArray;
	std::string	mBackground;
	std::string	mSceneName;
	std::map<std::string, pugi::xml_text> mParameters;
	void SaveScreen(const std::string&);
	void SetSaveGame();	
	void SaveParameters(const std::string&);
	void SaveInventory();
	void SaveObjects(const std::string& xmlPath);
	void SaveBackground(const std::string& xmlPath);
	void SetObjects(ListOfObjects objects);
	void SetParameters(ListOfParameters parameters);

public:
	
	static DataManager& GetInstance();

	bool isStoredGame();

	void SaveGame();
	void clearValues();//may be this method should be private...
	const std::string getSavedGame();
	
	GameObjectArray GetObjectArrayByName(const std::string& name);
	GameObject*	GetObjectByName(const std::string& name);
	GameObjectArray GetObjects();

	void SetStrategyToGroup(GameObjectArray& group, ObjectStrategy* strategy);
	void SetStrategyToGroup(const std::string& name, ObjectStrategy* strategy);

	void setValues(ListOfObjects objects, const std::string& backgroundPath, ListOfParameters parameters/*, std::string& SceneName*/);

	void SetParameter(const std::string&, const std::string&);
	void SetParameter(const std::string&, int);
	void SetParameter(const std::string&, double);
	void SetParameter(const std::string&, bool);

	pugi::xml_text GetParameter(const std::string&);
	void PrintParameters();//for debug only
	~DataManager();
};

#endif