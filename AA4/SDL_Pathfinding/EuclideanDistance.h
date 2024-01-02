#pragma once
#include "HeuristicFunction.h"

class EuclideanDistance : public HeuristicFunction
{
public:
	EuclideanDistance() { }
	~EuclideanDistance() { }

	//Distància "ordinària" (en línia recta)
	//Útil quan l'agent té llibertat de moviment en totes direccions
	float CalculateHeuristic(Vector2D point, Vector2D goal, float d_param) override;
};