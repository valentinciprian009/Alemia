#pragma once
#include"ConsoleOutput.h"
#include "zombie.h"
#include "garden.h"
#include "player.h"
class Zombie_manager
{
private:
	Zombie zombie_vec[15];
	int current_zombie=0;
	Player player;
	UserInterface::ConsoleOutput conOut;

public:
	Zombie_manager() {
		UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
		Player player = Player::getInstance();
	}
	static Zombie_manager& getInstance() { Zombie_manager* zm = new Zombie_manager; return *zm; };
	void generate();
	void check_for_hit_zombies (Garden &gd) ;
	void check_for_eaten_flower(Garden *gd);
	bool check_for_win();
	int update_zombies();


};

