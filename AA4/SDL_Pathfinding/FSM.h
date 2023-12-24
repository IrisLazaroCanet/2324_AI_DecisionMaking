#pragma once
#include "FSMState.h"
#include "Agent.h"

class FSM : public Agent::DecisionMakingAlgorithm
{
private:
	FSMState* currentState;

	// Function pointers for the current state's methods
	FSMState::EnterFunction currentStateEnter;
	FSMState::UpdateFunction currentStateUpdate;
	FSMState::ExitFunction currentStateExit;

	void ChangeState(FSMState* newState, Agent* agent);

public:

    FSM(FSMState* _currentState)
        : currentState(_currentState),
        currentStateEnter(nullptr),
        currentStateUpdate(nullptr),
        currentStateExit(nullptr)
    {
        // Initialize function pointers for the initial state
        if (currentState)
        {
            currentStateEnter = currentState->enter;
            currentStateUpdate = currentState->update;
            currentStateExit = currentState->exit;
        }
    }

	~FSM();

	void Update(Agent* agent, float dtime) override;
};