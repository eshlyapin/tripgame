#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "GameObject.h"
#include <string>

class ObjectFactory
{
public:
	static GameObject* Create(const std::string& name, const std::string& curState);
};

#endif