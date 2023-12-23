#pragma once
#include "GOAPWorldState.h"
#include "Agent.h"

class GOAPAction
{
public:
	GOAPWorldState preconditions;
	GOAPWorldState effects;
	float cost;

	GOAPAction() { }
	~GOAPAction() { }
	void SetPreconditions(int idx, bool value);
	void SetEffect(int idx, bool value);
	virtual void Update(Agent* agent, float dtime) = 0;
};