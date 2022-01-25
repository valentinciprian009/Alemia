#pragma once
#include "Plants.h"
class PlantsCherryBomb:public Plants
{
private:
	int cost;
	int nr_muscaturi;
	int regenerare;

public:
	PlantsCherryBomb() :cost(200), nr_muscaturi(10), regenerare(5) {};
	void showPlat(int row, int col);
	void showPlatB(int row, int col);
	int getCost() override;
	int getNrMuscaturi() override;
	int getRegenerare() override;

};

