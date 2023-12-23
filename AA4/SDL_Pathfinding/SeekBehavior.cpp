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
	Vector2D desiredVelocity = target - agent->getPosition();
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

Vector2D SeekBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return CalculateForces(agent, target->getPosition(), dtime);
}
