#include "ObjectStrategy.h"
#include "GameObject.h"
#include "inventory.h"

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
		mObject->SetState("Collected");
		Inventory::GetInstance().AddItems(mObject);
	}
}