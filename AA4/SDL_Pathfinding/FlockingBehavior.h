#pragma once
#include "SteeringBehavior.h"

#include "PriorityBlendingBehavior.h"
#include "WeightedBlendingBehavior.h"
#include "CohesionBehavior.h"
#include "SeparationBehavior.h"
#include "AllignmentBehavior.h"

class Agent;

class FlockingBehavior : public SteeringBehavior
{
private:
	WeightedBlendingBehavior* weightedBlending;
	float cohesionWeight;
	float separationWeight;
	float alignmentWeight;

public:
	FlockingBehavior(float _cohesionWeight, float _separationWeight, float _alignmentWeight);
	~FlockingBehavior();

	virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
	virtual Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
};