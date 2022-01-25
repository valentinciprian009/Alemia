#pragma once
#include "Player.h"
#include <vector>
#include <algorithm>
class PlayersList
{

private:
	int nr_players;
	vector<Player> v;
	static PlayersList* instance;
	PlayersList():nr_players(0) {};
	~PlayersList() {};
	PlayersList(const PlayersList&) {};
public:
	static PlayersList& getInstance();
	void destroyInstance();
	void checkFile();
	void getListFromFile();
	
};

