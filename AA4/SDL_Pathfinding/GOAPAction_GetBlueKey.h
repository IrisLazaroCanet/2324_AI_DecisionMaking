#pragma once
#include "GOAPAction.h"

class GOAPAction_GetBlueKey : public GOAPAction
{
public:
	GOAPAction_GetBlueKey();
	~GOAPAction_GetBlueKey();
	void Update(Agent* agent, float dtime) override;
};