#include "FSM.h"

FSM::FSM(FSMState* _currentState)
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


void FSM::ChangeState(FSMState* newState, Agent* agent)
{
    // Exit the current state
    if (currentStateExit)
        currentStateExit(agent);

    // Change to the new state
    currentState = newState;

    // Update function pointers for the new state
    if (currentState)
    {
        currentStateEnter = currentState->enter;
        currentStateUpdate = currentState->update;
        currentStateExit = currentState->exit;
    }

    // Enter the new state
    if (currentStateEnter)
        currentStateEnter(agent);
}


FSM::~FSM()
{
	delete currentState;
}

void FSM::Update(Agent* agent, float dtime)
{
    if (currentStateUpdate)
    {
        FSMState* newState = currentStateUpdate(agent, dtime);

        if (newState != nullptr)
        {
            ChangeState(newState, agent);
        }
    }
}