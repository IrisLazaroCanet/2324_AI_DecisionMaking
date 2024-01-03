#pragma once
#include "FSMState.h"
#include <iostream>

class FSMState_Patrol : public FSMState
{
private:
	//TEST
	//TODO: Remove this test
	float timeSinceEnter = 0;
public:
	void Enter(Agent* agent, float dtime) override;
	StateType Update(Agent* agent, float dtime) override;
	void Exit(Agent* agent, float dtime) override;
};