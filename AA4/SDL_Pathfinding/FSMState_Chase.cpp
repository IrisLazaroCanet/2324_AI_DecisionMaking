#include "FSMState_Chase.h"

void FSMState_Chase::Enter(Agent* agent, Agent* target)
{
	agent->setBehavior(new SeekBehavior());
}

StateType FSMState_Chase::Update(Agent* agent, Agent* target, float dtime)
{
	float distanceToTarget = Vector2D::Distance(agent->getPosition(), target->getPosition());

	agent->applySteeringBehavior(target, dtime, agent->getPosition(), false);


	if (distanceToTarget < agent->distanceThreshold && target->agentHasGunEquipped)
	{
		return StateType::EVADE;
	}

	else if (distanceToTarget > agent->distanceThreshold)
	{
		return StateType::PATROL;
	}

	return StateType::NONE;
}

void FSMState_Chase::Exit(Agent* agent, Agent* target)
{
}
