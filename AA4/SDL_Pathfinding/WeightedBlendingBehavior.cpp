#include "WeightedBlendingBehavior.h"

WeightedBlendingBehavior::WeightedBlendingBehavior(map<SteeringBehavior*, float> _behaviors)
{
	behaviors = _behaviors;
}

WeightedBlendingBehavior::~WeightedBlendingBehavior()
{
}

Vector2D WeightedBlendingBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    Vector2D totalForce;

    // Iterate through each behavior and calculate its force
    for (const auto& behaviorWeightPair : behaviors)
    {
        SteeringBehavior* behavior = behaviorWeightPair.first;
        float weight = behaviorWeightPair.second;

        // Calculate the force from the behavior
        Vector2D behaviorForce = behavior->CalculateForces(agent, target, dtime);
        // Add the weighted force to the total force
        totalForce += behaviorForce * weight;
    }
    return totalForce;
}

Vector2D WeightedBlendingBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return CalculateForces(agent, target->position, dtime);
}