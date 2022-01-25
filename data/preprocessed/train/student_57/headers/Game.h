#pragma once
#include "Teren.h"
#include "ZombieSimple.h"
#include "ZombieBucketHead.h"
#include "PlantsCherryBomb.h"
#include "PlantsPeaShooter.h"
#include "PlantsSnowPea.h"
#include "PlantsSunFlower.h"
#include "PlantsWallNut.h"
#include "Soare.h"
#include "Player.h"

#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
class Game
{
private:
	Player jucator;
	Soare sun;
	Teren ground;
	bool sori[8];
	PlantsPeaShooter pea;
	PlantsSnowPea snow;
	PlantsCherryBomb cherry;
	PlantsSunFlower flower;
	PlantsWallNut wall;
	std::chrono::steady_clock::time_point end_sun;
	std::chrono::steady_clock::time_point begin_sun;
	std::chrono::steady_clock::time_point end_zombie;
	std::chrono::steady_clock::time_point begin_zombie;
	vector<bool> plant;
	vector<bool> zombie;
	vector<PlantsPeaShooter> shooterPEA;
	int numar_zombie;
	vector<ZombieSimple> zs;
public:
	void getUsername();//primeste un username de la tastatura
	void initial_loading();//interfata grafica de la inceput
	void print_first_menu();//printeaza meniul cu cele 3 butoane, start;best;exit
	int select_option();//folosit atunci cand este apasat un buton
	void showSuns();
	void showZombie(int level);
	void catchSun(int row, int col);
	void showWeapons();
	int checkIfaPlantWasSelected(int x,int y);
	void putPlantOnMap(int k,int level);
	void checkIfZombieWasKicked();
	


	void level1();
	void level2();
	void level3();

	void play();
	



	void execute();
	
};