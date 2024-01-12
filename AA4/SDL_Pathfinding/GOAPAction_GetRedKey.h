#pragma once
#include "GOAPAction.h"

class GOAPAction_GetRedKey : GOAPAction
{
public:
	GOAPAction_GetRedKey();
	~GOAPAction_GetRedKey();
	void Update(Agent* agent, float dtime) override;
};