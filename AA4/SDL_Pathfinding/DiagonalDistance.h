#pragma once
#include "HeuristicFunction.h"

class DiagonalDistance : public HeuristicFunction
{
public:
	DiagonalDistance() { }
	~DiagonalDistance() { }

	//Útil per quan es pot moure en horitzontal, vertical o diagonal en una graella
	float CalculateHeuristic(Vector2D point, Vector2D goal, float d_param) override;
};