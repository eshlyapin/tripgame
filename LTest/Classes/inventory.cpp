#include "inventory.h"
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

bool Inventory::AddItems(GameObject* object)
{
	for(size_t i = 0; i < mCells.size(); ++i)
	{
		GameObjectList objs = mCells[i];
		if(objs.front()->GetName() == object->GetName())
		{
			objs.push_back(object);
			mCells[i] = objs;
			return true;
		}
	}

	if(mCells.size() < CellsCount)
	{
		GameObjectList objs;
		objs.push_back(object);
		mCells.push_back(objs);
		return true;
	}

	return false;
}

GameObjectList Inventory::GetItem(const std::string& name)
{
	for(size_t i = 0; i < mCells.size(); ++i)
	{
		GameObjectList objs = mCells[i];
		if(objs.front()->GetName() == name)
		{
			return mCells[i];
		}
	}
	return GameObjectList();
}


GameObjectList Inventory::GetItem(size_t index)
{
	if(index < mCells.size())
		return mCells[index];
	else
		return GameObjectList();
}