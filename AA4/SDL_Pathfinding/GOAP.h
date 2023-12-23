#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "Agent.h"
#include "GOAPAction.h"

class GOAP : public Agent::DecisionMakingAlgorithm
{
private:
	std::vector<std::string> atomNames;
	std::unordered_map<std::string, GOAPAction> actions;
	GOAPWorldState start;	//??
	GOAPWorldState goal;	//??
	std::vector<GOAPAction*> plan;
	int idxCurrAction = 0;

	void AStar(GOAPWorldState start, GOAPWorldState goal);

public:
	void Update(Agent* agent, float dtime) override;

};