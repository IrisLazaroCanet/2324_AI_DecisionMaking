#pragma once
//#include "FSMState.h"
#include "Agent.h"
#include <map>

#include "FSMState_Chase.h"
#include "FSMState_Evade.h"
#include "FSMState_Patrol.h"

class FSM : public Agent::DecisionMakingAlgorithm
{
private:
	FSMState* currentState;
	void ChangeState(StateType newStateType, Agent* agent, float dtime);

	std::map<StateType, FSMState*> availableStates;

public:

	FSM(FSMState* _currentState);
	~FSM();
	void Update(Agent* agent, float dtime) override;
};