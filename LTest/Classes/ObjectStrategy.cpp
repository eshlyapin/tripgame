#include "ObjectStrategy.h"
#include "GameObject.h"
#include "inventory.h"
#include "Log.h"
#include "MessageBox.h"

ToggleStrategy::ToggleStrategy()
{
}

void ToggleStrategy::OnClicked(GameObject* owner, const cocos2d::CCPoint& point)
{
	owner->SetNextState();
	MBox *mbox = MBox::createWithText("You clicked on " + owner->GetName() + " ! ! ! ! ! ! ! ! ! ! ! !");//for test
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