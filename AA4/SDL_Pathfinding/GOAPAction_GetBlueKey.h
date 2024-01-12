#pragma once
#include "GOAPAction.h"

class GOAPAction_GetBlueKey : GOAPAction
{
public:
	GOAPAction_GetBlueKey();
	~GOAPAction_GetBlueKey();
	void Update(Agent* agent, float dtime) override;
};