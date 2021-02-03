#pragma once
#include"Plant.h"
#include"FrozenPea.h"
#define GARDEN_LENGTH 111
#define SPEED_DECREASE 25

class SnowPea : public Plant
{
private:
	FrozenPea frozenPea;
public:
	SnowPea() : Plant(200, 175, 200, 35, 5), frozenPea(rowUpperLeft, colUpperLeft + 2, GARDEN_LENGTH, SPEED_DECREASE) { Log::getInstance().write("SnowPea created"); }
	SnowPea(int row_ul, int col_ul) : Plant(row_ul, col_ul, 200, 175, 200, 35, 5), frozenPea(rowUpperLeft, colUpperLeft + 2, GARDEN_LENGTH, SPEED_DECREASE) { Log::getInstance().write("SnowPea created"); }
	void ability();
	bool canPlantFlower(bool& canPlant, steady_clock::time_point& lastPlantedTime);
	void makePlantAvailable(bool& canPlant) { canPlant = 1; }
	int printCooldown(bool& canPlant, steady_clock::time_point& lastPlantedTime);
	void plant(bool& canPlant, steady_clock::time_point& lastPlantedTime);
	void print();
	void setLastPlantedTime(steady_clock::time_point& lastPlantedTime, steady_clock::time_point currTime) { lastPlantedTime = currTime; }
	bool hitZombie(Zombie* zombie);
	bool getHitZombie(Zombie* zombie);
};