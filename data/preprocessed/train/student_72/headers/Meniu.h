#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Player.h"
#include <vector>

class Meniu
{
private:
	UserInterface::ConsoleOutput	&conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput		&conIn = UserInterface::ConsoleInput::getInstance();

public:
	void print_Main_Meniu(Player player_cur);
	void exit_q();
	void print_levels(Player player_curent);
	void print_best(std::vector<Player> players);
	void print_win_lose(bool win);

	Meniu();
	~Meniu();
};

