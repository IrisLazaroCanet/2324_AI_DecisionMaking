#include "OctileDistance.h"

float OctileDistance::CalculateHeuristic(Vector2D point, Vector2D goal, float d_param)
{
    std::cout << "Calculate octile distance" << std::endl;

    //TODO: preguntar si és correcta l'assignació dels paràmetres d
    //TODO: preguntar si enlloc de 1.0f, emprar d_param
    float K_OCTILE_D = 1.0f;
    float K_OCTILE_D2 = sqrtf(2.0f);

    float dx = fabsf(point.x - goal.x);
    float dy = fabsf(point.x - goal.y);

    return K_OCTILE_D * (dx + dy) +
        (K_OCTILE_D2 - 2 * K_OCTILE_D) *
        fminf(dx, dy);
}
