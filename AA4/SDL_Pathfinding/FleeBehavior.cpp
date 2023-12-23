#include "FleeBehavior.h"

FleeBehavior::FleeBehavior()
{
}

FleeBehavior::~FleeBehavior()
{
}

Vector2D FleeBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
	Vector2D desiredVelocity = agent->position - target;
	desiredVelocity.Normalize();
	desiredVelocity *= agent->max_velocity;

	//Steering force, without acceleration
	Vector2D steeringForce = (desiredVelocity - agent->velocity);
	steeringForce /= agent->max_velocity;
	steeringForce *= agent->max_force;

	//Steering force, with acceleration
	steeringForce = steeringForce / agent->mass;
	return steeringForce;
}

Vector2D FleeBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return CalculateForces(agent, target->position, dtime);
}
