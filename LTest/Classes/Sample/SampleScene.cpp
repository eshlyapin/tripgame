#include "SampleScene.h"
using namespace cocos2d;
using namespace std;


bool SampleScene::init()
{
	if(!GameScreen::init("main"))
		return false;
	
	SetStrategyToGroup("smile",&mToggleStrategy);
	SetStrategyToGroup("coin",&mCollectStrategy);

	return true;
}