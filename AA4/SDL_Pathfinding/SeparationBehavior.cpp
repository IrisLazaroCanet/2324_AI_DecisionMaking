#include "SeparationBehavior.h"
#include "Agent.h"

SeparationBehavior::SeparationBehavior()
{
}

SeparationBehavior::~SeparationBehavior()
{
}

Vector2D SeparationBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    //1 Initialize variables to calculate the separation force and neighbor count
    Vector2D separationForce;
    int neighborCount = 0;
    //2 Iterate through the agent's neighbors
    for (Agent* neighbor : agent->getNeighbors())
    {
        //3 Calculate the distance to the neighbor
        float distance = Vector2D::Distance(agent->getPosition(), neighbor->getPosition());

        //4 Check if the neighbor is within the separation radius (avoid division by zero)
        if (distance > 0 && distance < agent->getSeparationRadius())
        {
            //5 Calculate the separation vector from the neighbor
            Vector2D separation = agent->getPosition() - neighbor->getPosition();
            //6 Weight the separation vector by the inverse of the distance
            separation /= distance;
            separation *= agent->getMaxForce();
            //7 Accumulate the separation force
            separationForce += separation;
            neighborCount++;
        }
    }
    //8 If there are suitable neighbors for separation
    if (neighborCount > 0)
    {
        //9 Average the separation force based on the number of neighbors
        separationForce /= static_cast<float>(neighborCount);
        return separationForce;
    }
    //10 If no suitable neighbors are found, return zero steering force
    return Vector2D(0, 0);
}

Vector2D SeparationBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->getPosition(), dtime);
}

