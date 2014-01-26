#include "inventory.h"
#include "ObjectFactory.h"
#include <algorithm>

using namespace std;

Inventory::Inventory()
{

}

Inventory& Inventory::GetInstance()
{
	static Inventory inst;
	return inst;
}

bool Inventory::AddItem(GameObject* object)
{
	for(size_t i = 0; i < mItems.size(); ++i)
	{
		if (mItems[i].AddItem(object))
			return true;
	}

	if( mItems.size() < CellsCount )
	{
		InventoryItem item(object->GetName());
		item.AddItem(object);

		mItems.push_back(item);
		return true;
	}
	return false;
}

size_t Inventory::GetItemCount(const std::string& name)
{
	for(size_t i = 0; i < mItems.size(); ++i)
		if(mItems[i].GetName() == name)
			return mItems[i].GetObjectsCount();
	return 0;
}

void Inventory::Clear()
{
	mItems.clear();
}

Inventory::InventoryItem::~InventoryItem()
{
	//for(size_t i = 0; i < mObjects.size(); ++i)
		//mObjects[i]->release();
	//mObjectToDraw->release();
}
Inventory::InventoryItem::InventoryItem(const std::string& name)
	:mName(name)
{
	mObjectToDraw = ObjectFactory::Create(name, "Collected");
	mObjectToDraw->retain();
}

std::string Inventory::InventoryItem::GetName()
{
	return mName;
}

bool Inventory::InventoryItem::AddItem(GameObject* object)
{
	if(object->GetName() != mName)
		return false;
	object->removeFromParent();
	object->retain();
	mObjects.push_back(object);
	return true;
}

size_t Inventory::InventoryItem::GetObjectsCount()
{
	return mObjects.size();
}

GameObject* Inventory::InventoryItem::GetCollectableGameObject()
{
	return mObjectToDraw;
}