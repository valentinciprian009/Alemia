#include "NewUserParser.h"
#include "Game.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
void NewUserParser::addUserProcess()
{
	auto &CO = ConsoleOutput::getInstance();
	auto CI = ConsoleInput::getInstance();

	std::string uName;
	std::string passW;

	CO.clearScreen();
	CO.setCursorVisibility(true);
	CI.setGameInput(false);
	std::cout << "Introdu noul username:";
	std::getline(std::cin, uName);
	std::cout << "Introdu parola:";
	std::getline(std::cin, passW);

	if (addUserToFile(uName, passW))
	{
		std::cout << "Utilizator adaugat cu succes" << std::endl;
	}
	else
	{
		std::cout << "Numarul maxim de utilizatori a fost atins" << std::endl;
	}
	std::cout << "Apasati enter pentru a continua";
	while (std::cin.get() != '\n');
	CI.setGameInput(true);
}
bool NewUserParser::addUserToFile(std::string uName, std::string passW)
{
	return Game::getGameInstance().addUser(uName, passW);
}
void NewUserParser::parseAction(std::string action)
{
	Game& game = Game::getGameInstance();
	if (action == "1")
	{
		addUserProcess();
		game.changeGameState(Game::State::NewUser);
	}
	else if (action == "2")
	{
		game.changeGameState(Game::State::MainMenu);
	}
}
