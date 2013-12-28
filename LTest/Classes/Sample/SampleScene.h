#ifndef _SAMPLESCENE_H
#define _SAMPLESCENE_H

#include "GameScreen.h"
#include "ObjectStrategy.h"
class SampleScene : public GameScreen
{
	ToggleStrategy mToggleStrategy;
	CollectStrategy mCollectStrategy;

	SampleScene(){};
public:
	
	virtual bool init();

	CREATE_FUNC(SampleScene);
};

#endif