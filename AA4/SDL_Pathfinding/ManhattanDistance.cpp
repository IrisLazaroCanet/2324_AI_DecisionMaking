#include "ManhattanDistance.h"

float ManhattanDistance::CalculateHeuristic(Vector2D point, Vector2D goal, float d_param)
{
    float dx = fabsf(point.x - goal.x);
    float dy = fabsf(point.y - goal.y);

    return d_param * (dx + dy);
}
