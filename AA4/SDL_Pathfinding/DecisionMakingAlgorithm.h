#pragma once
#include "Agent.h"

class DecisionMakingAlgorithm
{
public:
	DecisionMakingAlgorithm() { }
	~DecisionMakingAlgorithm() { }
	virtual void Update(Agent* agent, float dtime) = 0;
};