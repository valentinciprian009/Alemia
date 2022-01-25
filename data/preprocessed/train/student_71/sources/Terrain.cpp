#include "Terrain.h"
#include "TerrainBlock.h"
#include "Player.h"
#include "Sunflower.h"
#include "Peashooter.h"
#include "Wallnut.h"
#include "SnowPea.h"
#include "CherryBomb.h"
#include "NormalZombie.h"
#include "PoleVaultingZombie.h"
#include "BucketHeadZombie.h"
#include "SuperZombie.h"
#include "Scoreboard.h"

Terrain* Terrain::instance = NULL;

Terrain::Terrain()
{
	Player& player = Player::getInstance();

	int x = player.getCurrentLevel();
	entities = new GameObject**[5];
	for (int i = 0; i < 5; i++)
		entities[i] = new GameObject*[9];
	if (x >= 1)
		for (int i = 0; i < 9; i++)
		{
			entities[2][i] = new TerrainBlock;
			entities[2][i]->draw(2, i, matrix[2][i]);
		}
	if (x >= 2)
	{
		for (int i = 0; i < 9; i++)
		{
			entities[1][i] = new TerrainBlock;
			entities[3][i] = new TerrainBlock;
			entities[1][i]->draw(1, i, matrix[1][i]);
			entities[3][i]->draw(3, i, matrix[3][i]);
		}
	}
	if (x >= 3)
	{
		for (int i = 0; i < 9; i++)
		{
			entities[0][i] = new TerrainBlock;
			entities[4][i] = new TerrainBlock;
			entities[0][i]->draw(0, i, matrix[0][i]);
			entities[4][i]->draw(4, i, matrix[4][i]);
		}
	}

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
			map[i][j] = "Empty";
}

Terrain::~Terrain()
{
	Player& player = Player::getInstance();

	int x = player.getCurrentLevel();

	switch (x)
	{
	case 1:
		for (int i = 0; i < 9; i++)
			delete entities[2][i];
		break;
	case 2:
		for (int i = 1; i < 4; i++)
			for (int j = 0; j < 9; j++)
				delete entities[i][j];
		break;
	case 3:
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 9; j++)
				delete entities[i][j];
	}
	for (int i = 0; i < 5; i++)
		delete entities[i];
	delete entities;
}

Terrain& Terrain::getInstance()
{
	if (!instance)
		instance = new Terrain;
	return *instance;
}

void Terrain::destroyInstance()
{
	delete instance;
}

bool Terrain::place(std::string name, int x, int y)
{
	Player& player = Player::getInstance();

	switch (player.getCurrentLevel())
	{
	case 1:
		if (x != 2)
			return false;;
		break;
	case 2:
		if ((x < 1) || (x > 3))
			return false;;
		break;
	case 3:
		if ((x < 0) || (x > 5))
			return false;;
		break;
	}

	if (name == "Sunflower")
		entities[x][y] = new Sunflower;
	if (name == "Peashooter")
		entities[x][y] = new Peashooter;
	if (name == "SnowPea")
		entities[x][y] = new SnowPea;
	if (name == "Wallnut")
		entities[x][y] = new Wallnut;
	if (name == "CherryBomb")
		entities[x][y] = new CherryBomb;

	entities[x][y]->draw(x,y);
	entities[x][y]->useSkill();
	map[x][y] = entities[x][y]->identity();

	return true;
}

void Terrain::spawnZombie()
{
	Player& player = Player::getInstance();

	int random_row, random_zombie;
	srand(time(NULL));
	random_row = rand() % 5;
	switch (player.getCurrentLevel())
	{
	case 1:
		random_row = 2;
		break;
	case 2:
		random_row = rand() % 3 + 1;
		break;
	}


	random_zombie = rand() % 4;
	switch (random_zombie)
	{
	case 0:
		entities[random_row][8] = new NormalZombie;
		break;
	case 1:
		entities[random_row][8] = new BucketHeadZombie;
		break;
	case 2:
		entities[random_row][8] = new PoleVaultingZombie;
		break;
	case 3:
		entities[random_row][8] = new SuperZombie;
		break;
	}


	map[random_row][8] = entities[random_row][8]->identity();
	entities[random_row][8]->draw(random_row, 8);
	entities[random_row][8]->setX(random_row);
	entities[random_row][8]->setY(8);

	Scoreboard& score = Scoreboard::getInstance();
	score.zombiesRemaining--;
}

bool Terrain::isEmpty(int x, int y)
{
	if (map[x][y] == "Empty")
		return true;
	return false;
}

bool Terrain::isZombie(int x, int y)
{
	if (entities[x][y]->identity() == "NormalZombie")
		return true;
	if (entities[x][y]->identity() == "BucketHeadZombie")
		return true;
	if (entities[x][y]->identity() == "PoleVaultingZombie")
		return true;
	if (entities[x][y]->identity() == "SuperZombie")
		return true;
	return false;
}

bool Terrain::isPlant(int x, int y)
{
	if (entities[x][y]->identity() == "Sunflower")
		return true;
	if (entities[x][y]->identity() == "Wallnut")
		return true;
	if (entities[x][y]->identity() == "Peashooter") 
		return true;
	if (entities[x][y]->identity() == "SnowPea")
		return true;
	if (entities[x][y]->identity() == "CherryBomb") 
		return true;
	return false;
}

void Terrain::execute()
{
	for (int i = 4; i >= 0; i--)
		for (int j = 8; j >=0; j--)
			if (map[i][j] != "Empty")
				entities[i][j]->useSkill();
}


void Terrain::destroy(int x, int y)
{
	if (entities[x][y]->identity() != "Empty")
	{
		entities[x][y]->~GameObject();
		entities[x][y] = new TerrainBlock;
		entities[x][y]->draw(x, y, matrix[x][y]);
		map[x][y] = "Empty";
	}
}

void Terrain::damage(int x, int y, int damage, bool slowed)
{
	entities[x][y]->damage(damage, slowed);
}

void Terrain::move(GameObject* to_move, int blocks_to_move)
{
	std::string identity = to_move->identity();
	int new_y = to_move->getY() - blocks_to_move;
	int new_x = to_move->getX();

	if(identity == "NormalZombie")
		entities[new_x][new_y] = new NormalZombie;
	if (identity == "BucketHeadZombie")
		entities[new_x][new_y] = new BucketHeadZombie;
	if (identity == "PoleVaultingZombie")
		entities[new_x][new_y] = new PoleVaultingZombie;
	if (identity == "SuperZombie")
		entities[new_x][new_y] = new SuperZombie;

	entities[new_x][new_y] = entities[to_move->getX()][to_move->getY()]->clone();

	entities[new_x][new_y]->draw(new_x, new_y);
	entities[new_x][new_y]->setY(new_y);

	map[new_x][new_y] = identity;

	this->destroy(to_move->getX(), to_move->getY());
}

void Terrain::redraw(int x, int y)   // For projectiles
{
	if (y > 8)
		return;
	entities[x][y]->draw(x, y,matrix[x][y]);
	entities[x][y]->draw(x, y);
}
