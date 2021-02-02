#pragma once
#include <string>
#include "CherryBomb.h"
#include "Snow_Pea.h"
#include "Peashooter.h"
#include "WallNut.h"
#include "Sunflower.h"
#include "Menu.h"
#include "Terrain.h"
#include "Sun.h"
#include "Zombie.h"
#include <thread>
#include <vector>
#include <map>
class Pick_and_plant
{
	
	Peashooter p;
	Sunflower s;
	CherryBomb c;
	Snow_Pea sp;
	WallNut w;
	std::vector<int> pozitii_ocupate;
	int line1(std::string ac, Menu a);
	int line2(std::string ac, Menu a);
	int line3(std::string ac, Menu a);
	int line4(std::string ac, Menu a);
	int line5(std::string action1, Menu a);
	Zombie *zombies;
	int coins;
    int check_position(int x);
	int nr_peashooters;
	int aux;

	Pea bullets[30];
	std::vector <int> first_pos;
public:
	void colision();
	Pick_and_plant();
	int spawn();
	void shoot_peashooter();
	int get_nr_peashooters() { return nr_peashooters; };
	void peashooter(std::string action,Menu a,Terrain b);
	void sunflower(std::string action,Menu a,Terrain b);
	void cherrybomb(std::string action,Menu a,Terrain b);
	void snow_pea(std::string action,Menu a,Terrain b);
	void wallnut(std::string action,Menu a,Terrain b);  
	int get_coins() { return coins; };
	int sun_line(std::string action1, Menu a);
	void sun_coins(std::string action, Menu a);
	int k;
	~Pick_and_plant();
};

