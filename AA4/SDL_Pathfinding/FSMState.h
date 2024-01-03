#pragma once
#include "Agent.h"

enum class StateType { CHASE, EVADE, PATROL, NONE };

class FSMState
{
public:
	FSMState() { }
	~FSMState() { }
	virtual void Enter(Agent* agent, float dtime) = 0;
	virtual StateType Update(Agent* agent, float dtime) = 0;
	virtual void Exit(Agent* agent, float dtime) = 0;
};