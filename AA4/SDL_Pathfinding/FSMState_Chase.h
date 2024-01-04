#pragma once
#include "FSMState.h"
#include <iostream>
#include "Seek.h"

class FSMState_Chase : public FSMState
{
public:
	void Enter(Agent* agent) override;
	StateType Update(Agent* agent, float dtime) override;
	void Exit(Agent* agent) override;

private:
	Seek seekBehaviour;
};