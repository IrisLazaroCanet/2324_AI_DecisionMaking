#include "FlockingBehavior.h"

FlockingBehavior::FlockingBehavior(float _cohesionWeight, float _separationWeight, float _alignmentWeight)
{
	//Weighted blending: flocking. Can also be done with priority and works just as fine
	//We chose Weighted Blending for the example

	weightedBlending = new WeightedBlendingBehavior({
		{new CohesionBehavior(), _cohesionWeight},
		{new SeparationBehavior(), _separationWeight},
		{new AlignmentBehavior(), _alignmentWeight}
		});
}

FlockingBehavior::~FlockingBehavior()
{
}

Vector2D FlockingBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
	return weightedBlending->CalculateForces(agent, target, dtime);
}

Vector2D FlockingBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return weightedBlending->CalculateForces(agent, target, dtime);
}