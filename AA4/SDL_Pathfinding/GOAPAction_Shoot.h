#pragma once
#include "GOAPAction.h"

class GOAPAction_Shoot : GOAPAction
{
public:
	GOAPAction_Shoot() { }
	~GOAPAction_Shoot() { }
	void Update(Agent* agent, float dtime) override;
};