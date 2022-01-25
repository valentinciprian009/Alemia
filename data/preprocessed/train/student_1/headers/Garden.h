#pragma once
#include"ScoreTable.h"
#include"SpawnGround.h"
#include"Peashooter.h"
#include"Sunflower.h"
#include"CherryBomb.h"
#include"WallNut.h"
#include"SnowPea.h"

class Garden : public Entity
{
private:
	Ground ground;
	SpawnGround spawnGround;
	ScoreTable scoreTable;
	SunGround sunGround;
	Plant* plantSpawn[5];
	vector<Plant*> plantList;
	steady_clock::time_point lastPlantedTime[5] = { steady_clock::now(), steady_clock::now(), steady_clock::now(), steady_clock::now(), steady_clock::now() };
	bool canPlant[5] = { 1, 1, 1, 1, 1 };

public:
	Garden() : Entity(), ground(), spawnGround(), scoreTable(), sunGround(), plantSpawn(), plantList() { ; }
	Garden(int row_ul, int col_ul, int nr_rows, int nr_cols, float time_int);
	Garden(int row_ul, int col_ul, int nr_rows, int nr_cols, float time_int, int lvl, int scr, int sunQty, const string& usernm);
	void print();
	Ground& getGround() { return ground; }
	SunGround& getSunGround() { return sunGround; }
	vector<Plant*> getPlantList() { return plantList; }
	void updatePlantList(vector<Plant*>& newPlantList) { plantList = newPlantList; }
	void updateScore(int newscore) { scoreTable.setScore(newscore); }
	int getScore() { return scoreTable.getScore(); }
	int getSelectedPlant() { return spawnGround.getSelectedPlant(); }
	void reduceSunTimeInterval(float rate) { sunGround.reduceTimeInterval(rate); }
	bool plantFlower(int& type, int& row, int& col);
	void takeSun();
	virtual ~Garden();
};