#include "FSM.h"

FSM::FSM(FSMState* _currentState)
    : currentState(_currentState)
{
    availableStates[StateType::PATROL] = new FSMState_Patrol();
    availableStates[StateType::CHASE] = new FSMState_Chase();
    availableStates[StateType::EVADE] = new FSMState_Evade();

    //currentState = availableStates[StateType::PATROL];
    //currentState->Enter();
}


void FSM::ChangeState(StateType newStateType, Agent* agent, float dtime)
{
    currentState->Exit(agent, dtime);
    //currentState = newState;
    currentState = availableStates[newStateType];
    currentState->Enter(agent, dtime);

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