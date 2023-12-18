#include "PointerFSM.h"

void PointerFSM::ChangeState(PointerStateTemplate* newState)
{
	currentState->Exit();
	currentState = newState;
	currentState->Enter();
}
