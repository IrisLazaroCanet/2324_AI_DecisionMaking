#include "FleeBehavior.h"

FleeBehavior::FleeBehavior()
{
}

FleeBehavior::~FleeBehavior()
{
}

Vector2D FleeBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
	Vector2D desiredVelocity = agent->getPosition() - target;
	desiredVelocity.Normalize();
	desiredVelocity *= agent->getMaxVelocity();

	//Steering force, without acceleration
	Vector2D steeringForce = (desiredVelocity - agent->getVelocity());
	steeringForce /= agent->getMaxVelocity();
	steeringForce *= agent->getMaxForce();

	//Steering force, with acceleration
	steeringForce = steeringForce / agent->getMass();
	return steeringForce;
}

Vector2D FleeBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return CalculateForces(agent, target->getPosition(), dtime);
}
