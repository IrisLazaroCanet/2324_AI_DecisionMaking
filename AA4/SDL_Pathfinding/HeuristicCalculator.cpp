#include "HeuristicCalculator.h"

HeuristicCalculator* HeuristicCalculator::instance = nullptr;

HeuristicCalculator::HeuristicCalculator()
{
	d_param = 1.f;	//TODO: Posar valor amb sentit
	heuristicFunctions[EUCLIDEAN_KEY] = new EuclideanDistance();
	heuristicFunctions[MANHATTAN_KEY] = new ManhattanDistance();
	heuristicFunctions[CHEBYSHEV_KEY] = new ChebyshevDistance();
	heuristicFunctions[DIAGONAL_KEY] = new DiagonalDistance();
	heuristicFunctions[OCTILE_KEY] = new OctileDistance();

	currentFunctionKey = EUCLIDEAN_KEY;
}

HeuristicCalculator* HeuristicCalculator::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new HeuristicCalculator();
	}

	return instance;
}

float HeuristicCalculator::CalculateHeuristic(Vector2D point, Vector2D goal)
{
	return heuristicFunctions[currentFunctionKey]->CalculateHeuristic(point, goal, 1.f);
}

void HeuristicCalculator::SetFunctionToEuclidean()
{
	currentFunctionKey = EUCLIDEAN_KEY;
}

void HeuristicCalculator::SetFunctionToManhattan()
{
	currentFunctionKey = MANHATTAN_KEY;
}

void HeuristicCalculator::SetFunctionToChebyshev()
{
	currentFunctionKey = CHEBYSHEV_KEY;
}

void HeuristicCalculator::SetFunctionToDiagonal()
{
	currentFunctionKey = DIAGONAL_KEY;
}

void HeuristicCalculator::SetFunctionToOctile()
{
	currentFunctionKey = OCTILE_KEY;
}