#include "FSMState_Chase.h"

void FSMState_Chase::Enter(/*Agent* agent, float dtime*/)
{
}

FSMState* FSMState_Chase::Update(Agent* agent, float dtime)
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

void FSMState_Chase::Exit(/*Agent* agent, float dtime*/)
{
}
