#include "GameScreen.h"
#include <vector>
using namespace std;
using namespace cocos2d;

bool GameScreen::init()
{
	if( !CCScene::init() )
		return false;

	//it just for test!
	//not sure that the content should add here.

	//create object
	GameObject *ob = new GameObject("smile","state2");
	//add to scene
	addChild(ob);
	ob->setPosition(240, 160);
	//we can change state.
	ob->SetState("state1");
	return true;
}

GameScreen::~GameScreen()
{

}
