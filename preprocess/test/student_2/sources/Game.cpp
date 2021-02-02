#include "Game.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "ActionParserFactory.h"
#include <time.h>
#include <chrono>
#include <fstream>
#include "DummyAction.h"
#include "GameActions.h"
#include "computerActionFactory.h"
#include "Sunflower.h"
#include "BlankSpace.h"
#include "PeaShooter.h"
#include "Logging.h"
using namespace std::chrono;

Game* Game::gameInstance = nullptr;

void Game::changeUser(int option)
{
	if ((option > Users.size()) || (option == 0))
	{
		return;
	}
	std::string& newUser = Users[option - 1];

	ConsoleInput &CI = ConsoleInput::getInstance();
	ConsoleOutput& CO = ConsoleOutput::getInstance();
	CO.clearScreen();
	CI.setGameInput(false);

	std::string passWord;

	std::cout << "Intrdoceti parola pentru utilizatorul " << newUser << ": ";
	std::getline(std::cin, passWord);

	bool validCredentials = verifyCredentials(newUser, passWord);
	if (validCredentials)
	{
		std::cout << "Utilizator schimbat cu succes " << std::endl;
		this->user = newUser;
		Logging lg;
		lg.logEvent("Noul utilizator curent este :" + newUser);
	}
	else
	{
		std::cout << "Parola gresita " << std::endl;
		Logging lg;
		lg.logEvent("S-a incercat logarea frauduloasa pentru utilizatorul :" + newUser);
	}

	std::cout << "Apasati enter pentru a continua";
	while (std::cin.get() != '\n');

	if (validCredentials)
	{
		changeGameState(MainMenu);
	}
	else
	{
		changeGameState(SelectUser);
	}
	CI.setGameInput(true);
}

bool Game::verifyCredentials(std::string username, std::string passWord)
{

	std::ifstream usersFile(USERS_FILENAME);
	std::string userBuffer;
	std::string passWBuffer;

	while (std::getline(usersFile, userBuffer) && (std::getline(usersFile, passWBuffer)))
	{
		if ((passWBuffer == ("password:" + passWord)) && (userBuffer == ("username:" + username)))
		{
			return true;
		}
	}
	usersFile.close();
	return false;
}

void Game::loadUsers()
{
	std::ifstream menuFile;
	menuFile.open(this->USERS_FILENAME);
	std::string buffer;
	while (std::getline(menuFile, buffer))
	{
		if (buffer.find("username:") != std::string::npos)
		{
			this->Users.push_back(buffer.substr(strlen("username:"), buffer.length()));
		}
	}
}

void Game::doLoadingBar()
{
	static ConsoleOutput &conOut = ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}
	}
}


void Game::showMainMenu()
{
	std::ifstream menuFile(this->MAIN_MENU_FILENAME);
	std::string buffer;
	auto &CO = ConsoleOutput::getInstance();

	std::getline(menuFile, buffer);
	CO << buffer + this->user;
	CO << "\n";
	while (std::getline(menuFile, buffer))
	{
		CO << buffer;
		CO << "\n";
	}
	menuFile.close();

	Logging lg;
	lg.logEvent("Utilizatorul " + this->user + " este in meniul principal");

}

void Game::showNewUserMenu()
{
	std::ifstream menuFile(this->NEW_USER_MENU);
	std::string buffer;
	auto &CO = ConsoleOutput::getInstance();

	while (std::getline(menuFile, buffer))
	{
		CO << buffer;
		CO << "\n";
	}
	menuFile.close();

	Logging lg;
	lg.logEvent("Utilizatorul " + this->user + " este in de creare utilizatori");

}

void Game::showSelectUserMenu()
{
	std::ifstream menuFile(this->SELECT_USER_MENU_FILE);
	std::string buffer;
	auto &CO = ConsoleOutput::getInstance();

	while (std::getline(menuFile, buffer))
	{
		CO << buffer;
		CO << "\n";
	}

	menuFile.close();

	for (int i = 0; i < this->Users.size(); i++)
	{
		CO << (i + 1);
		CO << ".";
		CO << this->Users[i];
		CO << "\n";
	}
	CO << this->Users.size() + 1;
	CO << ".";
	CO << "Inapoi";

	Logging lg;
	lg.logEvent("Utilizatorul " + this->user + " este in de selectare utilizatori");
}

