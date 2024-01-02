#include "ChebyshevDistance.h"

float ChebyshevDistance::CalculateHeuristic(Vector2D point, Vector2D goal, float d_param)
{
	float K_CHEBYSHEV_D = 1.0f;
	float K_CHEBYSHEV_D2 = 1.0f;

	float dx = fabsf(point.x - goal.x);
	float dy = fabsf(point.y - goal.y);

	return K_CHEBYSHEV_D * (dx + dy) +
		(K_CHEBYSHEV_D2 - 2 * K_CHEBYSHEV_D) *
		fminf(dx, dy);
}
