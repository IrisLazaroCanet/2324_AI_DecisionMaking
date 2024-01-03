#include "FSMState_Patrol.h"

void FSMState_Patrol::Enter(Agent* agent, float dtime)
{
}

FSMState* FSMState_Patrol::Update(Agent* agent, float dtime)
{
	//Agent deploy state actions / movement
	std::cout << "A";

	//Transitions between states are checked here!
	//..

	/*
	* if(should_change_state) return new_state;
	* else
	*/
	return nullptr;
}

void FSMState_Patrol::Exit(Agent* agent, float dtime)
{
}
