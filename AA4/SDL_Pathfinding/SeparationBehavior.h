#pragma once
#include "SteeringBehavior.h"

class Agent;

class SeparationBehavior : public SteeringBehavior
{
public:
    SeparationBehavior();
    ~SeparationBehavior();
    virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
    virtual Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
};


