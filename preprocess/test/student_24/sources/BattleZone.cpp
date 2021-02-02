#include "BattleZone.h"
#include "Log.h"

void BattleZone::printUpZone(int color) const
{
	std::vector<ContainerRectangle<iBattleEntity*>*>::const_iterator i;
	auto coltStanga = battleArea.cbegin()->cbegin();
	auto coltDreapta = battleArea.cbegin()->cend() - 1;

	(*coltStanga)->printColtStangaSus(10);
	(*coltDreapta)->printColtDreaptaSus(10);

	for (i = battleArea.cbegin()->cbegin() + 1; i < battleArea.cbegin()->cend() - 1; i++)
	{
		(*i)->printSusInterior(10);
	}
}

void BattleZone::printMiddle(int color) const
{
	std::vector<ContainerRectangle<iBattleEntity*>*>::const_iterator coltStanga;
	std::vector<ContainerRectangle<iBattleEntity*>*>::const_iterator coltDreapta;

	for (int k = 1; k < nrLanes - 1; k++)
	{
		coltStanga = (battleArea.cbegin() + k)->cbegin();
		coltDreapta = (battleArea.cbegin() + k)->cend() - 1;

		(*coltStanga)->printStangaInterior(10);
		(*coltDreapta)->printDreaptaInterior(10);

		for (std::vector<ContainerRectangle<iBattleEntity*>*>::const_iterator j = (battleArea.cbegin() + k)->cbegin() + 1; j < (battleArea.cbegin() + k)->cend() - 1; j++)
		{
			(*j)->printInterior(10);
		}
	}
}

void BattleZone::printDownZone(int color) const
{
	std::vector<ContainerRectangle<iBattleEntity*>*>::const_iterator i;
	auto coltStanga = (battleArea.cend() - 1)->cbegin();
	auto coltDreapta = (battleArea.cend() - 1)->cend() - 1;

	(*coltStanga)->printColtStangaJos(10);
	(*coltDreapta)->printColtDreaptaJos(10);

	for (i = (battleArea.cend() - 1)->cbegin() + 1; i < (battleArea.cend() - 1)->cend() - 1; i++)
	{
		(*i)->printJosInterior(10);
	}
}

void BattleZone::printOneLane(int color) const
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(10);
	auto i = battleArea.begin()->begin();
	(*i)->print();

	for (i++ ; i != battleArea.begin()->end() - 2; i++)
	{
		(*i)->printSusInterior(10);
	}

	(*(i + 1))->print();
	(*i)->printSusInterior(10);
}

bool BattleZone::checkLane(int lane) const
{
	auto first = (*(battleArea.begin() + lane)).begin();

	if (dynamic_cast<iZombie*>((*first)->getInterEntity()) != nullptr)
		return false;
	return true;
}

int BattleZone::getNrLanes() const
{
	return nrLanes;
}


void BattleZone::clearLvl()
{
	for (int i = 0; i < nrLanes; i++)
	{
		for (auto iter : *(battleArea.begin() + i))
		{
			if (iter->getInterEntity() != nullptr)
			{
				iter->erase();
				delete iter->getInterEntity();
				iter->addEntity(nullptr);
			}
		}
	}
}

ContainerRectangle<iBattleEntity*>* BattleZone::getRectangle(int x, int y)
{
	for (int i = 0; i < nrLanes; i++)
	{
		for (auto iter : *(battleArea.begin() + i))
		{
			if (iter->isInside(x, y) == true)
				return iter;
		}
	}
	return nullptr;
}

void BattleZone::printInterior() const
{
	for (int i = 0; i < nrLanes; i++)
	{
		for (auto iter : *(battleArea.begin() + i))
		{
			if (iter->getInterEntity() != nullptr)
			{
				iter->getInterEntity()->print();
			}
		}
	}
}

BattleZone::BattleZone(int lanes) : 
	nrLanes(lanes),
	nrPlants(0),
	nrZombies(0)
{
	const int offsetY = 9;
	const int offsetX = 5;
	int pozY;

	for (int i = 0, pozX = 7; i < lanes; i++, pozX += offsetX)
	{
		pozY = 25;
		std::vector<ContainerRectangle<iBattleEntity*>*> aux;
		for (int i = 0; i < nrCols; i++, pozY += offsetY)
		{
			aux.push_back(new ContainerRectangle<iBattleEntity*>(pozX, pozY));
		}
		battleArea.push_back(aux);
		aux.clear();
	}
}

