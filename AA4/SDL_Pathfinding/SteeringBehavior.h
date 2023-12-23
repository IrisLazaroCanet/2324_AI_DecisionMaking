#pragma once
#include "Agent.h"
#include "Vector2D.h"

class Agent;

class SteeringBehavior
{
public:
	SteeringBehavior();
	~SteeringBehavior();

	virtual Vector2D CalculateForces(Agent *agent, Vector2D target, float dtime) = 0;
	virtual Vector2D CalculateForces(Agent *agent, Agent *target, float dtime) = 0;
};

