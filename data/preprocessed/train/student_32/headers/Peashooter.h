#pragma once
#include<iostream>
#include<chrono>
#include "Plants.h"
#include<time.h>
using namespace std;
using namespace std::chrono;

class Peashooter :
	public Plants
{
private:
	int shootingTime;
	steady_clock::time_point lastShooting;

public:
	Peashooter(string nume, int viata, int pret, int time, int rand, int coloana);
	~Peashooter() {};
	int get_health();
	int get_col();
	int get_row();
	int get_price();
	void set_col(int x);
	void set_row(int y);
	string get_name();
	bool delay();
	void take_damage(int dmg);
};

