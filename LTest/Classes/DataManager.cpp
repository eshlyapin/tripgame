#include "DataManager.h"
#include <string>
#include "utils.h"
#include "ScreenFactory.h"
#include "ObjectFactory.h"
#include "inventory.h"

using namespace std;
using namespace pugi;

DataManager::DataManager()
{
}

DataManager::~DataManager()
{	
}

DataManager& DataManager::GetInstance()
{
	static DataManager mgr;
	return mgr;
}

bool DataManager::isStoredGame()
{
	string xmlPath = GetXmlPath("SavedGames/sGame");//sGame contains configs and last saved screen	
	if(!IsFileAvailable(xmlPath))
		return false;	
	xml_document savedGame;
	CreateXmlDocument(xmlPath.c_str(), savedGame);
	if(!savedGame.child("game") || !savedGame.child("game").value())
		return false;
	return true;
}

void DataManager::SaveGame()
{
	xml_document savedGame;
	string xmlPath = GetXmlPath("SavedGames/" + mSceneName);	
	if(!IsFileAvailable(xmlPath))//need to create new file for this screen
		savedGame.save_file(xmlPath.c_str());

	CreateXmlDocument(xmlPath.c_str(), savedGame);
	savedGame.reset();	
	savedGame.save_file(xmlPath.c_str());
	
	SaveScreen(xmlPath);	
	SetSaveGame();
	SaveParameters(xmlPath);
	SaveInventory();
}

std::vector<GameObject*> DataManager::GetObjectArrayByName(const std::string& name)
{
	GameObjectArray retArray;
	for(size_t i = 0; i < mObjectsArray.size(); ++i)
	{
		if(mObjectsArray[i]->GetName() == name)
			retArray.push_back(mObjectsArray[i]);
	}
	return retArray;
}

GameObject* DataManager::GetObjectByName(const std::string& name)
{
	for(size_t i = 0; i < mObjectsArray.size(); ++i)
	{
		if(mObjectsArray[i]->GetName() == name)
			return mObjectsArray[i];
	}
	return 0;
}

void DataManager::SetStrategyToGroup(GameObjectArray& group, ObjectStrategy* strategy)
{
	if(!group.empty())
	{
		for(size_t i = 0; i < group.size(); ++i)
		{
			group[i]->SetStrategy(strategy);
		}
	}
	else
		Logger.log(Log::Prioritiy_ERROR, "Can't get array of objects");
}

void DataManager::SetStrategyToGroup(const std::string& name, ObjectStrategy* strategy)
{
	SetStrategyToGroup(GetObjectArrayByName(name), strategy);	
}

void DataManager::setValues(ListOfObjects objects, const std::string& backgroundPath, ListOfParameters parameters/*, string& SceneName*/)
{
	if(backgroundPath == "")
	{
		Logger.log(Log::Prioritiy_ERROR, "Can't load background");
		return;
	}

	mSceneName = "SampleScene";//SceneName; !!!
	mBackground = backgroundPath;
	
	SetObjects(objects);
	SetParameters(parameters);
}

void DataManager::SetObjects(ListOfObjects objects)
{
	for(size_t i = 0; i < objects.size(); ++i)
	{
		GameObject *ob = ObjectFactory::Create(objects[i].name, objects[i].state);
		ob->setPosition(objects[i].point);
		mObjectsArray.push_back(ob);
	}
}

void DataManager::SetParameters(ListOfParameters parameters)
{
	for(size_t i = 0; i < parameters.size(); i++)
	{
		mParameters[parameters[i].first] = parameters[i].second;
	}
}

GameObjectArray DataManager::GetObjects()
{
	return mObjectsArray;
}

void DataManager::clearValues()
{
	mBackground = "";
	mSceneName = "";
	mObjectsArray.clear();
	mParameters.clear();
}

void DataManager::SaveScreen(const string& xmlPath)
{
	SaveBackground(xmlPath);
	SaveObjects(xmlPath);
}

void DataManager::SetSaveGame()
{
	xml_document savedGame;
	string xmlPath = GetXmlPath("SavedGames/sGame");	
	if(!IsFileAvailable(xmlPath))
		savedGame.save_file(xmlPath.c_str());
	CreateXmlDocument(xmlPath.c_str(), savedGame);
	xml_node game = savedGame.child("game");
	if(game)
		savedGame.remove_child("game");
	savedGame.append_child("game").append_child(node_pcdata).set_value(mSceneName.c_str());
	savedGame.save_file(xmlPath.c_str());
}

