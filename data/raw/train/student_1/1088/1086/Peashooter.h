#pragma once
#include"Pea.h"
#include"Plant.h"
#define GARDEN_LENGTH 111

class Peashooter : public Plant
{
private:
	Pea pea;
public:
	Peashooter() : Plant(200, 100, 200, 15, 1), pea(rowUpperLeft, colUpperLeft + 2, GARDEN_LENGTH) { Log::getInstance().write("Peashooter created"); }
	Peashooter(int row_ul, int col_ul) : Plant(row_ul, col_ul, 200, 100, 200, 15, 1), pea(rowUpperLeft, colUpperLeft + 2, GARDEN_LENGTH) { Log::getInstance().write("Peashooter created"); }
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