#pragma once
#include "FSMState.h"
#include <iostream>

class FSMState_Patrol : public FSMState
{
private:
	int min;
	int max;
	bool canGenerateNextPatrolPosition = true;
	int patrolPosX;
	int patrolPosY;

	//TEST
	//TODO: Remove this test
	float timeSinceEnter;
	//

public:
	void Enter(Agent* agent) override;
	StateType Update(Agent* agent, float dtime) override;
	void Exit(Agent* agent) override;
};