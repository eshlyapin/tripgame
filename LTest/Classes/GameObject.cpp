#include "GameObject.h"
#include "pugixml.hpp"
#include "Log.h"
#include "utils.h"
#include "inventory.h"

using namespace cocos2d;
using namespace std;
using namespace pugi;

GameObject::GameObject(const std::string& name,std::vector<ObjectState>& states, const std::string& currentState)
	:mName(name),
	mStateMap(states),
	mCurrentState(currentState),
	mStrategy(0)
{
	for(size_t i = 0; i < mStateMap.size(); ++i)
	{
		addChild(mStateMap[i].mSprite);
	}
	if(!SetState(currentState))
		Logger.log(Log::Prioritiy_INFO, "State is not found: " + currentState);
}


GameObject::~GameObject()
{
}

void GameObject::SetStrategy(ObjectStrategy* strategy)
{
	mStrategy = strategy;
}

cocos2d::CCSprite* GameObject::GetCurrentSprite()
{
	for(size_t i = 0; i < mStateMap.size(); ++i)
	{
		if(mStateMap[i].mName == mCurrentState)
			return mStateMap[i].mSprite;
	}
	return 0;
}


bool GameObject::SetState(const string& name)
{	
	for(size_t i = 0; i < mStateMap.size(); ++i)
	{
		//if state exist
		if(mStateMap[i].mName == name)
		{
			mCurrentState = name;
			HideAll();
			ShowCurrent();
			return true;
		}
	}
	return false;
}


void GameObject::HideAll()
{
	for(size_t i = 0; i < mStateMap.size(); ++i)
	{
		mStateMap[i].mSprite->setVisible(false);
	}
}

void GameObject::ShowCurrent()
{
	GetCurrentSprite()->setVisible(true);
}
	
void GameObject::SetNextState()
{
	for(size_t i = 0; i < mStateMap.size(); ++i)
	{
		if(mStateMap[i].mName == mCurrentState)
		{
			if (i == (mStateMap.size() - 1))
				SetState(mStateMap[0].mName);
			else
				SetState(mStateMap[i+1].mName);
			break;
		}
	}
}

vector<CCSprite*> GameObject::GetSprites() const
{
	vector<CCSprite*> sprites;

	for(size_t i = 0; i < mStateMap.size(); ++i)
		sprites.push_back(mStateMap[i].mSprite);

	return sprites;
}

//this function is awful
//I WANT NEED TO REFACTOR IT
void GameObject::OnClicked(const cocos2d::CCPoint& point)
{
	std::cout << "clicked: " << point.x << " " << point.y << std::endl;
	if(mStrategy != 0)
	{
		for(size_t i = 0; i < mStateMap.size(); ++i)
		{
			if(mStateMap[i].mName == mCurrentState)
			{

				if(mStateMap[i].mBoundingBoxList.size() == 0)
				{
					CCRect box = mStateMap[i].mSprite->boundingBox();
					CCPoint pos = getPosition();

					box.origin = box.origin + pos;

					if(box.containsPoint(point))
						mStrategy->OnClicked(point);
				}
				else
				{
					vector<CCRect> bboxs = mStateMap[i].mBoundingBoxList;
					for(size_t j = 0; j < bboxs.size(); ++j)
					{
						CCRect box = bboxs[j];
						CCSize size = mStateMap[i].mSprite->getContentSize();
						
						box.origin.x -= size.width/2;
						box.origin.y -= size.height/2;

						CCPoint pos = getPosition();
						box.origin = box.origin + pos;

						if(box.containsPoint(point))
						{
							mStrategy->OnClicked(point);
							break;
						}
					}
				}
				break;
			}
		}

	}
}

void GameObject::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	CCTouch* touch = (CCTouch*)(touches->anyObject());
	CCPoint location = touch->getLocation();

	OnClicked(location);
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

