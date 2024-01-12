#pragma once
#include "GOAPAction.h"

class GOAPAction_GetCoin : public GOAPAction
{
public:
	GOAPAction_GetCoin();
	~GOAPAction_GetCoin();
	void Update(Agent* agent, float dtime) override;
};