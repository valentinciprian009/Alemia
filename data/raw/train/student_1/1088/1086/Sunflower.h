#pragma once
#include"Plant.h"
#include"SunGround.h"
#define RATE 0.93

class Sunflower : public Plant
{
public:
	Sunflower() : Plant(150, 50, 150, 15, 2) { Log::getInstance().write("Sunflower created"); }
	Sunflower(int row_ul, int col_ul) : Plant(row_ul, col_ul, 150, 50, 150, 15, 2) { Log::getInstance().write("Sunflower created"); }
	void ability(SunGround& sunGround);
	bool canPlantFlower(bool& canPlant, steady_clock::time_point& lastPlantedTime);
	void makePlantAvailable(bool& canPlant) { canPlant = 1; }
	int printCooldown(bool& canPlant, steady_clock::time_point& lastPlantedTime);
	void plant(bool& canPlant, steady_clock::time_point& lastPlantedTime);
	void print();
	void setLastPlantedTime(steady_clock::time_point& lastPlantedTime, steady_clock::time_point currTime) { lastPlantedTime = currTime; }
};