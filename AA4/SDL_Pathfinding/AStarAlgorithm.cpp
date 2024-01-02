#include "AStarAlgorithm.h"

Path* AStarAlgorithm::FindPath(Graph* graph, Node* origin, Node* goal)
{
    std::cout << "Calculate path using A star algorithm" << std::endl;
    HC->SetFunctionToManhattan();

    // Create a priority queue for A*
    std::priority_queue<std::pair<float, Node*>, std::vector<std::pair<float, Node*>>, std::greater<std::pair<float, Node*>>> pq;

    // Create a map to keep track of costs and parents for backtracking
    std::map<Node*, float> costSoFar;
    std::map<Node*, Node*> parentMap;

    // Initialize cost to the origin as 0
    costSoFar[origin] = 0.0f;

    // Push the origin node with the estimated total cost (g + h) to the priority queue
    //pq.push(std::make_pair(costSoFar[origin] + origin->GetHeuristic(), origin));
    pq.push(std::make_pair(costSoFar[origin] + HC->CalculateHeuristic(origin->GetCell(), goal->GetCell()), origin));

    while (!pq.empty())
    {
        Node* current = pq.top().second;
        pq.pop();

        visited[current->GetId()] = true;

        // Check if an enemy is close to the current node
        if (current->enemyClose)
        {
            // Construct the path until now and return it
            Path* path = new Path;
            Node* currentNode = current;

            // Backtrack from the current node to the origin using parentMap
            while (currentNode != nullptr)
            {
                path->points.insert(path->points.begin(), currentNode->GetCell());
                currentNode = parentMap[currentNode];
            }

            std::cout << "Explored nodes: " << visited.size() << std::endl;

            return path;
        }


        // If the goal node is reached, construct the path and return it
        if (current->GetCell() == goal->GetCell())
        {
            Path* path = new Path;
            Node* currentNode = current;

            // Backtrack from the goal to the origin using parentMap
            while (currentNode != nullptr)
            {
                path->points.insert(path->points.begin(), currentNode->GetCell());
                currentNode = parentMap[currentNode];
            }

            std::cout << "Explored nodes: " << visited.size() << std::endl;

            return path;
        }

        // Get the connections of the current node from the graph
        std::vector<Connection*> connections = graph->GetConnections(current->GetId());

        for (Connection* connection : connections)
        {
            Node* neighbor = graph->GetNodeFromId(connection->GetToNode()).second;

            float newCost = costSoFar[current] + connection->GetCost();

            // If the neighbor node has not been visited or a shorter path is found
            if (costSoFar.find(neighbor) == costSoFar.end() || newCost < costSoFar[neighbor])
            {
                costSoFar[neighbor] = newCost;
                parentMap[neighbor] = current;

                if (neighbor != nullptr)
                    //pq.push(std::make_pair(newCost + neighbor->GetHeuristic(), neighbor));
                    pq.push(std::make_pair(newCost + HC->CalculateHeuristic(neighbor->GetCell(), goal->GetCell()), neighbor));
            }
        }
    }

    // If no path is found, return nullptr
    return nullptr;
}
