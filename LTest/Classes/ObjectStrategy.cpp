#include "ObjectStrategy.h"
#include "GameObject.h"
#include "inventory.h"
#include "Log.h"

ToggleStrategy::ToggleStrategy()
{
}

void ToggleStrategy::OnClicked(GameObject* owner, const cocos2d::CCPoint& point)
{
	owner->SetNextState();
}

CollectStrategy::CollectStrategy()
{
}

void CollectStrategy::OnClicked(GameObject* owner, const cocos2d::CCPoint& point)
{
	if(owner->GetCurrentState() != "Collected")
	{
		if(owner->SetState("Collected"))
			Inventory::GetInstance().AddItems(owner);
		else
			Logger.log(Log::Prioritiy_ERROR, "ITEM HAS NOT COLLECTABLE STATE!");
	}
}