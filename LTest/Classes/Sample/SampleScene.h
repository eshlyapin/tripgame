#ifndef _SAMPLESCENE_H
#define _SAMPLESCENE_H

#include "GameScreen.h"
#include "ObjectStrategy.h"
#include "Sample\ClickableStrategy.h"

class ClickableStrategy;

class SampleScene : public GameScreen
{
	ToggleStrategy mToggleStrategy;
	CollectStrategy mCollectStrategy;
	ClickableStrategy *mClickableStrategy;

	SampleScene(){};
public:
	
	virtual bool init();
	virtual ~SampleScene();
	void update(float delta);
	CREATE_FUNC(SampleScene);
};

#endif