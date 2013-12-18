#include "ObjectStrategy.h"
#include "GameObject.h"
#include "inventory.h"
#include "Log.h"

ToggleStrategy::ToggleStrategy(GameObject* object)
	:ObjectStrategy(object)
{
}

void ToggleStrategy::OnClicked(const cocos2d::CCPoint& point)
{
	mObject->SetNextState();
}

CollectStrategy::CollectStrategy(GameObject* object)
	:ObjectStrategy(object)
{
}

void CollectStrategy::OnClicked(const cocos2d::CCPoint& point)
{
	if(mObject->GetCurrentState() != "Collected")
	{
		if(mObject->SetState("Collected"))
			Inventory::GetInstance().AddItems(mObject);
		else
			LOG_ERR("ITEM HAS NOT COLLECTABLE STATE!");
	}
}