#pragma once
#include<iostream>
#include<chrono>
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
#include<chrono>
#include<algorithm>
#include<time.h>
using namespace std;
using namespace std::chrono;
class Projectile
{
private:
	int col;
	int row;
	int frequency;
	int damage;
	steady_clock::time_point lastshot;
public:
	Projectile();
	Projectile(int row, int col, int damage, int frequency);
	void tranform_col(int val);
	int get_col();
	int get_row();
	int get_frequency();
	int get_damage();
	void move();
	bool delay();
};

