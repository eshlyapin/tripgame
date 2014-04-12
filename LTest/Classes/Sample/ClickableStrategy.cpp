#include "clickableStrategy.h"

ClickableStrategy::ClickableStrategy(GameScene* scene)
	:ownerScene(scene)
{
}

void ClickableStrategy::OnClicked(GameObject* owner, const cocos2d::CCPoint& point)
{	
	ownerScene->ShowTooltip("Take all coins and key!!", point);	
}