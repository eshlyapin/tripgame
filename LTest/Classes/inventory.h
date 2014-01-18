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
	std::vector< std::pair<std::string, size_t> > mCells;
	
	Inventory();
public:

	static Inventory& GetInstance();

	void			Clear();
	bool			AddItems(GameObject* object);
	GameObject*		GetItem(const std::string& name);
	GameObject*		GetItem(size_t index);
	size_t			GetItemCount(const std::string& name);
	size_t			GetItemCount(size_t index);
	size_t			GetSize() const {return CellsCount;}
};
#endif