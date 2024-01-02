#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include "Scene.h"
#include "Agent.h"
#include "Seek.h"
#include "PathFollowing.h"
#include "Grid.h"
#include "Graph.h"
#include "FSM.h"
#include "FSMState_Patrol.h"

class SceneFSM :
	public Scene
{
public:
	SceneFSM();
	~SceneFSM();
	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();
private:
	std::vector<Agent*> agents;
	Vector2D coinPosition;

	Graph* graph;
	Grid* maze;
	bool draw_grid;

	void drawMaze();
	void drawCoin();
	SDL_Texture* background_texture;
	SDL_Texture* coin_texture;
	bool loadTextures(char* filename_bg, char* filename_coin);

};

//Exemples ús A* (cal fer include de "PathCalculator.h"
//PathCalculator té posat A* com algorisme de resolució
//A* té posat Manhattan distance (es pot canviar a la línia 6 de AStarAlgorithm.cpp)
//path = PC->FindPath(graph, graph->GetNodeFromId(agentPositionID).second, graph->GetNodeFromId(coinPositionID).second);