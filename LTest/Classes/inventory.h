#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <map>
#include "GameObject.h"

class Inventory
{
	//TODO: Probably following container is
	//not good choice for inventory,
	//need to investigate this topic

	static const size_t CellsCount = 3;
	std::vector<GameObjectList> mCells;

	Inventory();
public:

	static Inventory& GetInstance();

	void			Clear();
	bool			AddItems(GameObject* object);
	GameObjectList	GetItem(const std::string& name);
	GameObjectList	GetItem(size_t index);
	size_t			GetSize() const {return CellsCount;}
};
#endif