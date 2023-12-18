#include "SceneFSM.h"

using namespace std;

SceneFSM::SceneFSM()
{
	draw_grid = false;
	maze = new Grid("../res/maze.csv");

	loadTextures("../res/maze.png");

	srand((unsigned int)time(NULL));

	player = new Agent;
	player->loadSpriteTexture("../res/soldier.png", 4);
	player->setBehavior(new PathFollowing);
	player->setTarget(Vector2D(-20,-20));

	// set agent position coords to the center of a random cell
	Vector2D rand_cell(-1,-1);
	while (!maze->isValidCell(rand_cell))
		rand_cell = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));
	player->setPosition(maze->cell2pix(rand_cell));

	//FSM TEST
	npc = new AgentPointer(
		new State_WanderMaze(),
		new State_ChaseEnemy(),
		new State_FleeEnemy()
	);

	npc->loadSpriteTexture("../res/soldier.png", 4);
	npc->setBehavior(new PathFollowing);
	npc->setTarget(Vector2D(-20, -20));
	npc->setPosition(maze->cell2pix(Vector2D(0.f, 0.f)));
}

SceneFSM::~SceneFSM()
{
	if (background_texture)
		SDL_DestroyTexture(background_texture);

	delete player;
	delete npc;
}

void SceneFSM::update(float dtime, SDL_Event* event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_KEYDOWN:
		if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
			draw_grid = !draw_grid;

		if (event->key.keysym.scancode == SDL_SCANCODE_7)
			spotEnemy = !spotEnemy;

		if (event->key.keysym.scancode == SDL_SCANCODE_8)
			looseEnemy = !looseEnemy;

		if (event->key.keysym.scancode == SDL_SCANCODE_9)
			enemyHasGun = !enemyHasGun;

		if (event->key.keysym.scancode == SDL_SCANCODE_0)
			enemyLooseGun = !enemyLooseGun;

		//Test
		if (event->key.keysym.scancode == SDL_SCANCODE_P)
			npc->SetStateToFlee();

		break;
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			Vector2D cell = maze->pix2cell(Vector2D((float)(event->button.x), (float)(event->button.y)));
			if (maze->isValidCell(cell)) {
				player->addPathPoint(maze->cell2pix(cell));
			}
		}
		break;
	default:
		break;
	}

	player->update(dtime, event);
	npc->update(dtime, event);
}

void SceneFSM::draw()
{
	drawMaze();

	if (draw_grid)
	{
		SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 255, 255, 255, 127);
		for (int i = 0; i < SRC_WIDTH; i+=CELL_SIZE)
		{
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), i, 0, i, SRC_HEIGHT);
		}
		for (int j = 0; j < SRC_HEIGHT; j = j += CELL_SIZE)
		{
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), 0, j, SRC_WIDTH, j);
		}
	}

	player->draw();
	npc->draw();
}

const char* SceneFSM::getTitle()
{
	return "SDL Path Finding :: FSM Demo";
}

void SceneFSM::drawMaze()
{
	SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 0, 0, 255, 255);
	SDL_Rect rect;
	Vector2D coords;
	for (int j = 0; j < maze->getNumCellY(); j++)
	{
		for (int i = 0; i < maze->getNumCellX(); i++)
		{		
			if (!maze->isValidCell(Vector2D((float)i, (float)j)))
			{
				SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 0, 0, 255, 255);
				coords = maze->cell2pix(Vector2D((float)i, (float)j)) - Vector2D((float)CELL_SIZE / 2, (float)CELL_SIZE / 2);
				rect = { (int)coords.x, (int)coords.y, CELL_SIZE, CELL_SIZE };
				SDL_RenderFillRect(TheApp::Instance()->getRenderer(), &rect);
			} else {
				// Do not draw if it is not necessary (bg is already black)
			}
					
			
		}
	}
	//Alternative: render a backgroud texture:
	//SDL_RenderCopy(TheApp::Instance()->getRenderer(), background_texture, NULL, NULL );
}


bool SceneFSM::loadTextures(char* filename_bg)
{
	SDL_Surface *image = IMG_Load(filename_bg);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	background_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	if (image)
		SDL_FreeSurface(image);

	return true;
}
