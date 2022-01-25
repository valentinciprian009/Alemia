#include "Game.h"
#include "Log.h"
#include "MyException.h"
#include "BucketHeadZombie.h"
#include "PoleVaultingZombie.h"
#include "SuperZombie.h"

int Game::getNrLanes()
{
	if (this->currentUser.getLevel() == 1)
		return 1;
	else
		if (this->currentUser.getLevel() == 2)
			return 3;
		else
			return 5;
}

Game::Game() :
	resourceValue(10),
	resourceFreq(200),
	state(true),
	plants(new PlantChooser),
	sunZone(new SunZone),
	battleZone(new BattleZone(Game::getNrLanes())),
	iteration(0)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut.clearScreen();
	std::cout << *plants << *battleZone << *sunZone;
}



Game::~Game()
{
	delete plants;
	delete sunZone;
	delete battleZone;
}

void Game::printScoreBoard() 
{
	instance->currentUser.printDataToScreen();
}

Game* Game::instance = nullptr;

Game* Game::getInstance()
{
	if (instance == nullptr)
	{
		try
		{
			instance = new Game();
			Log::getInstance()->LogEvent("New game started");
		}
		catch (MyException & e)
		{
			std::string log = "Exception thrown!! Description :";
			log += e.what();
			Log::getInstance()->LogEvent(log.c_str());
			throw e;
			
		}
		catch (std::exception & e)
		{
			std::string log = "Exception thrown!! Description :";
			log += e.what();
			Log::getInstance()->LogEvent(log.c_str());
			throw e;
		}
	}
	else
		return instance;
}

void Game::destroyInstance()
{
	if (instance != nullptr)
	{
		Log::getInstance()->LogEvent("Game exited");
		delete instance;
		instance = nullptr;
	}
}

void Game::setResourceVal(int val)
{
	instance->resourceValue = val;
}

void Game::addToScore(int toAdd)
{
	instance->currentUser.setScore(toAdd);
}

void Game::addResourceFreq(int freq)
{
	instance->resourceFreq += freq;
}

BattleZone* Game::getBattleZone()
{
	return instance->battleZone;
}

void Game::setIteration(const int iter)
{
	instance->iteration = iter;
}

int Game::getIteration()
{
	return instance->iteration;
}

void Game::run()
{
	if (instance->currentUser.getLevel() == 1)
	{
		if (instance->level1() == false)
		{
			Log::getInstance()->LogEvent("Level 1 failed");
			instance->finishLevelLoss();
			return;
		}
		
		if (instance->state == true)
		{
			instance->finishLevelWin();
			Log::getInstance()->LogEvent("Level 1 passed");
		}
	}

	if (instance->currentUser.getLevel() == 2)
	{
		if (instance->level2() == false)
		{
			Log::getInstance()->LogEvent("Level 2 failed");
			instance->finishLevelLoss();
			return;
		}
		if (instance->state == true)
		{
			Log::getInstance()->LogEvent("Level 2 passed");
			instance->finishLevelWin();
		}
	}

	if (instance->currentUser.getLevel() == 3)
	{
		if (instance->level3() == false)
		{
			Log::getInstance()->LogEvent("Level 3 failed");
			instance->finishLevelLoss();
			return;
		}
		if (instance->state == true)
		{
			Log::getInstance()->LogEvent("Level 3 passed. Game won");
			instance->finishLevelWin();
		}
	}
}

void Game::manageClicks() 
{
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	int x, y;

	conIn.getCoordinates(x, y, conIn.getUserActions());

	if (instance->sunZone->isInside(x, y))
	{
		instance->currentUser.setResources(instance->resourceValue);
	}
	if (instance->plants->isInside(x, y))
	{
		instance->buyPlant(x, y);
	}
	if ((x >= 35) && (x <= 45))
	{
		if ((y >= 5) && (y <= 15))
		{
			instance->state = false;
		}
	}
}

