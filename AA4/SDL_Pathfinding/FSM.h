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
	void ChangeState(StateType newStateType, Agent* agent, Agent* target, float dtime);

	std::map<StateType, FSMState*> availableStates;

public:

	FSM(FSMState* _currentState, Agent* agent, Agent* target);
	~FSM();
	void Update(Agent* agent, Agent* target, float dtime) override;

	FSMState* GetCurrentState() { return currentState; }
};