#include "FSMState_Patrol.h"

void FSMState_Patrol::Enter(Agent* agent)
{
	timeSinceEnter = 0;
}

StateType FSMState_Patrol::Update(Agent* agent, float dtime)
{
	timeSinceEnter += dtime;
	//Agent deploy state actions / movement
	std::cout << "Patrol";

	//Transitions between states are checked here!
	//..

	//TEST
	//Change to chase
	if (timeSinceEnter >= 0.5f)
		return StateType::CHASE;
	else
		return StateType::NONE;

	/*
	* if(should_change_state) return new_state;
	* else
	return nullptr;
	*/
}

void FSMState_Patrol::Exit(Agent* agent)
{
}
