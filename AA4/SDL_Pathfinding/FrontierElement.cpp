#include "FrontierElement.h"

FrontierElement::FrontierElement(std::pair<std::string, Node*> _node, std::pair<std::string, Node*> _cameFrom, float _costSoFar, float _heuristic)
{
	node = _node;
	cameFrom = _cameFrom;
	costSoFar = _costSoFar;
	heuristic = _heuristic;
	priority = CalculatePriority();
}

FrontierElement::~FrontierElement()
{
	delete node.second;
	delete cameFrom.second;
}

float FrontierElement::CalculatePriority()
{
	float priority = costSoFar + heuristic;
	return priority;
}
