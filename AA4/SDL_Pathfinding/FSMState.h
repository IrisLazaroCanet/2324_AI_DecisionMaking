#pragma once
#include "Agent.h"

enum class StateType { CHASE, EVADE, PATROL, NONE };

class FSMState
{
public:
	FSMState() { }
	~FSMState() { }
	virtual void Enter(Agent* agent, Agent* target) = 0;
	virtual StateType Update(Agent* agent, Agent* target, float dtime) = 0;
	virtual void Exit(Agent* agent, Agent* target) = 0;
};