#pragma once
#include "GOAPAction.h"

class GOAPAction_Aim : GOAPAction
{
public:
	void Update(Agent* agent, float dtime) override;
};