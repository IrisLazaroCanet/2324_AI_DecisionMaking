#pragma once
#include "FSMState.h"
#include "Agent.h"

class FSM : public Agent::DecisionMakingAlgorithm
{
private:
	FSMState* currentState;

	void ChangeState(FSMState* newState);

public:
	FSM(FSMState* _currentState) { currentState = _currentState; }
	~FSM();

	void Update(Agent* agent, float dtime) override;
};