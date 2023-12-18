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

#include "AgentPointer.h"
#include "State_WanderMaze.h"
#include "State_ChaseEnemy.h"
#include "State_FleeEnemy.h"

class SceneFSM :
	public Scene
{
public:
	SceneFSM();
	~SceneFSM();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();

private:
	Agent* player;
	AgentPointer* npc;

	//TODO: Remove test bools
	bool spotEnemy = false;			//Toggle key: 7
	bool looseEnemy = false;		//Toggle key: 8
	bool enemyHasGun = false;		//Toggle key: 9
	bool enemyLooseGun = false;		//Toggle key: 0

	Grid *maze;
	bool draw_grid;
		
	void drawMaze();
	SDL_Texture *background_texture;
	bool loadTextures(char* filename_bg);

};
