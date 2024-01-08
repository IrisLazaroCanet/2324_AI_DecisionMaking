#pragma once
#include "FSMState.h"
#include <iostream>
#include "SeekBehavior.h"

class FSMState_Chase : public FSMState
{
public:
	void Enter(Agent* agent, Agent* target) override;
	StateType Update(Agent* agent, Agent* target, float dtime) override;
	void Exit(Agent* agent, Agent* target) override;

private:
};