#include "EuclideanDistance.h"

float EuclideanDistance::CalculateHeuristic(Vector2D point, Vector2D goal, float d_param)
{
    float dx = fabsf(point.x - goal.x);
    float dy = fabsf(point.y - goal.y);

    return d_param * sqrtf(powf(dx, 2) + powf(dy, 2));
}
