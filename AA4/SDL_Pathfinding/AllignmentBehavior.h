#pragma once
#include "SteeringBehavior.h"

class Agent;

class AlignmentBehavior : public SteeringBehavior
{
public:
    AlignmentBehavior();
    ~AlignmentBehavior();
    virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
    virtual Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
};
