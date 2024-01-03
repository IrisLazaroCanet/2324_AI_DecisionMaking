#pragma once
#include "FSMState.h"
#include <iostream>

class FSMState_Evade : public FSMState
{
public:

	void Enter(Agent* agent, float dtime) override;
	StateType Update(Agent* agent, float dtime) override;
	void Exit(Agent* agent, float dtime) override;
};