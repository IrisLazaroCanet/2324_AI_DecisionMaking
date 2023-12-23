#pragma once
#include "SteeringBehavior.h"
#include <vector>

class Agent;

class CohesionBehavior : public SteeringBehavior
{
public:
    CohesionBehavior();
    ~CohesionBehavior();
    virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
    virtual Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
};

