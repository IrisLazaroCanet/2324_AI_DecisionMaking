#pragma once
#include "Agent.h"

class FSMState
{
public:
	virtual void Enter(/*Agent* agent, float dtime*/) = 0;
	virtual FSMState* Update(Agent* agent, float dtime) = 0;
	virtual void Exit(/*Agent* agent, float dtime*/) = 0;
};