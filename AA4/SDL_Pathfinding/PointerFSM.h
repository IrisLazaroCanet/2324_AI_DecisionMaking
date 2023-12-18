#pragma once
#include "PointerStateTemplate.h"

class PointerFSM
{
protected:
	PointerStateTemplate* currentState;
	void ChangeState(PointerStateTemplate* newState);
};