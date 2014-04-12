#include "SampleScene.h"
#include "ScreenFactory.h"
#include "DataManager.h"
using namespace cocos2d;
using namespace std;


bool SampleScene::init(const std::string& backgroundPath)
{
	if(!GameScreen::init(backgroundPath))
		return false;

	mClickableStrategy = new ClickableStrategy(this);

	DataManager::GetInstance().SetStrategyToGroup("smile",&mToggleStrategy);
	DataManager::GetInstance().SetStrategyToGroup("coin",&mCollectStrategy);
	DataManager::GetInstance().GetObjectByName("door")->SetStrategy(mClickableStrategy); //? check that GetObjectByName returns not 0	
	DataManager::GetInstance().GetObjectByName("key")->SetStrategy(&mCollectStrategy);
	scheduleUpdate();

	return true;
}

SampleScene::~SampleScene()
{
	delete mClickableStrategy;
}
void SampleScene::update(float delta)
{
	if(IsUpdate)
	{
		if(Inventory::GetInstance().GetItemCount("key") == 1)
		{
			DataManager::GetInstance().SetParameter("key", true);
		}
		if(Inventory::GetInstance().GetItemCount("coin") > 2)
		{
			if(DataManager::GetInstance().GetParameter("key").as_bool() == true)
			{
				DataManager::GetInstance().GetObjectByName("door")->SetStrategy(&mToggleStrategy);	//? check that GetObjectByName returns not 0
				DataManager::GetInstance().SetParameter("openDoor", true);
			}
		}
		if(DataManager::GetInstance().GetParameter("openDoor").as_bool() == true)
		{
			DataManager::GetInstance().SetStrategyToGroup("squash", &mCollectStrategy);
		}
	}
}