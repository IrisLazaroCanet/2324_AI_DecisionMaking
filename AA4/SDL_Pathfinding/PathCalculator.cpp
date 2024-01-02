#include "PathCalculator.h"

PathCalculator* PathCalculator::instance = nullptr;

PathCalculator::PathCalculator()
{
    /*
    pathfindingAlgorithms[BFS_KEY] = new BFSAlgorithm();
    pathfindingAlgorithms[DIJKSTRA_KEY] = new DijkstraAlgorithm();
    pathfindingAlgorithms[GREEDY_KEY] = new GreedyAlgorithm();
    */
    pathfindingAlgorithms[ASTAR_KEY] = new AStarAlgorithm();

    currentAlgorithmKey = ASTAR_KEY;
}

PathCalculator* PathCalculator::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new PathCalculator();
    }

    return instance;
}

Path* PathCalculator::FindPath(Graph* graph, Node* origin, Node* goal)
{
    return pathfindingAlgorithms[currentAlgorithmKey]->FindPath(graph, origin, goal);
}

/*
void PathCalculator::SetAlgorithmToBFS()
{
    currentAlgorithmKey = BFS_KEY;
}

void PathCalculator::SetAlgorithmToDijkstra()
{
    currentAlgorithmKey = DIJKSTRA_KEY;
}

void PathCalculator::SetAlgorithmToGreedy()
{
    currentAlgorithmKey = GREEDY_KEY;
}
*/

void PathCalculator::SetAlgorithmToAStar()
{
    currentAlgorithmKey = ASTAR_KEY;
}
