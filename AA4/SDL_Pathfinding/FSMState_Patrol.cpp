#include "FSMState_Patrol.h"

void FSMState_Patrol::Enter(Agent* agent)
{
	timeSinceEnter = 0;
}

StateType FSMState_Patrol::Update(Agent* agent, float dtime)
{
	//Agent deploy state actions / movement

	// set agent position coords to the center of a random cell
	
	if (canGenerateNextPatrolPosition)
	{
		canGenerateNextPatrolPosition = false;

		min = 0;
		max = 39;
		patrolPosX = min + std::rand() % (max - min + 1);

		min = 0;
		max = 23;
		patrolPosY = min + std::rand() % (max - min + 1);

		//agent->addPathPoint(graph->CellToPix(Vector2D(patrolPosX, patrolPosY)));
		int offset = CELL_SIZE / 2;
		agent->addPathPoint(
			Vector2D(patrolPosX * CELL_SIZE + offset, patrolPosY * CELL_SIZE + offset)
		);
		//agent->setTarget(Vector2D(patrolPosX, patrolPosY));
	}

	//std::cout << "x: " << agents[1]->getVelocity().x << "\n";
	//std::cout << "y: " << agents[1]->getVelocity().y << "\n";

	//std::cout << "Path : " << agents[1]->getPathPoint(agents[1]->getCurrentTargetIndex()).x << "\n";

	if (agent->getVelocity() == (0, 0) && canGenerateNextPatrolPosition == false)
	{
		canGenerateNextPatrolPosition = true;
	}
	
	
	
	//TODO: Remove this test
	timeSinceEnter += dtime;
	std::cout << "Patrol";
	//

	//Transitions between states are checked here!
	//..

	//TEST
	//Change to chase
	
	if (timeSinceEnter >= 0.5f)
		return StateType::CHASE;
	else
		
		return StateType::NONE;

	/*
	* if(should_change_state) return new_state;
	* else
	return nullptr;
	*/
}

void FSMState_Patrol::Exit(Agent* agent)
{
}
