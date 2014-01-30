#ifndef STRUCTOBJECT_H
#define STRUCTOBJECT_H

#include <string>
#include "cocos2d.h"

struct structObject
{
	std::string name;
	std::string state;
	cocos2d::CCPoint point;
};
#endif