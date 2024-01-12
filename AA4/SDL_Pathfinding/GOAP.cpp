#include "GOAP.h"

void GOAP::AStar(GOAPWorldState start, GOAPWorldState goal)
{
    std::printf("\nSTARTING A*\n");
    // Priority queue for open set
    std::priority_queue<GOAPNode, std::vector<GOAPNode>, std::greater<GOAPNode>> openSet;

    // Closed set to keep track of visited nodes
    std::unordered_map<std::map<FactKey, int>, GOAPNode, FactKeyHash> closedSet;

    // Initialize the start node
    GOAPNode startNode;
    startNode.state = start;
    startNode.action = nullptr;
    startNode.cost = 0.0f;
    startNode.heuristic = CalculateHeuristic(startNode.state, goal);

    // Add the start node to the open set
    openSet.push(startNode);

    while (!openSet.empty())
    {
        // Get the node with the lowest f value from the open set
        GOAPNode currentNode = openSet.top();
        openSet.pop();

        // Check if the current node is the goal
        if (currentNode.state.facts == goal.facts)
        {
            // Reconstruct the plan
            plan.clear();
            while (currentNode.action != nullptr)
            {
                plan.insert(plan.begin(), currentNode.action);
                currentNode = closedSet[currentNode.state.facts];
            }
            return;  // Plan found
        }

        // Generate successor nodes
        for (auto& kv : actions)
        {
            GOAPAction* action = kv.second;
            if (action->IsAchievable(currentNode.state))
            {
                GOAPNode successor;
                successor.state = ApplyAction(currentNode.state, action);
                successor.action = action;
                successor.cost = currentNode.cost + action->cost;
                successor.heuristic = CalculateHeuristic(successor.state, goal);

                // Check if the successor is not in the closed set or open set with a lower cost
                auto closedSetIt = closedSet.find(successor.state.facts);
                if (closedSetIt == closedSet.end() || successor.cost < closedSetIt->second.cost)
                {
                    // Add the successor to the open set
                    openSet.push(successor);

                    // Update or insert into closed set
                    closedSet[successor.state.facts] = successor;
                }
            }
        }
    }

    // No plan found
    plan.clear();
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

        //Test
        plan.push_back(new GOAPAction_GetCoin());
	}
	else
	{
        std::printf("\NOT A*\n");
		//Deploy an existing plan
		plan[idxCurrAction]->Update(agent, dtime);
		//...
		//Check currAction effects and currAction precond!
		//	- time for next action?
		//	- reset plan?
		//...
	}
}

GOAPWorldState GOAP::ApplyAction(const GOAPWorldState& currentState, const GOAPAction* action)
{
    GOAPWorldState successorState = currentState;

    // Apply the preconditions and effects of the action to the successor state
    for (const auto& precond : action->preconditions.facts)
    {
        successorState.SetFact(precond.first, precond.second);
    }

    for (const auto& effect : action->effects.facts)
    {
        successorState.SetFact(effect.first, effect.second);
    }

    return successorState;
}

float GOAP::CalculateHeuristic(const GOAPWorldState& state, const GOAPWorldState& goal)
{
    float heuristic = 0.0f;

    // Iterate over all facts in the states
    for (const auto& stateFact : state.facts)
    {
        FactKey key = stateFact.first;
        int stateValue = stateFact.second;

        // Check if the fact is present in the goal state and has a different value
        auto goalFactIt = goal.facts.find(key);
        if (goalFactIt != goal.facts.end() && goalFactIt->second != stateValue)
        {
            // Increase the heuristic value
            heuristic += 1.0f;
        }
    }

    return heuristic;
}
