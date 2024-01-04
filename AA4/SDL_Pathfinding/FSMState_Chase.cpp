#include "FSMState_Chase.h"

void FSMState_Chase::Enter(Agent* agent)
{
	agent->setBehavior(&seekBehaviour);
}

StateType FSMState_Chase::Update(Agent* agent, float dtime)
{
	//Agent deploy state actions / movement
	//...

	//Transitions between states are checked here!
	//..
	agent->setTarget(agent->getTarget());
	std::cout << "Chase";
	/*
	* if(should_change_state) return new_state (StateType enum);
	* else
	* */
	return StateType::NONE;
}

void FSMState_Chase::Exit(Agent* agent)
{
}
