#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <map>
#include "GameObject.h"

class Inventory
{
public:
	class InventoryItem
	{
		std::vector<GameObject*> mObjects;
		std::string mName;
		GameObject* mObjectToDraw;

	public:
						InventoryItem(const std::string& name);
						~InventoryItem();
		std::string		GetName();		
		bool			AddItem(GameObject* object);
		size_t			GetObjectsCount();
		GameObject*		GetCollectableGameObject();
	};
private:

	//TODO: Probably following container is
	//not good choice for inventory,
	//need to investigate this topic

	static const size_t CellsCount = 3;
	std::vector<InventoryItem> mItems;
	
	Inventory();
public:

	static Inventory& GetInstance();

	void						Clear();
	bool						AddItem(GameObject* object);
	size_t						GetItemCount(const std::string& name);

	std::vector<InventoryItem>	GetInvenotryItems() const {return mItems;}
	size_t						GetSize() const {return CellsCount;}
};
#endif