void Game::updateScreen()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut.clearScreen();
	std::cout << *instance->plants << *instance->battleZone << *instance->sunZone;
}

void Game::buyPlant(int x, int y)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	std::string output;
	iPlant* newPlant = instance->plants->getClickedPlant(x, y)->clone();

	if (newPlant == nullptr)
	{
		conOut(39, 80) << "Nu puteti cumpara planta pentru ca se afla in cooldown\n";
		return;
	}

	if (instance->currentUser.getResources() < newPlant->getPrice())
	{
		conOut(39, 80) << "Trist. Nu aveti destule resurse";
		Sleep(1000);
		conOut(39, 80) << "                               ";
	}
	else
	{
		try
		{
			do
			{
				output = conIn.getUserActions();
			} while (output == "");

			if (output != "")
			{
				conIn.getCoordinates(x, y, output);
				if (instance->battleZone->getRectangle(x, y) == nullptr)
					throw MyException("Data viitoare va rog sa apasati in INTERIORUL unui patratel din zona de lupta\n");
				newPlant->setX(instance->battleZone->getRectangle(x, y)->getX() + 1);
				newPlant->setY(instance->battleZone->getRectangle(x, y)->getY() + 4);
				instance->battleZone->getRectangle(x, y)->addEntity(newPlant);
			}
			instance->currentUser.setResources(-newPlant->getPrice());
			Log::getInstance()->LogEvent("Resources are now" + instance->currentUser.getResources());
		}
		catch (MyException & e)
		{
			std::string log = "Exception thrown!! Description :";
			log += e.what();
			Log::getInstance()->LogEvent(log.c_str());
			conOut(39, 80) << e.what();
			Sleep(1000);
			conOut(39, 80) << "                                                                                        ";
		}
		catch (std::exception & e)
		{
			std::string log = "Exception thrown!! Description :";
			log += e.what();
			Log::getInstance()->LogEvent(log.c_str());
			conOut(39, 80) << e.what();
			Sleep(1000);
			conOut(39, 80) << "                                                 ";
		}
	}
}

bool Game::level1()
{
	int nrZombies = 0;
	int zombieFreq = 700;

	for (; instance->state == true; instance->iteration++)
	{
		instance->operations();
	
		if (instance->checkLoss() == true)
		{
			instance->state = false;
			return false;
		}
		if (nrZombies == 3)
		{
			if(instance->getBattleZone()->getNrZombies() == 0)
			{
				break;
			}
		}
		
		if ((nrZombies < 4) && ((instance->iteration + 1) % zombieFreq == 0))
		{
			if (nrZombies == 1)
			{
				zombieFreq -= 300;
			}
			instance->generateZombie(0);
			nrZombies++;
		}
	}
	return true;
}

bool Game::level2()
{
	int nrZombies = 0;
	int zombieFreq = 700;
	srand(time(0));

	if (instance->state == false)
		return false;

	for (; instance->state == true; instance->iteration++)
	{
		instance->operations();

		if (instance->checkLoss() == true)
		{
			instance->state = false;
			return false;
		}
		if (nrZombies >= 10)
		{
			if (instance->getBattleZone()->getNrZombies() == 0)
			{
				break;
			}
		}

		if (nrZombies < 10)
		{
			if (nrZombies == 1)
			{
				zombieFreq -= 300;
			}
			if ((instance->iteration + 1) % (150 + zombieFreq) == 0)
			{
				auto current = instance->battleZone->getLastRectangle(rand() % 3);
				current->addEntity(new BucketHeadZombie(current->getX() + 1, current->getY() + 4, 300, 7));
			}
			if ((instance->iteration + 1)% (100 + zombieFreq) == 0)
			{
				auto current = instance->battleZone->getLastRectangle(rand() % 3);
				current->addEntity(new PoleVaultingZombie(current->getX() + 1, current->getY() + 4, 100, 7, 0));
			}
			if((instance->iteration + 1) % zombieFreq == 0)
			{
				zombieFreq -= 25;
				int poz = rand() % 3;
				instance->generateZombie(poz);
				poz = rand() % 3;
				instance->generateZombie(poz);
				poz = rand() % 3;
				instance->generateZombie(poz);
				nrZombies += 3;
			}
		}
	}
	return true;
}

