#pragma once
#include "Player.h"
#include "Terrain.h"

class Scoreboard
{

	int					zombiesCount;
	int					zombiesRemaining;
	int					zombiesKilled = 0;

	Scoreboard();
	~Scoreboard();
	static Scoreboard* instance;
public:
	static Scoreboard& getInstance();
	static void destroyInstance();

	int getRemainingZombies();
	void zombieKilled();
	bool win();
	void update();

	friend void Terrain::spawnZombie();
};

