#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <unordered_map>
#include <algorithm>  // For std::reverse
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

	void AStar(GOAPWorldState start, GOAPWorldState goal);

public:
	GOAP();
	~GOAP();
	void Update(Agent* agent, Agent* target, float dtime) override;

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
	GOAPWorldState ApplyAction(const GOAPWorldState& currentState, const GOAPAction* action) 
	{
		GOAPWorldState successorState = currentState;
		// Apply the preconditions and effects of the action to the successor state
		for (size_t i = 0; i < action->preconditions.values.size(); ++i) {
			if (action->preconditions.mask[i]) {
				successorState.values[i] = action->preconditions.values[i];
			}
		}
		for (size_t i = 0; i < action->effects.values.size(); ++i) {
			if (action->effects.mask[i]) {
				successorState.values[i] = action->effects.values[i];
			}
		}
		return successorState;
	}

	// Calculate heuristic based on the distance between two world states
	float CalculateHeuristic(const GOAPWorldState& state, const GOAPWorldState& goal) {
		// PLACEHOLDER
		float heuristic = 1.0f;
		for (size_t i = 0; i < state.values.size(); ++i) {
			// Add the squared difference between each value as a simple heuristic
			heuristic += static_cast<float>((state.values[i] - goal.values[i]) * (state.values[i] - goal.values[i]));
		}
		return heuristic;
	}

};