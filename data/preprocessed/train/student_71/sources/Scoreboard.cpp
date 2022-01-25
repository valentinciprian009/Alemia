#include "Scoreboard.h"
#include "ConsoleOutput.h"
#define SCORE_ROW			3
#define SCORE_COL			10
#define NAME_ROW			1
#define NAME_COL			7
#define LEVEL_ROW			2
#define LEVEL_COL			10

Scoreboard* Scoreboard::instance = NULL;

Scoreboard::Scoreboard()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	Player& player = Player::getInstance();
	conOut(0, 0) << L"███████████████████";
	conOut(1, 0) << L"██";	conOut(1, 17) << L"██";
	conOut(2, 0) << L"██";  conOut(2, 3) << "Level: ";	 conOut(2, 17) << L"██";
	conOut(3, 0) << L"██";  conOut(3, 5) << "Sun: ";	 conOut(3, 17) << L"██";
	conOut(4, 0) << L"███████████████████";

	conOut(NAME_ROW, NAME_COL) << player.getName();
	conOut(LEVEL_ROW, LEVEL_COL) << player.getCurrentLevel();
	conOut(SCORE_ROW, SCORE_COL) << player.getAvailableSun();

	switch (player.getCurrentLevel())
	{
	case 1:
		this->zombiesCount = 20;
		this->zombiesRemaining = 20;
		break;
	case 2:
		this->zombiesCount = 30;
		this->zombiesRemaining = 30;
		break;
	case 3:
		this->zombiesCount = 10;
		this->zombiesRemaining =10;
		break;
	}
}

Scoreboard::~Scoreboard()
{
	Player& player = Player::getInstance();
	player.decreaseScore(player.getAvailableSun());
}

Scoreboard& Scoreboard::getInstance()
{
	if (!instance)
		instance = new Scoreboard;
	return *instance;
}

void Scoreboard::destroyInstance()
{
	delete instance;
}

int Scoreboard::getRemainingZombies()
{
	return zombiesRemaining;
}

void Scoreboard::zombieKilled()
{
	zombiesKilled++;
}

bool Scoreboard::win()
{
	if (zombiesKilled<zombiesCount)
		return false;
	return true;
}

void Scoreboard::update()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	Player& player = Player::getInstance();

	conOut(NAME_ROW, NAME_COL) << player.getName();
	conOut(LEVEL_ROW, LEVEL_COL) << player.getCurrentLevel();
	conOut(SCORE_ROW, SCORE_COL) << "    ";
	conOut(SCORE_ROW, SCORE_COL) << player.getAvailableSun();

	conOut(39, 76, 15) << (int)((float)zombiesKilled / zombiesCount * 100) << "% Complete";
}