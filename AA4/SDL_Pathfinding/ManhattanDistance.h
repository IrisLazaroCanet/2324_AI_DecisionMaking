#pragma once
#include "HeuristicFunction.h"

class ManhattanDistance : public HeuristicFunction
{
public:
	ManhattanDistance() { };
	~ManhattanDistance() { };

	//Útil per a mapes basats en quadrícula en què no es permet el moviment diagonal
	float CalculateHeuristic(Vector2D point, Vector2D goal, float d_param) override;
};