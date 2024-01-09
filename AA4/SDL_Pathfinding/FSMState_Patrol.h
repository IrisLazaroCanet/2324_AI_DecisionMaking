#pragma once
#include "FSMState.h"
#include <iostream>
#include "SeekBehavior.h"
//#include <WanderBehavior.h>

class FSMState_Patrol : public FSMState
{
private:
	int min;
	int max;
	bool canGenerateNextPatrolPosition = true;
	int patrolPosX;
	int patrolPosY;
	float timer;

	int randomX;
	int randomY;

	//TEST
	//TODO: Remove this test
	float timeSinceEnter;
	Vector2D randomPos;
	//

public:
	void Enter(Agent* agent, Agent* target) override;
	StateType Update(Agent* agent, Agent* target, float dtime) override;
	void Exit(Agent* agent, Agent* target) override;
};