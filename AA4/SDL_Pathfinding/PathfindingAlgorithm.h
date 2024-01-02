#pragma once
#include "Path.h"
#include "Graph.h"

#include <iostream>
#include <queue>

class PathfindingAlgorithm
{
public:
	PathfindingAlgorithm() { }
	~PathfindingAlgorithm() { }

	virtual Path* FindPath(Graph* graph, Node* origin, Node* goal) = 0;

	int GetExploredNodes() { return (int)visited.size(); }

protected:
	std::vector<Node*> frontier;

	std::map<std::string, bool> visited;
};