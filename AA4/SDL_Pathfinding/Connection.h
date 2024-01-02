#pragma once
#include "Node.h"
#include <string>
#include <map>

class Connection
{
private:
	std::string fromNodeId;
	std::string toNodeId;
	int cost;

public:
	Connection(int _cost, std::string _fromNodeId, std::string _toNodeId);
	~Connection();

	int GetCost() { return cost; }
	std::string GetFromNode() { return fromNodeId; }
	std::string GetToNode() { return toNodeId; }
};