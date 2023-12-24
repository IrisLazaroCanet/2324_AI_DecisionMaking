#pragma once
#include "Agent.h"

class FSMState
{
public:
	//FSM Pointer
    typedef void (*EnterFunction)(Agent* agent);
    typedef FSMState* (*UpdateFunction)(Agent* agent, float dtime);
    typedef void (*ExitFunction)(Agent* agent);

    EnterFunction enter;
    UpdateFunction update;
    ExitFunction exit;

    virtual ~FSMState() {}

    virtual void Enter(Agent* agent, float dtime) = 0;
	virtual FSMState* Update(Agent* agent, float dtime) = 0;
	virtual void Exit(Agent* agent, float dtime) = 0;
};