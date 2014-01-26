#include "SampleScene.h"
using namespace cocos2d;
using namespace std;


bool SampleScene::init()
{
	if(!GameScreen::init("main"))
		return false;

	mClickableStrategy = new ClickableStrategy(this);

	SetStrategyToGroup("smile",&mToggleStrategy);
	SetStrategyToGroup("coin",&mCollectStrategy);
	GetObjectByName("door")->SetStrategy(mClickableStrategy);

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
		GetObjectByName("door")->SetStrategy(&mToggleStrategy);		
}