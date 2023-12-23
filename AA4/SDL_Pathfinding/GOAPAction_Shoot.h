#pragma once
#include "GOAPAction.h"

class GOAPAction_Shoot : GOAPAction
{
public:
	void Update(Agent* agent, float dtime) override;
};