#pragma once
#include "GOAPAction.h"

class GOAPAction_Patrol : GOAPAction
{
public:
	void Update(Agent* agent, float dtime) override;
};