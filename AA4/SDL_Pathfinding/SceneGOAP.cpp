#include "SceneGOAP.h"

using namespace std;

enum Color { White=0, Black, Red, Orange, Yellow, Green, Blue, Purple};
char *color_strings[8] = {"White", "Black", "Red", "Orange", "Yellow", "Green", "Blue", "Purple"};

SceneGOAP::SceneGOAP()
{
	draw_grid = false;
	maze = new Grid("../res/maze_rooms.csv");

	loadTextures("../res/maze.png", "../res/coin.png", "../res/keys.png");

	srand((unsigned int)time(NULL));

	Agent *agent = new Agent;
	agent->loadSpriteTexture("../res/soldier.png", 4);
	agent->setBehavior(new PathFollowing);
	agent->setTarget(Vector2D(-20,-20));
	agents.push_back(agent);

	// set agent position coords to the center of a random cell in the Black room
	Vector2D rand_cell(-1,-1);
	while ((!maze->isValidCell(rand_cell)) || (maze->getCellValue(rand_cell) != Color::Black))
		rand_cell = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));
	agents[0]->setPosition(maze->cell2pix(rand_cell));

	// set the coin in a random cell (but not in the Black room)
	coinPosition = Vector2D(-1,-1);
	while ((!maze->isValidCell(coinPosition)) || (maze->getCellValue(coinPosition) == Color::Black))
		coinPosition = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));

	// set keys in in a random cell (but not in the room of its same color)
	for (int i=Color::Red; i<8; i++)
	{
		keyPositions[i] = Vector2D(-1,-1);
		while ((!maze->isValidCell(keyPositions[i])) || (maze->getCellValue(keyPositions[i]) == i))
			keyPositions[i] = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));
	}

}

SceneGOAP::~SceneGOAP()
{
	if (background_texture)
		SDL_DestroyTexture(background_texture);
	if (coin_texture)
		SDL_DestroyTexture(coin_texture);

	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneGOAP::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_KEYDOWN:
		if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
			draw_grid = !draw_grid;
		break;
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			Vector2D cell = maze->pix2cell(Vector2D((float)(event->button.x), (float)(event->button.y)));
			if (maze->isValidCell(cell)) {
				agents[0]->addPathPoint(maze->cell2pix(cell));
			}
		}
		break;
	default:
		break;
	}

	agents[0]->update(dtime, event);

	// check if the agent has reached 
	if (agents[0]->getCurrentTargetIndex() == -1)
	{
		// the agent has arrived to the coin we are done!
		if (maze->pix2cell(agents[0]->getPosition()) == coinPosition)
		{
			cout << "The Agent achieved its GOAL!." << endl;
			// nothing to do here but clear the coin position (set coinPosition to -1,-1)
			coinPosition = Vector2D(-1,-1);
		}
		for (int i=Color::Red; i<8; i++)
		{
			if (maze->pix2cell(agents[0]->getPosition()) == keyPositions[i])
			{
				cout << "Now the Agent has the " << color_strings[i] << " Key." << endl;
				// clear the key texture (set key position to -1,-1)
				keyPositions[i] = Vector2D(-1,-1);
			}
		}
	}
	
}

void SceneGOAP::draw()
{
	drawMaze();
	drawCoin();

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

	agents[0]->draw();
}

const char* SceneGOAP::getTitle()
{
	return "SDL Path Finding :: PathFinding Mouse Demo";
}

void SceneGOAP::drawMaze()
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
				SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 255, 255, 255, 255);
				coords = maze->cell2pix(Vector2D((float)i, (float)j)) - Vector2D((float)CELL_SIZE / 2, (float)CELL_SIZE / 2);
				rect = { (int)coords.x, (int)coords.y, CELL_SIZE, CELL_SIZE };
				SDL_RenderFillRect(TheApp::Instance()->getRenderer(), &rect);
			} else {
				int cell_color = maze->getCellValue(Vector2D((float)i, (float)j));
				if (cell_color == Color::Black)
					continue; // Do not draw if it is not necessary (bg is already black)
				switch (cell_color)
				{
					case Color::Red:
						SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 255, 23, 23, 89);
						break;
					case Color::Orange:
						SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 255, 182, 20, 129);
						break;
					case Color::Yellow:
						SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 255, 255, 20, 129);
						break;
					case Color::Green:
						SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 82, 252, 20, 89);
						break;
					case Color::Blue:
						SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 20, 144, 252, 89);
						break;
					case Color::Purple:
						SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 214, 20, 252, 89);
						break;
				}
				coords = maze->cell2pix(Vector2D((float)i, (float)j)) - Vector2D((float)CELL_SIZE / 2, (float)CELL_SIZE / 2);
				rect = { (int)coords.x, (int)coords.y, CELL_SIZE, CELL_SIZE };
				SDL_SetRenderDrawBlendMode(TheApp::Instance()->getRenderer(), SDL_BLENDMODE_BLEND);
				SDL_RenderFillRect(TheApp::Instance()->getRenderer(), &rect);
				SDL_SetRenderDrawBlendMode(TheApp::Instance()->getRenderer(), SDL_BLENDMODE_NONE);
				
			}
					
			
		}
	}
	//Alternative: render a backgroud texture:
	//SDL_RenderCopy(TheApp::Instance()->getRenderer(), background_texture, NULL, NULL );
}

void SceneGOAP::drawCoin()
{
	int offset = CELL_SIZE / 2;

	if (maze->isValidCell(coinPosition))
	{
		Vector2D coin_coords = maze->cell2pix(coinPosition);
		SDL_Rect dstrect = {(int)coin_coords.x-offset, (int)coin_coords.y - offset, CELL_SIZE, CELL_SIZE};
		SDL_RenderCopy(TheApp::Instance()->getRenderer(), coin_texture, NULL, &dstrect);
	}

	for (int i=Color::Red; i<8; i++)
	{
		if (!maze->isValidCell(keyPositions[i])) continue;
		Vector2D key_coords = maze->cell2pix(keyPositions[i]);
		SDL_Rect dstrect = {(int)key_coords.x-offset, (int)key_coords.y - offset, CELL_SIZE, CELL_SIZE};
		SDL_Rect srcrect = {i * 32, 0, 32, 32};
		SDL_RenderCopy(TheApp::Instance()->getRenderer(), keys_texture, &srcrect, &dstrect);
	}
}


bool SceneGOAP::loadTextures(char* filename_bg, char* filename_coin, char* filename_keys)
{
	SDL_Surface *image = IMG_Load(filename_bg);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	background_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	if (image)
		SDL_FreeSurface(image);

	image = IMG_Load(filename_coin);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	coin_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	if (image)
		SDL_FreeSurface(image);

	image = IMG_Load(filename_keys);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	keys_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);
	
	if (image)
		SDL_FreeSurface(image);


	return true;
}
