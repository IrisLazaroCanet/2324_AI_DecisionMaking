#pragma once
#include "FSMState.h"
#include <iostream>
//#include <WanderBehavior.h>

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
	void Enter(Agent* agent, Agent* target) override;
	StateType Update(Agent* agent, Agent* target, float dtime) override;
	void Exit(Agent* agent, Agent* target) override;
};