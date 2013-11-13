#include "GameScreen.h"

bool GameScreen::init()
{
	if( !CCScene::init() )
		return false;

	//it just for test!
	//not sure that the content should add here.
	GameObject *gobject = new GameObject();	
	addChild(gobject->GetSprite());
	mObjectList.push_back(gobject);
	return true;
}

GameScreen::~GameScreen()
{
	for(GameObjectList::iterator object = mObjectList.begin(); object != mObjectList.end(); object++)
	{
		delete *object;
	}
}