#include "FSMState_Chase.h"

void FSMState_Chase::Enter(Agent* agent, Agent* target)
{
	agent->setBehavior(new SeekBehavior());
}

StateType FSMState_Chase::Update(Agent* agent, Agent* target, float dtime)
{
	//Agent deploy state actions / movement
	//agent->setTarget(target->getPosition());
	std::cout << "Chase";
	agent->ApplySteeringBehavior(target, dtime);

	/*
	Vector2D sterring_force = agent->getBehavior()->CalculateForces(agent, target, dtime);
	
	agent->setVelocity(
		agent->getVelocity() + sterring_force * dtime
	);
	agent->setVelocity(
		agent->getVelocity().Truncate(agent->getMaxVelocity())
	);

	agent->setPosition(
		agent->getPosition() + agent->getVelocity() * dtime
	);

	agent->updateOrientation();
	*/

	//Transitions between states are checked here!
	//..

	/*
	* if(should_change_state) return new_state (StateType enum);
	* else
	* */
	return StateType::NONE;
}

void FSMState_Chase::Exit(Agent* agent, Agent* target)
{
}
