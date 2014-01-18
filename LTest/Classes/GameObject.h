#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "cocos2d.h"
#include "pugixml.hpp"
#include "ObjectStrategy.h"
#include "ObjectState.h"
#include <list>
#include <map>
#include <string>


class GameObject : public cocos2d::CCNode, public cocos2d::CCStandardTouchDelegate//cocos2d::CCTargetedTouchDelegate
{

	std::vector<ObjectState> mStateMap;
	std::string mCurrentState;
	std::string mName;
	ObjectStrategy* mStrategy;

	
	ObjectStrategy* LoadStrategy(pugi::xml_document& doc);
	bool LoadSprites(const std::string& name);
	void HideAll();
	void ShowCurrent();
	GameObject(const std::string& name,std::vector<ObjectState>& states, const std::string& currentState);
public:
	static GameObject* create(const std::string& name,std::vector<ObjectState>& states, const std::string& currentState);
	virtual ~GameObject();

	void SetStrategy(ObjectStrategy* strategy);

	bool SetState(const std::string& name);
	void SetNextState();
	std::string GetName() const {return mName;}

	void OnClicked(const cocos2d::CCPoint& point);
	
	void onEnter();
	void onExit();
	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();
	virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
	
	cocos2d::CCSprite*				GetCurrentSprite();
	std::string						GetCurrentState() const {return mCurrentState;}
	std::vector<cocos2d::CCSprite*>	GetSprites() const;
};


typedef std::list<GameObject*> GameObjectList;
typedef std::vector<GameObject*> GameObjectArray;

#endif