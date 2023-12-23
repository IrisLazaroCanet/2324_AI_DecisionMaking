#include "PriorityBlendingBehavior.h"

PriorityBlendingBehavior::PriorityBlendingBehavior(std::initializer_list<SteeringBehavior*> behaviors)
    : behaviors(behaviors), threshold(2.0f) // Initialize the threshold to a value that we want
{
}

PriorityBlendingBehavior::~PriorityBlendingBehavior()
{
}

Vector2D PriorityBlendingBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    Vector2D totalForce;

    // Iterate through behaviors in the order they are provided
    for (SteeringBehavior* behavior : behaviors)
    {
        // Calculate the force from the current behavior
        Vector2D behaviorForce = behavior->CalculateForces(agent, target, dtime);

        // Check if the behavior force magnitude exceeds the threshold
        if (behaviorForce.LengthSquared() >= threshold * threshold)
        {
            // If it does, return the behavior's force immediately
            return behaviorForce;
        }

        // Otherwise, accumulate the behavior's force into the total force
        totalForce += behaviorForce;
    }

    // If no behavior force exceeds the threshold, return the accumulated force
    return totalForce;
}

Vector2D PriorityBlendingBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->position, dtime);
}
