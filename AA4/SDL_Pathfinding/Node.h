#pragma once
#include "Vector2D.h"
#include <string>


//A l'hora de construir la inst�ncia de Graph, es recorreran totes les cel�les de Grid
//Si isValidCell() => afegir aquella cel�la com a Node al Graph
//El Node es guarda quina cel�la �s

//Alhora, es defineixen les Connections del Graph

//En el moment d'executar l'algorisme, a l'inici es cridar� un "HeuristicCalculator" (Singleton) que, donada una cel�la, un objectiu,
//i una funci� heur�stica (manhattan, chebyshev...), calcular� h(n).
//A continuaci�, es podr� assignar, mitjan�ant aquest valor, l'heur�stica del node del graf

//Quan s'hagi fet per tots els grafs, es procedir� a executar l'algorisme


class Node
{
private:
    Vector2D cell;
    float heuristic;  // Add a heuristic value

    std::string id;  // Add an ID for the node

public:
    Node() : heuristic(1.0f) { }  // Initialize the heuristic to 0
    Node(Vector2D _cell, std::string _id) : cell(_cell), id(_id), heuristic(1.0f) { }
    ~Node() { }


    bool enemyClose = false;  // Add a variable to track if an enemy is close


    // Set the heuristic value
    void SetHeuristic(float _heuristic) { heuristic = _heuristic; }

    // Get the heuristic value
    float GetHeuristic() { return heuristic; }

    // Add a method to get the ID of the node
    std::string GetId() const { return id; }

    Vector2D GetCell() { return cell; }
};
