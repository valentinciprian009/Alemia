#include "GameManager.h"
#include "Slide.h"
#include "PeaShooterPlant.h"
#include "ArenaSlide.h"
#include "PoleZombie.h"
#include "Zombie.h"
#include "SunflowerPlant.h"
#include "StatusSlide.h"
#include "CherryBomb.h"

using namespace Arena;

GameManager::GameManager(ArenaSlide* pr)
{
	parent = pr;
	fout.open("logs.txt");
	log("New game session started for player " + parent->user->name() + " on level " + std::to_string(parent->user->level()) + ".");

	switch (parent->user->level())
	{
	case 1:
		tereny = 3;
		break;
	case 2:
		tereny = 4;
		break;
	default:
		tereny = 5;
		break;
	}

	for (int i = 0; i < TERENX; i++)
		for (int j = 0; j < tereny; j++)
			plants[j][i] = new BasicPlant(this, parent->console(), -1, j, i);

}

Arena::GameManager::~GameManager()
{
	for (int y = 0; y < tereny; y++)
	{
		for (int x = 0; x < TERENX; x++)
			delete plants[y][x];
		for (auto it : peas[y])
			delete it;
		for (auto it : zombies[y])
			delete it;
	}
}

void Arena::GameManager::reset()
{
	scr = 0;

	for (int y = 0; y < tereny; y++)
	{
		for (int x = 0; x < TERENX; x++)
			delete plants[y][x];
		for (auto it : peas[y])
			delete it;
		for (auto it : zombies[y])
			delete it;
		peas[y].clear();
		zombies[y].clear();
	}

	switch (parent->user->level())
	{
	case 1:
		tereny = 3;
		break;
	case 2:
		tereny = 4;
		break;
	default:
		tereny = 5;
		break;
	}

	fout.close();
	fout.open("logs.txt");
	log("New game session started for player " + parent->user->name() + " on level " + std::to_string(parent->user->level()) + ".");


	for (int i = 0; i < TERENX; i++)
		for (int j = 0; j < tereny; j++)
			plants[j][i] = new BasicPlant(this, parent->console(), -1, j, i);
}

void Arena::GameManager::addPlant(int id, int y, int x)
{
	if (id > -1)
	{
		std::string format = "Planted a ";
		format += BasicPlant::plants[id].name;
		format += " at cell (";
		format += '0'+y+1;
		format += ", ";
		format += '0'+x + 1;
		format += ").";
		log(format);
	}
	delete plants[y][x];

	if (id == 0)
		plants[y][x] = new PeaShooter(this, parent->console(), y, x, false);
	else if (id == 1)
		plants[y][x] = new SunflowerPlant(this, parent->console(), y, x);
	else if (id == 2)
		plants[y][x] = new BasicPlant(this, parent->console(), 2, y, x);
	else if (id == 3)
		plants[y][x] = new CherryBomb(this, parent->console(), y, x);
	else if(id==4)
		plants[y][x] = new PeaShooter(this, parent->console(), y, x, true);
	else 
		plants[y][x] = new BasicPlant(this, parent->console(), -1, y, x);
}

void Arena::GameManager::addZombie(int id, int y)
{
	if(id == 3)
		zombies[y].push_back(new PoleZombie(this, parent->console(), y, true));
	if (id == 2)
		zombies[y].push_back(new PoleZombie(this, parent->console(), y, false));
	else
		zombies[y].push_back(new BasicZombie(this, parent->console(), y, id));
	zombies[y].back()->startMoving();
	if (id > -1)
	{
		std::string format = "A new ";
		format += BasicZombie::zombies[id].name;
		format += " appeared at row ";
		format += '0' + y + 1;
		format += ".";
		log(format);
	}
}

bool GameManager::empty(int y, int x)
{
	if (y >= tereny || x >= TERENX)
		return true;
	return plants[y][x]->getID() == -1;
}

void Arena::GameManager::update()
{
	//delete dead things
	for (int y = 0; y < tereny; y++)
	{
		std::vector<Pea*> nvp;
		for (auto it : peas[y])
			if (it->active())
				nvp.push_back(it);
			else
				delete it;
		peas[y] = nvp;

		std::vector<BasicZombie*> nvz;
		for (auto it : zombies[y])
			if (it->active())
				nvz.push_back(it);
			else
				delete it;
		zombies[y] = nvz;

		for (int x = 0; x < TERENX; x++)
			if (!plants[y][x]->active())
				addPlant(-1, y, x);
	}

	//update things
	for (int y = 0; y < tereny; y++)
	{
		for (int x = 0; x < TERENX; x++)
			plants[y][x]->update();

		for (auto it : peas[y])
			it->update();

		for (auto it : zombies[y])
			it->update();
	}
}

void Arena::GameManager::draw(UserInterface::ConsoleOutput conOut)
{
	//draw things
	for (int y = 0; y < tereny; y++)
	{
		for (int x = 0; x < TERENX; x++)
			plants[y][x]->draw();

		for (auto it : peas[y])
			it->draw();

		for (auto it : zombies[y])
			it->draw();
	}
}

void Arena::GameManager::addScore(int inc)
{
	scr += inc;
}

int Arena::GameManager::score()
{
	return scr;
}

int Arena::GameManager::wave()
{
	return wv;
}

void Arena::GameManager::log(std::string s)
{
	fout << ITickable::curentTime() << "  ->  ";
	fout << s << "\n";
}

void Arena::GameManager::addToRate(int i)
{
	parent->rman->addToRate(i);
}

void Arena::GameManager::gameOver()
{
	parent->currentUser()->addScore(scr / 5);
	parent->next = new StatusSlide(StatusSlide::GAME_OVER);
}

bool Arena::GameManager::nozombies()
{
	for (int i = 0; i < tereny; i++)
		if (zombies[i].empty())
			return true;
	return false;
}

int Arena::GameManager::terenY()
{
	return tereny;
}
