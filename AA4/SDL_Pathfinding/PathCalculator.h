#pragma once
#include "PathfindingAlgorithm.h"
/*
#include "BFSAlgorithm.h"
#include "DijkstraAlgorithm.h"
#include "GreedyAlgorithm.h"
*/
#include "AStarAlgorithm.h"

#include <map>
#include <string>

#define PC PathCalculator::GetInstance()

class PathCalculator
{
private:
	static PathCalculator* instance;
	std::map<std::string, PathfindingAlgorithm*> pathfindingAlgorithms;
	std::string currentAlgorithmKey;

	/*
	const std::string BFS_KEY = "BFS";
	const std::string DIJKSTRA_KEY = "Dijkstra";
	const std::string GREEDY_KEY = "Greedy";
	*/
	const std::string ASTAR_KEY = "A*";

	PathCalculator();

public:
	static PathCalculator* GetInstance();

	Path* FindPath(Graph* graph, Node* origin, Node* goal);

	PathfindingAlgorithm* GetCurrentAlgorithm() { return pathfindingAlgorithms[currentAlgorithmKey]; }

	/*
	void SetAlgorithmToBFS();
	void SetAlgorithmToDijkstra();
	void SetAlgorithmToGreedy();
	*/
	void SetAlgorithmToAStar();
};