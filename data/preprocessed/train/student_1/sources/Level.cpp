#include"Level.h"

void Level::createZombies()
{
	srand(time(nullptr));
	int type;
	for (int i = 0; i < number_of_zombies - 1; i++)
	{
		type = rand() % 3 + 1;
		switch (type)
		{
		case 1:
			Zombie * z1;
			z1 = new Zombie((garden.getGround())[(i % (user.getMaxLevel() + 1))][8].getRowUpperLeft() + 2, garden.getGround()[(i % (user.getMaxLevel() + 1))][8].getColUpperLeft() + 14, (i % (user.getMaxLevel() + 1)), 42);
			zombieList.push_back(z1);
			break;

		case 2:
			Zombie * z2;
			z2 = new BucketHead((garden.getGround())[(i % (user.getMaxLevel() + 1))][8].getRowUpperLeft() + 2, garden.getGround()[(i % (user.getMaxLevel() + 1))][8].getColUpperLeft() + 14, (i % (user.getMaxLevel() + 1)), 42);
			zombieList.push_back(z2);
			break;

		case 3:
			Zombie * z3;
			z3 = new PoleVaulting((garden.getGround())[(i % (user.getMaxLevel() + 1))][8].getRowUpperLeft() + 2, garden.getGround()[(i % (user.getMaxLevel() + 1))][8].getColUpperLeft() + 14, (i % (user.getMaxLevel() + 1)), 42);
			zombieList.push_back(z3);
			break;

		default:
			break;
		}
	}
	int lane = rand() % (user.getMaxLevel() + 1);
	Zombie* z4;
	z4 = new SuperZombie((garden.getGround())[lane][8].getRowUpperLeft() + 2, garden.getGround()[lane][8].getColUpperLeft() + 14, lane, 42);
	zombieList.push_back(z4);
}

void Level::deployZombies(int wave)
{
	if (checkIfWaveReady(wave))
	{
		if (wave < (number_of_zombies / (user.getMaxLevel() + 1)))
		{
			for (int i = 0; i < (user.getMaxLevel() + 1); i++)
			{
				zombieList[(user.getMaxLevel() + 1) * wave + i]->move();
			}
		}
		else
		{
			zombieList[(number_of_zombies / (user.getMaxLevel() + 1))]->move();
		}
	}
}

bool Level::checkIfWaveReady(int wave)
{
	if ((wave < (number_of_zombies / (user.getMaxLevel() + 1))) && wave > 0)
	{
		for (int i = 0; i < (user.getMaxLevel() + 1); i++)
			if (zombieList[(user.getMaxLevel() + 1) * (wave - 1) + i])
				return false;
	}
	else if (wave == 0)
	{
		return true;
	}
	else if (wave == (number_of_zombies / (user.getMaxLevel() + 1)))
	{
		if (zombieList[(number_of_zombies / (user.getMaxLevel() + 1))])
			return false;
	}
	else
		return false;
	return true;
}

int Level::game_status()
{
	bool still_runs = 0;
	for (int i = 0; i < number_of_zombies; i++)
	{
		if (zombieList[i])
		{
			still_runs = 1;
			if (zombieList[i]->getColUpperLeft() == 42)
			{
				return 2;
			}
		}
	}
	return still_runs;
}

void Level::start()
{
	createZombies();
}

int Level::run()
{
	if (game_status() == 1)
	{
		int type, row, col;
		garden.print();
		auto plantList = garden.getPlantList();
		if (garden.plantFlower(type, row, col))
			consoleOut(4, 2) << "Plant placed in cell (" << row << ", " << col << ")";
		deployZombies(currentWave);
		for (auto& plant : plantList)
		{
			for (int j = 0; j < (user.getMaxLevel() + 1); j++)
			{
				if (plant->getRowGround() == j)
				{
					zombieList[(user.getMaxLevel() + 1) * currentWave + j]->move();
					if (zombieList[(user.getMaxLevel() + 1) * currentWave + j])
					{
						if (plant->getType() == 1)
						{
							//consoleOut(5, 1) << zombieList[(user.getMaxLevel() + 1) * currentWave + j]->getHealth() << "       ";
							//consoleOut(6, 1) << (*plantIt)->getCurrentHP() << "       ";
							if (((Peashooter*)plant)->hitZombie(zombieList[(user.getMaxLevel() + 1) * currentWave + j]))
							{
								int oldScore = garden.getScore();
								garden.updateScore(oldScore + 100);
								delete zombieList[(user.getMaxLevel() + 1) * currentWave + j];
								zombieList[(user.getMaxLevel() + 1) * currentWave + j] = nullptr;
							}
						}
						else if (plant->getType() == 5)
						{
							//consoleOut(5, 1) << zombieList[(user.getMaxLevel() + 1) * currentWave + j]->getHealth() << "       ";
							//consoleOut(6, 1) << (*plantIt)->getCurrentHP() << "       ";
							if (((SnowPea*)plant)->hitZombie(zombieList[(user.getMaxLevel() + 1) * currentWave + j]))
							{
								delete zombieList[(user.getMaxLevel() + 1) * currentWave + j];
								zombieList[(user.getMaxLevel() + 1) * currentWave + j] = nullptr;
							}
						}
						//consoleOut(5, 1) << zombieList[(user.getMaxLevel() + 1) * currentWave + j]->getHealth() << "       ";
						if (plant->getHitZombie(zombieList[(user.getMaxLevel() + 1) * currentWave + j]))
						{
							zombieList[(user.getMaxLevel() + 1) * currentWave + j]->setStop(42);
							row = plant->getRowGround();
							col = plant->getColumnGround();
							garden.getGround()[row][col].changeType(0);
							delete plant;
							plant = nullptr;
							garden.updatePlantList(plantList);
						}
					}
				}
			}
		}
		if (checkIfWaveReady(currentWave + 1))
			currentWave++;
	}
	else if (game_status() == 0)
	{
		if (user.getMaxLevel() <= 2)
			user.nextLevel(garden.getScore());
		else
		{
			user.setScore(garden.getScore());
			return 3;	// 3 -> endgame
		}
	}
	return game_status();	// if 0 -> next level, if 1 -> still runs this level, if 2 -> game over
}