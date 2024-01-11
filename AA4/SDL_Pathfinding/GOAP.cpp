#include "GOAP.h"

Path* GOAP::AStar(GOAPWorldState start, GOAPWorldState goal)
{
    // Create a priority queue for A*
    std::priority_queue<std::pair<float, GOAPWorldState>, std::vector<std::pair<float, GOAPWorldState>>, CustomComparator> pq;

    // Create a map to keep track of costs and parents for backtracking
    std::unordered_map<GOAPWorldState, float, GOAPWorldStateHasher> costSoFar;
    std::unordered_map<GOAPWorldState, GOAPWorldState, GOAPWorldStateHasher> parentMap;

    // Initialize cost to the start as 0
    costSoFar[start] = 0.0f;

    // Push the start state with the estimated total cost (g + h) to the priority queue
    pq.push(std::make_pair(costSoFar[start] + HeuristicFunction(start, goal), start));

    while (!pq.empty())
    {
        GOAPWorldState current = pq.top().second;
        pq.pop();

        // Check if the goal state is reached
        if (current == goal)
        {
            // Construct the path until now and return it
            Path* path = new Path;
            GOAPWorldState currentState = current;

            // Backtrack from the goal to the start using parentMap
            while (currentState != start)
            {
                // Extract information from currentState to create a Vector2D
                Vector2D currentPosition; // replace this with the actual conversion/extraction
                path->points.insert(path->points.begin(), currentPosition);
                currentState = parentMap[currentState];
            }

            return path;
        }

        // Get the applicable actions for the current state
        std::vector<GOAPAction*> applicableActions = GetApplicableActions(current);

        for (GOAPAction* action : applicableActions)
        {
            GOAPWorldState next = ApplyAction(current, action);

            float newCost = costSoFar[current] + ActionCost(action);

            // If the next state has not been visited or a shorter path is found
            if (costSoFar.find(next) == costSoFar.end() || newCost < costSoFar[next])
            {
                costSoFar[next] = newCost;
                parentMap[next] = current;

                pq.push(std::make_pair(newCost + HeuristicFunction(next, goal), next));
            }
        }
    }

    // If no path is found, return nullptr
    return nullptr;
}

GOAP::GOAP()
{
}

GOAP::~GOAP()
{
}

void GOAP::Update(Agent* agent, Agent* target, float dtime)
{
	//...
	if (plan.empty())
	{
		AStar(start, goal);
	}
	else
	{
		//Deploy an existing plan
		plan[idxCurrAction]->Update(agent, dtime);
		//...
		//Check currAction effects and currAction precond!
		//	- time for next action?
		//	- reset plan?
		//...
	}
}

// Add these functions to your GOAP class to match the A* algorithm's needs

float GOAP::HeuristicFunction(const GOAPWorldState& current, const GOAPWorldState& goal)
{
	// Implement your heuristic function here
	// It should estimate the cost from the current state to the goal state
	// You might need to calculate the difference between the two states
	// and assign a cost based on the differences.
	// Return the estimated cost.
}

std::vector<GOAPAction*> GOAP::GetApplicableActions(const GOAPWorldState& state)
{
	// Implement this function to return a list of applicable actions for the given state
}

GOAPWorldState GOAP::ApplyAction(const GOAPWorldState& state, GOAPAction* action)
{
	// Implement this function to apply the given action to the current state
}

float GOAP::ActionCost(GOAPAction* action)
{
	// Implement this function to return the cost of the given action
	// You might want to define a cost for each action.
    return 1.f;
}
