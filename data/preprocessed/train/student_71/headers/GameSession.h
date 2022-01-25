#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Terrain.h"
#include "Player.h"
#include "ItemSlots.h"
#include "SunSlots.h"
#include "Scoreboard.h"

class GameSession
{
	Player&				player = Player::getInstance();
	Scoreboard&			scoreboard = Scoreboard::getInstance();
	Terrain&			terrain = Terrain::getInstance();
	SunSlots&			sun = SunSlots::getInstance();
	ItemSlots&			items = ItemSlots::getInstance();

	float				zombieSpawnRate = 5.0;
	float				sunSpawnRate = 7.0;

	std::string			selectedItem = "";
	
	static				GameSession* instance;

	GameSession();
	~GameSession();
public:

	static GameSession& getInstance();
	void destroyInstance();

	void execute();
	void terminate(int code);
};

