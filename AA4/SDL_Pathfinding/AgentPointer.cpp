#include "AgentPointer.h"

AgentPointer::AgentPointer(PointerStateTemplate* _wanderMazeState, PointerStateTemplate* _chaseEnemyState, PointerStateTemplate* _fleeEnemyState)
{
	wanderMazeState = _wanderMazeState;
	chaseEnemyState = _chaseEnemyState;
	fleeEnemyState = _fleeEnemyState;

	currentState = wanderMazeState;
	currentState->Enter();
}

AgentPointer::~AgentPointer()
{
	delete wanderMazeState;
	delete chaseEnemyState;
	delete fleeEnemyState;
}

void AgentPointer::update(float dtime, SDL_Event* event)
{
	currentState->Update();
}

void AgentPointer::SetStateToWander()
{
	ChangeState(wanderMazeState);
}

void AgentPointer::SetStateToChase()
{
	ChangeState(chaseEnemyState);
}

void AgentPointer::SetStateToFlee()
{
	ChangeState(fleeEnemyState);
}
