#include "GameObject.h"
#include "pugixml.hpp"
#include "Log.h"
#include "utils.h"
#include "inventory.h"

using namespace cocos2d;
using namespace std;
using namespace pugi;

GameObject::GameObject(const string& name, const string& curState)
	:mName(name)
{
	if(!LoadSprites(name))
		LOG_ERR("Can't load game object: " + name);

	if(!SetState(curState))
		LOG_ERR("State is not found: " + curState);
}

std::string GameObject::ReadObjectName(pugi::xml_document& doc)
{
	return doc.next_sibling("name").text().as_string();
}

bool GameObject::LoadSprites(const std::string& name)
{
	//get files to load

	string xmlPath = GetXmlPath(name);
	if(xmlPath == "")
		return false;

	xml_document doc;
	CreateXmlDocument(xmlPath.c_str(), doc);

	mName = ReadObjectName(doc);

	for(xml_node state = doc.child("state"); state; state = state.next_sibling("state"))
	{
		string stateName = state.child("name").text().as_string();
		string imagePath = state.child("image").text().as_string();
		
		if(stateName == "" || imagePath == "")
		{
			mSpriteMap.clear();
			return false;
		}

		CCSprite* sprite = CCSprite::create(imagePath.c_str());

		mSpriteMap[stateName] = sprite;
		addChild(sprite);
	}
	return true;
}

GameObject::~GameObject()
{
}

cocos2d::CCSprite* GameObject::GetCurrentSprite() const
{
	return 0;
}

bool GameObject::SetState(const string& name)
{
	map<string, CCSprite*>::iterator iter = mSpriteMap.find(name);
	if(iter == mSpriteMap.end())
		return false;

	mCurrentState = name;
	HideAll();
	ShowCurrent();
	return true;
}


void GameObject::HideAll()
{
	map<string, CCSprite*>::iterator iter;
	for(iter = mSpriteMap.begin(); iter != mSpriteMap.end(); iter++)
	{
		CCSprite *sprite = iter->second;
		sprite->setVisible(false);
	}
}

void GameObject::ShowCurrent()
{
	mSpriteMap[mCurrentState]->setVisible(true);
}
	
vector<CCSprite*> GameObject::GetSprites() const
{
	vector<CCSprite*> sprites;

	map<string, CCSprite*>::const_iterator iter;
	for(iter = mSpriteMap.begin(); iter != mSpriteMap.end(); iter++)
	{
		sprites.push_back(iter->second);
	}
	return sprites;
}

void GameObject::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
CCTouch* touch = (CCTouch*)(touches->anyObject());
CCPoint location = touch->getLocation();

OnClicked(location);
}

void GameObject::OnClicked(const cocos2d::CCPoint& point)
{
	std::cout << "clicked: " << point.x << " " << point.y << std::endl;
	Inventory::GetInstance().AddItems(this);
}

void GameObject::touchDelegateRelease()
{
this->release();
}
void GameObject::touchDelegateRetain()
{
this->retain();
}

void GameObject::onEnter()
{
   CCDirector* pDirector = CCDirector::sharedDirector();
pDirector->getTouchDispatcher()->addStandardDelegate(this, 0);
   CCNode::onEnter();
}

void GameObject::onExit()
{
   CCDirector* pDirector = CCDirector::sharedDirector();
   pDirector->getTouchDispatcher()->removeDelegate(this);
   CCNode::onExit();
}    