#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <functional>


#include "Path.h"


#include "Agent.h"
#include "GOAPAction.h"

class GOAP : public Agent::DecisionMakingAlgorithm
{
private:
	std::vector<std::string> atomNames;
	std::unordered_map<std::string, GOAPAction*> actions;
	GOAPWorldState start;	//??
	GOAPWorldState goal;	//??
	std::vector<GOAPAction*> plan;
	int idxCurrAction = 0;

	Path* AStar(GOAPWorldState start, GOAPWorldState goal);

	// Add these functions to your GOAP class
	float HeuristicFunction(const GOAPWorldState& current, const GOAPWorldState& goal);
	std::vector<GOAPAction*> GetApplicableActions(const GOAPWorldState& state);
	GOAPWorldState ApplyAction(const GOAPWorldState& state, GOAPAction* action);
	float ActionCost(GOAPAction* action);

public:
	GOAP();
	~GOAP();
	void Update(Agent* agent, Agent* target, float dtime) override;

	class GOAPWorldStateHasher
	{
	public:
		std::size_t operator()(const GOAPWorldState& state) const
		{
			// Implement a hash function for GOAPWorldState
			// You can use std::hash for each boolean value in state.values
			std::size_t hash = 0;

			for (bool value : state.values)
			{
				hash ^= std::hash<bool>{}(value)+0x9e3779b9 + (hash << 6) + (hash >> 2);
			}

			return hash;
		}
	};

	// Replace the CustomComparator struct with the following code
	struct CustomComparator {
		template <class T1, class T2>
		bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right) const {
			if (left.first < right.first)
				return true;
			if (right.first < left.first)
				return false;
			return left.second < right.second;
		}
	};




};