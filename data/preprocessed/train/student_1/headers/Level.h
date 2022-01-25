#pragma once
#include"Menu.h"
#include"Garden.h"
#include"User.h"

class Level : public Menu
{
private:
	User user;
	Garden garden;
	int number_of_zombies;
	vector<Zombie*> zombieList;
	int currentWave = 0;
public:
	Level() : Menu(), user(), garden(), number_of_zombies(), zombieList() { ; }
	Level(const User& us) : Menu(), user(us), garden(6, 30, 2 * us.getMaxLevel() + 1, 9, 4.5, us.getMaxLevel() + 1, us.getScoreBoard().getScore(), 100, us.getUsername()), number_of_zombies(15 * us.getMaxLevel() + 16), zombieList() { user.refreshSuns(); Log::getInstance().write("Level started");
	}
	void createZombies();
	void deployZombies(int wave);
	bool checkIfWaveReady(int wave);
	int game_status();
	int run();
	void start();
	User& getUser() { return user; }
};