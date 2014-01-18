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

bool Inventory::AddItems(GameObject* object)
{
	for(size_t i = 0; i < mCells.size(); ++i)
	{
		string currentName = mCells[i].first;
		if(currentName == object->GetName())
		{
			object->removeFromParent();
			mCells[i].second++;
			return true;
		}
	}

	if( mCells.size() < CellsCount )
	{
		mCells.push_back(pair<string,size_t>(object->GetName(),1));
		object->removeFromParent();
		return true;
	}
	return false;
}

GameObject* Inventory::GetItem(const std::string& name)
{
	for(size_t i = 0; i < mCells.size(); ++i)
	{
		string currentName = mCells[i].first;
		if(currentName == name)
		{
			return ObjectFactory::Create(currentName, "Collected");
		}
	}
	return 0;
}


GameObject* Inventory::GetItem(size_t index)
{
	if(mCells.size() <= index)
		return 0;
	string objectName = mCells[index].first;
	return ObjectFactory::Create(objectName, "Collected");
}

size_t Inventory::GetItemCount(const std::string& name)
{
	for(size_t i = 0; i < mCells.size(); ++i)
	{
		string currentName = mCells[i].first;
		if(currentName == name)
		{
			return mCells[i].second;
		}
	}
	return 0;
}

size_t Inventory::GetItemCount(size_t index)
{
	if(mCells.size() <= index)
		return 0;
	return mCells[index].second;
}

void Inventory::Clear()
{
	mCells.clear();
}