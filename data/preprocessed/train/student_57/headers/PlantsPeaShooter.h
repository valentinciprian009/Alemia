#pragma once
#include "Plants.h"
#include "ProiectilPEA.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <chrono>
#include <list>
#include <algorithm>
using namespace std;
class PlantsPeaShooter:public Plants
{
private:
	int Row;
	int Col;
	int cost;
	int nr_muscaturi;
	int regenerare;
	list<ProiectilPEA> pea;
	std::chrono::steady_clock::time_point end;
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end_generare;
	std::chrono::steady_clock::time_point begin_generare;
public:
	PlantsPeaShooter() :cost(100), nr_muscaturi(10), regenerare(5), Row(0), Col(0) {};
	PlantsPeaShooter(int x, int y) :cost(100), nr_muscaturi(10), regenerare(5), Row(x), Col(y) {};
	ProiectilPEA returnFirstProiectil();
	int returnNrOfProiectils();
	void destroyFirstProiectil();
	void decrementLife();
	void Shoot();
	void GenerateProiectil();
	void showPlat(int row,int col);
	void showPlatB(int row, int col);
	int getCost() override;
	int getNrMuscaturi() override;
	int getRegenerare() override;

};

