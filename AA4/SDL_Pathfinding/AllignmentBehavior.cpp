#include "AllignmentBehavior.h"

AlignmentBehavior::AlignmentBehavior()
{

}

AlignmentBehavior::~AlignmentBehavior()
{
}

Vector2D AlignmentBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    //1 Initialize variables to calculate average velocity and agent count
    Vector2D averageVelocity;
    int agentCount = 0;

    //2 Iterate through the agent's neighbors
    for (Agent* neighbor : agent->getNeighbors())
    {
        //3 Calculate distance to neighbor
        float distance = Vector2D::Distance(agent->getPosition(), neighbor->getPosition());

        //4 Check if the neighbor is within the alignment radius
        if (distance > 0 && distance < agent->getAlignmentRadius())
        {
            //5 Accumulate the neighbor's velocity to calculate the average
            averageVelocity += neighbor->getVelocity();
            agentCount++;
        }
    }

    // If there are suitable neighbors for alignment
    if (agentCount > 0)
    {
        // Calculate the average velocity by dividing the sum by the count
        averageVelocity /= agentCount;

        // Calculate the steering force towards the average velocity
        Vector2D alignmentForce = (averageVelocity - agent->getVelocity()).Normalize() * agent->getMaxForce();
        return alignmentForce;
    }

    // If no suitable neighbors are found, return zero steering force
    return Vector2D(0, 0);
}

Vector2D AlignmentBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->getPosition(), dtime);
}