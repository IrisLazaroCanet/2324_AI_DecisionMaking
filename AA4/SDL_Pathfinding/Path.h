#pragma once
#include <vector>
#include "Vector2D.h"

#include "GOAPWorldState.h"


struct Path
{
	std::vector<Vector2D> points;
	static const int ARRIVAL_DISTANCE = 35;
};