void Game::showPlayingMap()
{
	std::ifstream mapFile(this->LEVEL3FILENAME);
	std::string buffer;
	auto &CO = ConsoleOutput::getInstance();
	CO(0, 0);
	while (std::getline(mapFile, buffer))
	{
		CO << buffer;
		CO << "\n";
	}

	mapFile.close();
	Map::getInstance().printFlowersSidebar();
	Logging lg;
	lg.logEvent("Utilizatorul " + this->user + " a inceput jocul");
}

void Game::run()
{
	ConsoleOutput &conOut = ConsoleOutput::getInstance();
	std::string action;
	while (true)
	{
		action = ConsoleInput::getInstance().getUserActions();
		//primeste actiunea

		IParser *parser = ActionParserFactory::generateParser(this->gameState);
		parser->parseAction(action);
		delete parser;

		IComputerAction* action = computerActionFactory::generateParser(this->gameState);
		action->doAction();
		delete action;
		Sleep(this->sleepTime);
	}

}

int Game::getSori()
{
	return this->sori;
}

Game::Game()
{
	this->user = "none";
	score = 0;
	sori = 0;
	changeGameState(MainMenu);
	this->loadUsers();

}

int Game::getScore()
{
	return this->score;
}

Game& Game::getGameInstance()
{
	if (Game::gameInstance == nullptr)
	{
		Game::gameInstance = new Game();
	}
	return *Game::gameInstance;
}

void Game::changeGameState(State newState)
{
	this->gameState = newState;
	ConsoleOutput::getInstance().clearScreen();
	switch (newState)
	{
	case MainMenu:
	{
		this->showMainMenu();
		sleepTime = 500;
		break;
	}
	case State::NewUser:
	{
		this->showNewUserMenu();
		sleepTime = 500;
		break;
	}
	case State::SelectUser:
	{
		this->showSelectUserMenu();
		sleepTime = 500;
		break;
	}
	case State::Defeat:
	{

	}
	case State::Playing:
	{
		this->showPlayingMap();
		sleepTime = 0;
	}
	case State::Victory:
	{

	}
	};

}

bool Game::addUser(std::string uName, std::string passW)
{
	if (this->Users.size() == 8)
	{
		return false;
	}
	std::fstream uFile;
	this->Users.push_back(uName);
	uFile.open(this->USERS_FILENAME, std::fstream::app);
	uFile << "username:" << uName << std::endl << "password:" << passW << std::endl;
	uFile.close();
	return true;
}

int Game::getUsersNum()
{
	return Users.size();
}

void Game::addSun()
{
	Map::getInstance().addDrawable(new Sun);
}

void Game::addZombie(int zombieNum)
{
	switch (zombieNum)
	{
	case 0:
	{
		Map::getInstance().addZombie(new WalkerZombie(5, 10, "zombie.txt"));
	}
	case 1:
	{
		Map::getInstance().addZombie(new WalkerZombie(50, 25, "bucketHeadZombie.txt"));
	}
	default:
		break;
	}
}

void Game::answerDoubleClick(int col, int line)
{
	AbstractDrawable* clickedAsset = Map::getInstance().getClickedAsset(col, line);
	if (clickedAsset != nullptr)
	{
		if (clickedAsset->getDrawableType() == "Sun")
		{
			this->sori += 10;
			Map::getInstance().printSori(this->sori);
			Map::getInstance().removeSun(((Sun*)clickedAsset)->getIndex());
		}
		else if ((clickedAsset->getDrawableType() == "blank") && (this->selectedPlant != nullptr))
		{
			BlankSpace* blank = (BlankSpace*)clickedAsset;

			Map::getInstance().plantFlower(blank, this->selectedPlant);
			this->selectedPlant = nullptr;
		}
		else if (clickedAsset->getDrawableType() == "WalkerZombie")
		{
			return;
		}
		else if ((this->selectedPlant == nullptr) && (clickedAsset != nullptr))
		{
			GenericFLower* plant = dynamic_cast<GenericFLower*>(clickedAsset);
			if (!Map::getInstance().hasPlant(plant))
			{
				if (this->sori >= plant->getCost())
				{
					this->removeSori(plant->getCost());
					this->selectedPlant = plant;
				}
			}
		}
	}
}

void Game::addScore(int amount)
{
	this->score += amount;
	Map::getInstance().printScore(this->score);
}

void Game::addSori(int amount)
{
	this->sori += amount;
	Map::getInstance().printSori(this->sori);
}

void Game::removeSori(int amount)
{
	this->sori -= amount;
	Map::getInstance().printSori(sori);
}
