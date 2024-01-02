#pragma once
#include "HeuristicFunction.h"

class OctileDistance : public HeuristicFunction
{
public:
	OctileDistance() { }
	~OctileDistance() { }

	//Cost de moviment horitzontal / vertical = 1
	//Cost de moviment diagonal = sqrt(2)
	float CalculateHeuristic(Vector2D point, Vector2D goal, float d_param) override;
};