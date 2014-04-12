#ifndef STRUCTOBJECT_H
#define STRUCTOBJECT_H

#include <string>
#include "cocos2d.h"

struct structObject
{
	std::string name;
	std::string state;
	cocos2d::CCPoint point;

	structObject(std::string& Name, std::string& State, cocos2d::CCPoint& Point) : name(Name), state(State), point(Point) {}
};
#endif