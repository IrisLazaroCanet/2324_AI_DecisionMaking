#pragma once
#include "HeuristicFunction.h"

class ChebyshevDistance : public HeuristicFunction
{
public:
	ChebyshevDistance() { }
	~ChebyshevDistance() { }

	//Cost de moviment horitzontal / vertical = 1
	//Cost de moviment diagonal = 1
	float CalculateHeuristic(Vector2D point, Vector2D goal, float d_param) override;
};