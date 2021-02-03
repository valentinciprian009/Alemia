#pragma once
#include <chrono>
#include <stdlib.h>

using namespace std; 
using namespace std::chrono;

class Player
{
	int money;
	int score;
	int zombie_kills;
	int sun_rate;
	int sun_plants;
	steady_clock::time_point time;
	Player() :money(0), score(0), zombie_kills(0), sun_rate(4000), time(steady_clock::now()), sun_plants(0) {};
	static Player* instance;
public:
	int get_money() { return money; };
	static Player& get_instance();
	void add_sun() { money += 50; };
	int check_player();
	void add_sunplants() { sun_plants++; sun_rate -= sun_rate / 10; };
	void substract_sun(int x) { money -= x; };
	int get_score() { return score; };
	void add_kill(int points);
	~Player();
};

