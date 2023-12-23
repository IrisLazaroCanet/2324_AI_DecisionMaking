#include "FSM.h"

void FSM::ChangeState(FSMState* newState)
{
	currentState->Exit();
	currentState = newState;
	currentState->Enter();
}

FSM::~FSM()
{
	delete currentState;
}

void FSM::Update(Agent* agent, float dtime)
{
	FSMState* newState = currentState->Update(agent, dtime);
	
	if (newState != nullptr)
	{
		ChangeState(newState);
	}
}