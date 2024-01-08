#pragma once
#include "Agent.h"
#include <vector>

class PriorityBlendingBehavior : public Agent::SteeringBehavior
{
public:
    PriorityBlendingBehavior(std::initializer_list<SteeringBehavior*> behaviors);
    ~PriorityBlendingBehavior();

    SteeringBehavior* getBehavior(int index) const { return behaviors[index]; }

    virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
    virtual Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;

private:
    std::vector<SteeringBehavior*> behaviors;
    float threshold; // Threshold value for behavior force
};


