#pragma once
#include"Plant.h"

class WallNut : public Plant
{
public:
	WallNut() : Plant(3600, 150, 3600, 20, 4) { Log::getInstance().write("WallNut created"); }
	WallNut(int row_ul, int col_ul) : Plant(row_ul, col_ul, 3600, 150, 3600, 40, 4) { Log::getInstance().write("WallNut created"); }
	bool canPlantFlower(bool& canPlant, steady_clock::time_point& lastPlantedTime);
	void makePlantAvailable(bool& canPlant) { canPlant = 1; }
	int printCooldown(bool& canPlant, steady_clock::time_point& lastPlantedTime);
	void plant(bool& canPlant, steady_clock::time_point& lastPlantedTime);
	void print();
	void setLastPlantedTime(steady_clock::time_point& lastPlantedTime, steady_clock::time_point currTime) { lastPlantedTime = currTime; }
};