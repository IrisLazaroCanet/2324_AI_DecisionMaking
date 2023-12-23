#pragma once
#include "SteeringBehavior.h"
#include <map>

using namespace std;

class Agent;

class WeightedBlendingBehavior : public SteeringBehavior
{
public:
	WeightedBlendingBehavior(map<SteeringBehavior*, float> _behaviors);
	~WeightedBlendingBehavior();

	virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
	virtual Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
	
private:
	//A map allows us to associate each behavior with its weight. It's better than having two separate vectors.
	map<SteeringBehavior*, float> behaviors;
};