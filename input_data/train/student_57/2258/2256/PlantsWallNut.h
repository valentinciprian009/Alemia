#pragma once
#include "Plants.h"
class PlantsWallNut:public Plants
{
private:
	int cost;
	int nr_muscaturi;
	int regenerare;

public:
	PlantsWallNut() :cost(75), nr_muscaturi(15), regenerare(5) {};
	void showPlat(int row, int col);
	void showPlatB(int row, int col);
	int getCost() override;
	int getNrMuscaturi() override;
	int getRegenerare() override;

};

