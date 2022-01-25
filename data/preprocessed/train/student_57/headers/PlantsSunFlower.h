#pragma once
#include "Plants.h"
class PlantsSunFlower:public Plants
{
private:
	int cost;
	int nr_muscaturi;
	int regenerare;

public:
	PlantsSunFlower() :cost(125), nr_muscaturi(10), regenerare(5) {};
	void showPlat(int row, int col);
	void showPlatB(int row, int col);
	int getCost() override;
	int getNrMuscaturi() override;
	int getRegenerare() override;

};

