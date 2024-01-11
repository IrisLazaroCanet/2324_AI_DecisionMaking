#include "FSMState_Evade.h"

void FSMState_Evade::Enter(Agent* agent, Agent* target)
{
	agent->setBehavior(new FleeBehavior());
}

StateType FSMState_Evade::Update(Agent* agent, Agent* target, float dtime)
{
	float distanceToTarget = Vector2D::Distance(agent->getPosition(), target->getPosition());

	agent->applySteeringBehavior(target, dtime, agent->getPosition(), false);

	if (distanceToTarget < agent->distanceThreshold && target->agentHasGunEquipped == false)
	{
		return StateType::CHASE;
	}

	else if (distanceToTarget > agent->distanceThreshold)
	{
		return StateType::PATROL;
	}

	return StateType::NONE;
}

void FSMState_Evade::Exit(Agent* agent, Agent* target)
{
}
