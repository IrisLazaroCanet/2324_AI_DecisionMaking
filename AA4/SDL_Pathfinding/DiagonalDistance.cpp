#include "DiagonalDistance.h"

float DiagonalDistance::CalculateHeuristic(Vector2D point, Vector2D goal, float d_param)
{
    //TODO: revisar assignació de d2_param
    float d2_param = d_param;

    float dx = fabsf(point.x - goal.y);
    float dy = fabsf(point.y - goal.y);

    return d_param * (dx + dy) +
        (d2_param - 2 * d_param) *
        fminf(dx, dy);
}
