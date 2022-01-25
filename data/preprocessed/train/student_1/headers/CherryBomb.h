#pragma once
#include"Plant.h"

class CherryBomb : public Plant
{
public:
	CherryBomb() : Plant(1000000, 150, 1000000, 40, 3) { ; }
	CherryBomb(int row_ul, int col_ul) : Plant(row_ul, col_ul, 1000000, 150, 1000000, 40, 3) { Log::getInstance().write("Cherrybomb created"); }
	void ability();
	bool canPlantFlower(bool& canPlant, steady_clock::time_point& lastPlantedTime);
	void makePlantAvailable(bool& canPlant) { canPlant = 1; }
	int printCooldown(bool& canPlant, steady_clock::time_point& lastPlantedTime);
	void plant(bool& canPlant, steady_clock::time_point& lastPlantedTime);
	void print();
	void setLastPlantedTime(steady_clock::time_point& lastPlantedTime, steady_clock::time_point currTime) { lastPlantedTime = currTime; }
};