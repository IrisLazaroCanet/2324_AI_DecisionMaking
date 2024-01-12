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
	void SetPreconditions(FactKey key, int value);
	void SetEffect(FactKey key, int value);
	bool IsAchievable(const GOAPWorldState& worldState) const;
	virtual void Update(Agent* agent, float dtime) = 0;
};