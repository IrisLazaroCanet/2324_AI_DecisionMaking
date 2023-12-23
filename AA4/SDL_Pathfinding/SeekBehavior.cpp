#include "SeekBehavior.h"

SeekBehavior::SeekBehavior()
{
}

SeekBehavior::~SeekBehavior()
{
}

Vector2D SeekBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
	//Calculate desired velocity
	Vector2D desiredVelocity = target - agent->position;
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

Vector2D SeekBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return CalculateForces(agent, target->position, dtime);
}
