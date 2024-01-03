#include "FSM.h"

FSM::FSM(FSMState* _currentState, Agent* agent)
    : currentState(_currentState)
{
    availableStates[StateType::PATROL] = new FSMState_Patrol();
    availableStates[StateType::CHASE] = new FSMState_Chase();
    availableStates[StateType::EVADE] = new FSMState_Evade();

    //currentState = availableStates[StateType::PATROL];
    currentState->Enter(agent);
}


void FSM::ChangeState(StateType newStateType, Agent* agent, float dtime)
{
    currentState->Exit(agent);
    //currentState = newState;
    currentState = availableStates[newStateType];
    currentState->Enter(agent);

}

FSM::~FSM()
{
	delete currentState;
}

void FSM::Update(Agent* agent, float dtime)
{
    StateType newStateType = currentState->Update(agent, dtime);
    if (newStateType != StateType::NONE)
        ChangeState(newStateType, agent, dtime);
}