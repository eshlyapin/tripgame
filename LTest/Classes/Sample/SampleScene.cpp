#include "SampleScene.h"
#include "ScreenFactory.h"
using namespace cocos2d;
using namespace std;


bool SampleScene::init(std::vector<structObject>& objects, const std::string& backgroundPath)
{
	if(!GameScreen::init(objects, backgroundPath))
		return false;

	mClickableStrategy = new ClickableStrategy(this);

	SetStrategyToGroup("smile",&mToggleStrategy);
	SetStrategyToGroup("coin",&mCollectStrategy);
	GetObjectByName("door")->SetStrategy(mClickableStrategy); //? check that GetObjectByName returns not 0	

	scheduleUpdate();

	return true;
}

SampleScene::~SampleScene()
{
	delete mClickableStrategy;
}
void SampleScene::update(float delta)
{
	if(Inventory::GetInstance().GetItemCount("coin") == 2)
		GetObjectByName("door")->SetStrategy(&mToggleStrategy);	//? check that GetObjectByName returns not 0	
}