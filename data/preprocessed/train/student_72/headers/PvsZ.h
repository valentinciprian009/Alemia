#pragma once

#include "Meniu.h";
#include <time.h>
#include <chrono>
#include "mouse_input.h"
#include "key_input.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include "sun.h";
#include "Pea.h"

#include "Plant_choosing_area.h"
#include "Sun_Spawn_Area.h"
#include "arena.h"

class PvsZ
{
private: 
	UserInterface::ConsoleOutput&	conOut= UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput&	conIn= UserInterface::ConsoleInput::getInstance();
	Player Curent_Player;
	std::vector<Player> Players;

	bool check_click_box(mouse_input inp,int x1,int x2 , int y1, int y2);
	void save_curent_player();
	void save_file();
	void load_save_file();
	void clear();
	void lvl(int nr);

public:
	Meniu meniu;

	//////// PRINT THE LOADING STAGE////////
	void print_Loading();
	void doLoadingBar();
	///////////////////////////////////////
	void run();
	void read_player();
	PvsZ();
	~PvsZ();
};