const string DataManager::getSavedGame()
{
	string xmlPath = GetXmlPath("SavedGames/sGame");
	xml_document savedGame;
	CreateXmlDocument(xmlPath.c_str(), savedGame);
	string path = savedGame.child("game").text().as_string();
	return "SavedGames/" + path;// :(
}

void DataManager::SaveParameters(const string& xmlPath)
{
	xml_document savedScreen;
	CreateXmlDocument(xmlPath.c_str(), savedScreen);	
	xml_node parameters = savedScreen.append_child("parameters");
	
	for(std::map<string, xml_text>::iterator i = mParameters.begin(); i != mParameters.end(); i++)
	{	
		xml_node parameter = parameters.append_child("parameter");
		xml_attribute name = parameter.append_attribute("name");
		name.set_value((*i).first.c_str());
		parameter.append_child(node_pcdata).set_value((*i).second.as_string());		
	}

	savedScreen.save_file(xmlPath.c_str());
}
void DataManager::SetParameter(const string& name, const string& val)
{
	mParameters.find(name)->second = val.c_str();
}

void DataManager::SetParameter(const string& name, int val)
{
	mParameters.find(name)->second = val;
}

void DataManager::SetParameter(const string& name, double val)
{
	mParameters.find(name)->second = val;
}

void DataManager::SetParameter(const string& name, bool val)
{
	mParameters.find(name)->second = val;
}

xml_text DataManager::GetParameter(const std::string& name)
{	
	return mParameters[name];
}

void DataManager::SaveInventory()
{
	xml_document savedInventory;
	string xmlPath = GetXmlPath("SavedGames/inventory");
	if(!IsFileAvailable(xmlPath))
		savedInventory.save_file(xmlPath.c_str());
	CreateXmlDocument(xmlPath.c_str(), savedInventory);	
	savedInventory.reset();	
	vector<Inventory::InventoryItem> items = Inventory::GetInstance().GetInvenotryItems();
	for(size_t i = 0; i < items.size(); i++)
	{		
		xml_node cell = savedInventory.append_child("cell");
		cell.append_child("name").append_child(node_pcdata).set_value(items[i].GetName().c_str());
		string val;
		MakeString(val, items[i].GetObjectsCount());
		cell.append_child("count").append_child(node_pcdata).set_value(val.c_str());
	}
	savedInventory.save_file(xmlPath.c_str());
}

void DataManager::SaveObjects(const string& xmlPath)
{
	xml_document savedScreen;
	CreateXmlDocument(xmlPath.c_str(), savedScreen);
	for(size_t i = 0; i < mObjectsArray.size(); i++)
	{		
		xml_node object = savedScreen.append_child("object");
		xml_node obName = object.append_child("name");
		xml_node obState = object.append_child("state");
		xml_node obXPos = object.append_child("xpos");
		xml_node obYPos = object.append_child("ypos");

		obName.append_child(pugi::node_pcdata).set_value(mObjectsArray[i]->GetName().c_str());
		obState.append_child(pugi::node_pcdata).set_value(mObjectsArray[i]->GetCurrentState().c_str());
		string XPos, YPos;
		MakeString(XPos, mObjectsArray[i]->getPositionX());
		MakeString(YPos, mObjectsArray[i]->getPositionY());
		obXPos.append_child(pugi::node_pcdata).set_value(XPos.c_str());
		obYPos.append_child(pugi::node_pcdata).set_value(YPos.c_str());
	}
	savedScreen.save_file(xmlPath.c_str());
}

void DataManager::SaveBackground(const string& xmlPath)
{
	xml_document savedScreen;
	CreateXmlDocument(xmlPath.c_str(), savedScreen);

	xml_node bgName = savedScreen.append_child("background").append_child("name");
	bgName.append_child(pugi::node_pcdata).set_value(mBackground.c_str());
	savedScreen.save_file(xmlPath.c_str());
}

void DataManager::PrintParameters()
{
	std::map<std::string, pugi::xml_text>::iterator it = mParameters.begin();
	for(it; it != mParameters.end(); ++it)
	{
		std::cout << it->first << "\t" << it->second.as_bool() << std::endl;
	}	
}