#pragma once
#include "Node.h"
#include "Connection.h"
#include "Grid.h"

#include <string>
#include <vector>
#include <map>
#include <limits>

class Graph
{
public:
	Graph() { }
	Graph(std::map<std::string, Node*> _nodes, std::map<std::pair<std::string, std::string>, int> _connectionsInfo);
	Graph(Grid* grid);
	~Graph();

	std::vector<Connection*> GetConnections(std::string fromNodeId);
	std::pair<std::string, Node*> GetNodeFromId(std::string id);
	Vector2D CellToPix(Vector2D cell);
	std::pair<std::string, Node*> GetRandomNodeWithID();
	std::string GetRandomNodeID();

	Node* GetNodeCloseToEnemy(const std::string& enemyNodeID);


private:
	std::vector<Connection*> InitializeConnections(std::map<std::pair<std::string, std::string>, int> connectionsInfo);
	std::string GenerateNodeName(int charAmount);
	std::string GenerateValidNodeName(int charAmount);
	int GetRandomIndex(int size);
	int CalculateZoneFromPoint(int x, int y, Grid* grid);
	float GenerateRandomWeight(int zone);

	std::vector<std::string> unavailableNames;

	std::map<std::string, Node*> nodes;
	std::vector<Connection*> connections;

	const float MIN_WEIGHT_UPPER_LEFT = 1.f;
	const float MAX_WEIGHT_UPPER_LEFT = 5.f;

	const float MIN_WEIGHT_UPPER_RIGHT = 4.f;
	const float MAX_WEIGHT_UPPER_RIGHT = 8.f;

	const float MIN_WEIGHT_LOWER_LEFT = 3.f;
	const float MAX_WEIGHT_LOWER_LEFT = 6.f;

	const float MIN_WEIGHT_LOWER_RIGHT = 6.f;
	const float MAX_WEIGHT_LOWER_RIGHT = 10.f;


};