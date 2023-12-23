#include "FSMState_Evade.h"

void FSMState_Evade::Enter(/*Agent* agent, float dtime*/)
{
}

FSMState* FSMState_Evade::Update(Agent* agent, float dtime)
{
	//Agent deploy state actions / movement
	//...

	//Transitions between states are checked here!
	//..

	/*
	* if(should_change_state) return new_state;
	* else
	*/
	return nullptr;
}

void FSMState_Evade::Exit(/*Agent* agent, float dtime*/)
{
}