bool Game::level3()
{
	int nrZombies = 0;
	int zombieFreq = 700;
	srand(time(0));

	if (instance->state == false)
		return false;

	for (; instance->state == true; instance->iteration++)
	{
		instance->operations();

		if (instance->checkLoss() == true)
		{
			instance->state = false;
			return false;
		}
		if (nrZombies >= 20)
		{
			if (instance->getBattleZone()->getNrZombies() == 0)
			{
				break;
			}
		}

		if ((nrZombies <= 20))
		{
			if ((nrZombies == 3) && (instance->iteration) % zombieFreq == 0)
			{
				zombieFreq -= 500;
				auto current = instance->battleZone->getLastRectangle(rand() % 3);
				current->addEntity(new SuperZombie(current->getX() + 1, current->getY() + 4, 300, 7, 0));
			}
			if ((instance->iteration + 1) % (200 + zombieFreq) == 0)
			{
				auto current = instance->battleZone->getLastRectangle(rand() % 3);
				current->addEntity(new BucketHeadZombie(current->getX() + 1, current->getY() + 4, 300, 7));
			}
			if ((instance->iteration + 1) % (100 + zombieFreq) == 0)
			{
				auto current = instance->battleZone->getLastRectangle(rand() % 3);
				current->addEntity(new PoleVaultingZombie(current->getX() + 1, current->getY() + 4, 100, 7, 0));
			}
			if ((instance->iteration) % zombieFreq == 0)
			{
				int poz = rand() % 5;
				instance->generateZombie(poz);
				poz = rand() % 5;
				instance->generateZombie(poz);
				poz = rand() % 5;
				instance->generateZombie(poz);
				nrZombies += 3;
			}
		}
	}
	return true;
}

void Game::generateZombie(int lane)
{
	auto current = instance->battleZone->getLastRectangle(lane);
	current->addEntity(new Zombie(current->getX() + 1, current->getY() + 4, 100, 7));
}

bool Game::checkLoss()
{
	for (int i = 0; i < instance->getNrLanes(); i++)
	{
		if (instance->battleZone->checkLane(i) == false)
			return true;
	}
	return false;
}

void Game::operations()
{
	instance->printExit();
	instance->printScoreBoard();
	instance->battleZone->eraseDead();
	instance->battleZone->printInterior();
	instance->currentUser.printDataToFile();
	std::cout << *instance->sunZone;
	instance->manageClicks();

	instance->battleZone->triggerActions();

	if (instance->iteration % instance->resourceFreq == 0)
		instance->sunZone->generateSun(instance->resourceValue);
}

void Game::finishLevelLoss()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.clearScreen();
	conOut.setColor(13);
	conOut(10, 10) << "GAME OVER";
	instance->state = false;
}

void Game::recreateBattleZone()
{
	delete instance->battleZone;

	instance->battleZone = new BattleZone(instance->getNrLanes());
}

void Game::printExit()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.setColor(13);
	conOut(40, 10) << "Exit";
}


void Game::finishLevelWin()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	conOut.clearScreen();
	conOut.setColor(13);
	conOut(30, 50) << "NIVEL " << instance->currentUser.getLevel() << " TRECUT";
	Sleep(1000);
	conOut(30, 50) << "                             ";
	instance->battleZone->clearLvl();
	instance->resourceValue = 10;
	instance->resourceFreq -= 10;
	instance->currentUser.setLevel(instance->currentUser.getLevel() + 1);
	instance->recreateBattleZone();
	std::cout << *instance->battleZone;
	std::cout << *instance->plants;
	std::cout << *instance->sunZone;
}

