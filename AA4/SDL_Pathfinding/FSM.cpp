#include "FSM.h"

FSM::FSM(FSMState* _currentState, Agent* agent, Agent* target)
    : currentState(_currentState)
{
    availableStates[StateType::PATROL] = new FSMState_Patrol();
    availableStates[StateType::CHASE] = new FSMState_Chase();
    availableStates[StateType::EVADE] = new FSMState_Evade();

    //currentState = availableStates[StateType::PATROL];
    currentState->Enter(agent, target);
}


void FSM::ChangeState(StateType newStateType, Agent* agent, Agent* target, float dtime)
{
    currentState->Exit(agent, target);
    //currentState = newState;
    currentState = availableStates[newStateType];
    currentState->Enter(agent, target);

}

FSM::~FSM()
{
	delete currentState;
}

void FSM::Update(Agent* agent, Agent* target, float dtime)
{
    StateType newStateType = currentState->Update(agent, target, dtime);
    if (newStateType != StateType::NONE)
        ChangeState(newStateType, agent, target, dtime);
}