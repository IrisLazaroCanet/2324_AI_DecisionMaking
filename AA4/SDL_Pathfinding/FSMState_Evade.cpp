#include "FSMState_Evade.h"

void FSMState_Evade::Enter(Agent* agent, float dtime)
{
	
}

StateType FSMState_Evade::Update(Agent* agent, float dtime)
{
	//Agent deploy state actions / movement
	//...

	//Transitions between states are checked here!
	//..

	/*
	* if(should_change_state) return new_state (StateType enum);
	* else
	*/
	return StateType::NONE;
}

void FSMState_Evade::Exit(Agent* agent, float dtime)
{
}
