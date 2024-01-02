#pragma once
#include "Node.h"

#include <map>
#include <string>

class FrontierElement
{
public:
	FrontierElement(std::pair<std::string, Node*> _node, std::pair<std::string, Node*> _cameFrom, float _costSoFar, float _heuristic);
	~FrontierElement();

	std::string GetCameFrom() { return cameFrom.first; }
	float GetCostSoFar() { return costSoFar; }
	float GetHeuristic() { return heuristic; }
	float GetPriority() { return priority; }

private:
	float CalculatePriority();

	std::pair<std::string, Node*> node;
	std::pair<std::string, Node*> cameFrom;
	float costSoFar;
	float heuristic;
	float priority;
};