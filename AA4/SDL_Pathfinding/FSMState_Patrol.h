#pragma once
#include "FSMState.h"
#include <iostream>

class FSMState_Patrol : public FSMState
{
public:
	void Enter(/*Agent* agent, float dtime*/) override;
	FSMState* Update(Agent* agent, float dtime) override;
	void Exit(/*Agent* agent, float dtime*/) override;
};