void BattleZone::print() const
{
	if (nrLanes > 1)
	{
		printUpZone(10);
		printMiddle(10);
		printDownZone(10);
	}
	else
		printOneLane(10);
	printInterior();
}

void BattleZone::triggerActions()
{
	for (int i = 0; i < nrLanes; i++)
	{
		for (auto iter : *(battleArea.begin() + i))
		{
			if (iter->getInterEntity() != nullptr)
			{
				iter->getInterEntity()->action();
			}
		}
	}
}

ContainerRectangle<iBattleEntity*>* BattleZone::getNextRectangle(int x, int y)
{
	for (int i = 0; i < nrLanes; i++)
	{
		for (auto iter = (*(battleArea.begin() + i)).begin(); iter != (*(battleArea.begin() + i)).end() - 1; iter++)
		{
			if ((*iter)->isInside(x, y) == true)
				return *(iter + 1);
		}
	}
	return nullptr;
}

ContainerRectangle<iBattleEntity*>* BattleZone::getPrevRectangle(int x, int y)
{
	for (int i = 0; i < nrLanes; i++)
	{
		for(auto iter = (*(battleArea.begin() + i)).begin(); iter != (*(battleArea.begin() + i)).end(); iter++)
		{
			if ((*iter)->isInside(x, y) == true)
				return *(iter - 1);
		}
	}
	return nullptr;
}

ContainerRectangle<iBattleEntity*>* BattleZone::getUpRectangle(int x, int y)
{
	auto iter = battleArea.begin();

	for (int i = 0; i < nrLanes; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i > 0)
			{
				if ((*((*(iter + i - 1)).begin() + j))->isInside(x, y) == true)
				{
					return (*((*(iter + i)).begin() + j));
				}
			}
		}
	}
	
	return nullptr;
}

ContainerRectangle<iBattleEntity*>* BattleZone::getDownRectangle(int x, int y)
{
	auto iter = battleArea.begin();

	for (int i = 0; i < nrLanes; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if ((*((*(iter + i)).begin() + j))->isInside(x, y) == true)
			{
				if (nrLanes > 1)
				{
					return (*((*(iter + i + 1)).begin() + j));
				}
			}
		}
	}
	return nullptr;
}

ContainerRectangle<iBattleEntity*>* BattleZone::getLastRectangle(int lane)
{
	auto iter = battleArea.begin();
	return (*(iter + lane)).back();

}

void BattleZone::eraseDead() const
{
	for (int i = 0; i < nrLanes; i++)
	{
		for (auto iter : *(battleArea.begin() + i))
		{
			if (iter->getInterEntity() != nullptr)
			{
				if (iter->getInterEntity()->getHealth() <= 0)
				{
					Log::getInstance()->LogEvent("Entity killed ");
					iter->erase();
					delete iter->getInterEntity();
					iter->addEntity(nullptr);
				}
			}
		}
	}

}

int BattleZone::getNrPlants() const
{
	int nrPlants = 0;
	for (int i = 0; i < nrLanes; i++)
	{
		for (auto iter : *(battleArea.begin() + i))
		{
			if (dynamic_cast<iPlant*>(iter->getInterEntity()) != nullptr)
			{
				nrPlants++;
			}
		}
	}
	return nrPlants;

}

int BattleZone::getNrZombies() const
{
	int nrZombies = 0;
	for (int i = 0; i < nrLanes; i++)
	{
		for (auto iter : *(battleArea.begin() + i))
		{
			if (dynamic_cast<iZombie*>(iter->getInterEntity()) != nullptr)
			{
				nrZombies++;
			}
		}
	}
	return nrZombies;
}

void BattleZone::setNrPlants(int plants)
{
	this->nrPlants = plants;
}

void BattleZone::setNrZombies(int zombies)
{
	this->nrZombies = zombies;
}
