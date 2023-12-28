#pragma once
#include "GOAPAction.h"

class GOAPAction_Patrol : GOAPAction
{
public:
	GOAPAction_Patrol() { }
	~GOAPAction_Patrol() { }
	void Update(Agent* agent, float dtime) override;
};