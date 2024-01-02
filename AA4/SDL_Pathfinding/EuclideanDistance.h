#pragma once
#include "HeuristicFunction.h"

class EuclideanDistance : public HeuristicFunction
{
public:
	EuclideanDistance() { }
	~EuclideanDistance() { }

	//Dist�ncia "ordin�ria" (en l�nia recta)
	//�til quan l'agent t� llibertat de moviment en totes direccions
	float CalculateHeuristic(Vector2D point, Vector2D goal, float d_param) override;
};