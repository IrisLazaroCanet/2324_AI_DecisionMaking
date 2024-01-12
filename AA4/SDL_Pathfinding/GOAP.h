#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <unordered_map>
#include <algorithm>  // For std::reverse
#include "Agent.h"
#include "GOAPAction.h"

#include "GOAPAction_GetCoin.h"
#include "GOAPAction_GetRedKey.h"
#include "GOAPAction_GetBlueKey.h"


class GOAP : public Agent::DecisionMakingAlgorithm
{
private:
	std::vector<std::string> atomNames;
	std::unordered_map<std::string, GOAPAction*> actions;
	GOAPWorldState start;
	GOAPWorldState goal;
	std::vector<GOAPAction*> plan;
	int idxCurrAction = 0;

	void AStar(GOAPWorldState start, GOAPWorldState goal);

public:
	GOAP();
	~GOAP();
	void Update(Agent* agent, Agent* target, float dtime) override;
	void SetStartState(GOAPWorldState _start) { start = _start; }
	void SetGoalState(GOAPWorldState _goal) { goal = _goal; }

	//Stuff for A*
	struct GOAPNode {
		GOAPWorldState state;
		GOAPAction* action;
		float cost;
		float heuristic;

		bool operator>(const GOAPNode& other) const {
			return (cost + heuristic) > (other.cost + other.heuristic);
		}
	};


	// Apply an action to generate a successor state
	GOAPWorldState ApplyAction(const GOAPWorldState& currentState, const GOAPAction* action);

	// Calculate heuristic based on the distance between two world states
	float CalculateHeuristic(const GOAPWorldState& state, const GOAPWorldState& goal);

	// This struct provides a hash function for std::map<FactKey, int>.
	// It allows efficient hashing of the map-based representation of GOAPWorldState for use in unordered containers,
	//Used for the std::unordered_map, which is utilized in the A* algorithm to keep track of visited nodes.
	struct FactKeyHash {
		size_t operator()(const std::map<FactKey, int>& facts) const {
			size_t hash = 0;
			// Iterate over each key-value pair in the map
			for (const auto& pair : facts) 
			{
				// Combine the hash values of the key and value using a bitwise XOR operation
				hash ^= std::hash<FactKey>()(pair.first) + std::hash<int>()(pair.second) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
			}
			// Return the final combined hash value
			return hash;
		}
	};
};