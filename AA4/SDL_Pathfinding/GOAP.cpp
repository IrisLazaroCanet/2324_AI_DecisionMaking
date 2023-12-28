#include "GOAP.h"

void GOAP::AStar(GOAPWorldState start, GOAPWorldState goal)
{
	//Adapt A* from nodes to GOAP world states
}

GOAP::GOAP()
{
}

GOAP::~GOAP()
{
}

void GOAP::Update(Agent* agent, float dtime)
{
	//...
	if (plan.empty())
	{
		AStar(start, goal);
	}
	else
	{
		//Deploy an existing plan
		plan[idxCurrAction]->Update(agent, dtime);
		//...
		//Check currAction effects and currAction precond!
		//	- time for next action?
		//	- reset plan?
		//...
	}
}
