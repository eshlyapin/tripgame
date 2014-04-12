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

public:
	virtual bool init(const std::string& backgroundPath);
	virtual ~SampleScene();
	void update(float delta);
};

#endif