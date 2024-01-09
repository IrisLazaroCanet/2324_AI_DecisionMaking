#include "FSMState_Patrol.h"

void FSMState_Patrol::Enter(Agent* agent, Agent* target)
{
	timeSinceEnter = 0;
	//agent->setBehavior(new WanderBehavior());
	agent->setBehavior(new SeekBehavior());
}

StateType FSMState_Patrol::Update(Agent* agent, Agent* target, float dtime)
{
	float distanceToTarget = Vector2D::Distance(agent->getPosition(), target->getPosition());
	//Agent deploy state actions / movement

	// set agent position coords to the center of a random cell
	
	//agent->getBehavior()->CalculateForces(agent, target, dtime);
	// 


	//OLD
	
	//patrolPosX = 100;
	//patrolPosY = 100;
	//randomPos = (patrolPosX, patrolPosY);

	if (canGenerateNextPatrolPosition)
	{
		int minX = 0;
		int maxX = 2000;
		int minY = 0;
		int maxY = 2000;

		randomX = rand() % (maxX - minX + 1) + minX;
		randomY = rand() % (maxY - minY + 1) + minY;

		randomPos = Vector2D(randomX, randomY);

		std::cout<< "X:" << (randomX) << std::endl;
		std::cout<< "Y:" << (randomY) << std::endl;

		canGenerateNextPatrolPosition = false;

	}

	timer += dtime;
	//if (timer >= 2)
	//{
	//	timer = 0;
	//	canGenerateNextPatrolPosition = true;
	//}

	float distanceToWanderPosition = Vector2D::Distance(agent->getPosition(), (randomX,randomY));

	if (distanceToWanderPosition < 300 || timer >4)
	{
		canGenerateNextPatrolPosition = true;
		timer = 0;
	}

	agent->applySteeringBehavior(target, dtime, (randomPos), true);



	//std::cout << "Pos X: " << randomPos.x;
	//std::cout << "Pos Y: " << randomPos.y;

		//agent->addPathPoint(graph->CellToPix(Vector2D(patrolPosX, patrolPosY)));
		//int offset = CELL_SIZE / 2;
		//agent->addPathPoint(
		//	Vector2D(patrolPosX * CELL_SIZE + offset, patrolPosY * CELL_SIZE + offset)
		//);
		//agent->setTarget(Vector2D(patrolPosX, patrolPosY));
	

	//std::cout << "x: " << agents[1]->getVelocity().x << "\n";
	//std::cout << "y: " << agents[1]->getVelocity().y << "\n";

	//std::cout << "Path : " << agents[1]->getPathPoint(agents[1]->getCurrentTargetIndex()).x << "\n";

	//if (agent->getVelocity() == (0, 0) && canGenerateNextPatrolPosition == false)
	//{
	//	canGenerateNextPatrolPosition = true;
	//}
	
	
	//TODO: Remove this test
	timeSinceEnter += dtime;
	//std::cout << "Patrol";
	//

	//Transitions between states are checked here!
	//..

	//TEST
	//Change to chase
	
	//if (timeSinceEnter >= 1.f)
	//	return StateType::CHASE;
	//else

	if (distanceToTarget < agent->distanceThreshold)
	{
		return StateType::CHASE;
	}

	/*else if (distanceToTarget < agent->distanceThreshold && target->agentHasGunEquipped)
	{
		return StateType::EVADE;
	}*/
		
    return StateType::NONE;

	/*
	* if(should_change_state) return new_state;
	* else
	return nullptr;
	*/
}

void FSMState_Patrol::Exit(Agent* agent, Agent* target)
{
}
