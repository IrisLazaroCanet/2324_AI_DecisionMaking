#pragma once
#include "Vector2D.h"
#include <iostream>

class HeuristicFunction
{
public:
	HeuristicFunction() { };
	~HeuristicFunction() { };

	virtual float CalculateHeuristic(Vector2D point, Vector2D goal, float d_param) = 0;
};