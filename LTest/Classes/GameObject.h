#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "cocos2d.h"
#include "pugixml.hpp"
#include <list>
#include <map>
#include <string>

class GameObject : public cocos2d::CCNode, public cocos2d::CCStandardTouchDelegate//cocos2d::CCTargetedTouchDelegate
{
	std::map<std::string, cocos2d::CCSprite*> mSpriteMap;
	std::string mCurrentState;
	std::string mName;

	bool LoadSprites(const std::string& name);
	void HideAll();
	void ShowCurrent();
	std::string ReadObjectName(pugi::xml_document& doc);

	public:
	GameObject(const std::string& name, const std::string& currentState);
	~GameObject();

	bool SetState(const std::string& name);
	std::string GetName() const {return mName;}

	void OnClicked(const cocos2d::CCPoint& point);
	
	void onEnter();
	void onExit();
	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();
	virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
	
	cocos2d::CCSprite* GetCurrentSprite() const;
	std::vector<cocos2d::CCSprite*> GetSprites() const;
};


typedef std::list<GameObject*> GameObjectList;

#endif