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
#include "GOAP.h"

//White equival a null
enum Color { White = 0, Black, Red, Orange, Yellow, Green, Blue, Purple };

class SceneGOAP :
	public Scene
{
public:
	SceneGOAP();
	~SceneGOAP();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
private:
	std::vector<Agent*> agents;
	Vector2D coinPosition;
	Vector2D keyPositions[8];

	Graph* graph;
	Grid *maze;
	bool draw_grid;

	//GOAP
	GOAPWorldState* currentWorldState;
		
	void drawMaze();
	void drawCoin();
	SDL_Texture *background_texture;
	SDL_Texture *coin_texture;
	SDL_Texture *keys_texture;
	bool loadTextures(char* filename_bg, char* filename_coin, char* filename_keys);

	//GOAP
	void InitGOAPWorldState();

};
