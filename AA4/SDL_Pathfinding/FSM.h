#pragma once
#include "FSMState.h"
#include "DecisionMakingAlgorithm.h"

class FSM : public DecisionMakingAlgorithm
{
private:
	FSMState* currentState;

	void ChangeState(FSMState* newState);

public:
	FSM(FSMState* _currentState);
	~FSM();

	void Update(Agent* agent, float dtime) override;
};