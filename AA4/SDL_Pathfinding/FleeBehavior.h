#pragma once
#include "Agent.h"

//class Agent;

class FleeBehavior : public Agent::SteeringBehavior
{
public:
	FleeBehavior();
	~FleeBehavior();

	virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
	virtual Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
};