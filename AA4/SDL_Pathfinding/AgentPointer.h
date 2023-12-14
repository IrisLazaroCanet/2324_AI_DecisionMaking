#pragma once
#include "PointerStateTemplate.h"
#include "Agent.h"
#include "PointerFSM.h"

class AgentPointer : public Agent, public PointerFSM
{
protected:
	PointerStateTemplate* wanderMazeState;
	PointerStateTemplate* chaseEnemyState;
	PointerStateTemplate* fleeEnemyState;
};