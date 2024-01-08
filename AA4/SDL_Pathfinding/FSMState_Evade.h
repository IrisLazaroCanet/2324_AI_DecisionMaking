#pragma once
#include "FSMState.h"
#include <iostream>
#include "FleeBehavior.h"

class FSMState_Evade : public FSMState
{
public:
	void Enter(Agent* agent, Agent* target) override;
	StateType Update(Agent* agent, Agent* target, float dtime) override;
	void Exit(Agent* agent, Agent* target) override;

private:
};