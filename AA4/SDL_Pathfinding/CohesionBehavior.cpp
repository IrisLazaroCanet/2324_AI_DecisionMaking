#include "CohesionBehavior.h"
#include "Agent.h"

CohesionBehavior::CohesionBehavior()
{

}

CohesionBehavior::~CohesionBehavior()
{
}

Vector2D CohesionBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    //1 Initialize variables to calculate the center of mass and agent count

    Vector2D centerOfMass;
    int agentCount = 0;

    //2 Iterate through the agent's neighbors
    for (Agent* neighbor : agent->getNeighbors())
    {
        //3 Calculate distance to neighbor
        float distance = Vector2D::Distance(agent->getPosition(), neighbor->getPosition());

        //4 Check if the neighbor is within the cohesion radius
        if (distance > 0 && distance < agent->getCohesionRadius())
        {
            //5 Accumulate the neighbor's position to calculate the center of mass
            centerOfMass += neighbor->getPosition();
            agentCount++;
        }
    }
    //6 If there are suitable neighbors for cohesion
    if (agentCount > 0)
    {
        //7 Calculate the center of mass by dividing the sum by the count
        centerOfMass /= agentCount;

        //8 Calculate the steering force towards the center of mass
        Vector2D cohesionForce = (centerOfMass - agent->getPosition()).Normalize() * agent->getMaxForce();
        return cohesionForce;
    }

    return Vector2D(0, 0);
}

Vector2D CohesionBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->getPosition(), dtime);
}

