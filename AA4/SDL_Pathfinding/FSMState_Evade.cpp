#include "FSMState_Evade.h"

void FSMState_Evade::Enter(Agent* agent, Agent* target)
{
	agent->setBehavior(new FleeBehavior());
}

StateType FSMState_Evade::Update(Agent* agent, Agent* target, float dtime)
{
	float distanceToTarget = Vector2D::Distance(agent->getPosition(), target->getPosition());
	//Agent deploy state actions / movement
	//agent->getBehavior()->CalculateForces(agent, target, dtime);
	agent->applySteeringBehavior(target, dtime);
	//Transitions between states are checked here!
	//..

	/*
	* if(should_change_state) return new_state (StateType enum);
	* else
	*/
	if (distanceToTarget > agent->distanceThreshold)
	{
		return StateType::PATROL;
	}

	return StateType::NONE;
}

void FSMState_Evade::Exit(Agent* agent, Agent* target)
{
}
