#ifndef _OBJECT_STRATEGY_H
#define _OBJECT_STRATEGY_H


class ObjectStrategy
{
public:

	virtual void OnClicked() = 0;

	//The following methods are same...
	//virtual void OnMoved() = 0;
};

#endif