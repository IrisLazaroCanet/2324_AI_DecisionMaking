#pragma once
#include "Agent.h"

//class Agent;

class SeekBehavior : public Agent::SteeringBehavior
{
public:
	SeekBehavior();
	~SeekBehavior();

	virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
	virtual Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
};