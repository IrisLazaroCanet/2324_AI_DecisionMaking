#pragma once
#include "HeuristicFunction.h"

class ManhattanDistance : public HeuristicFunction
{
public:
	ManhattanDistance() { };
	~ManhattanDistance() { };

	//�til per a mapes basats en quadr�cula en qu� no es permet el moviment diagonal
	float CalculateHeuristic(Vector2D point, Vector2D goal, float d_param) override;
};