#pragma once
#include "GOAPAction.h"

class GOAPAction_Aim : GOAPAction
{
public:
	GOAPAction_Aim() { }
	~GOAPAction_Aim() { }
	void Update(Agent* agent, float dtime) override;
};