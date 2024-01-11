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

	float distanceToWanderPosition = Vector2D::Distance(agent->getPosition(), (randomX,randomY));

	if (distanceToWanderPosition < 300 || timer >4)
	{
		canGenerateNextPatrolPosition = true;
		timer = 0;
	}

	agent->applySteeringBehavior(target, dtime, (randomPos), true);


	timeSinceEnter += dtime;


	if (distanceToTarget < agent->distanceThreshold)
	{
		return StateType::CHASE;
	}
		
    return StateType::NONE;

}

void FSMState_Patrol::Exit(Agent* agent, Agent* target)
{
}
