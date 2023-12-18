#pragma once
#include "PointerStateTemplate.h"
#include "Agent.h"
#include "PointerFSM.h"

class AgentPointer : public Agent, public PointerFSM
{
public:
	AgentPointer(PointerStateTemplate* _wanderMazeState, PointerStateTemplate* _chaseEnemyState, PointerStateTemplate* _fleeEnemyState);
	~AgentPointer();

	void update(float dtime, SDL_Event* event) override;
	void SetStateToWander();
	void SetStateToChase();
	void SetStateToFlee();

protected:
	PointerStateTemplate* wanderMazeState;
	PointerStateTemplate* chaseEnemyState;
	PointerStateTemplate* fleeEnemyState;
};