#pragma once
#include "Zombie.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <chrono>
using namespace std;
class ZombieSimple:public Zombie
{
private:
	int speed;
	int health;
	int rand;
	int coloana;
	bool moveable;
	std::chrono::steady_clock::time_point end;
	std::chrono::steady_clock::time_point begin;
public:
	ZombieSimple() : speed(10), health(100),rand(0),coloana(0), moveable(true) {};
	ZombieSimple(int r, int c) : speed(10), health(100), rand(r), coloana(c), moveable(true) {};
	int getRezistence();
	int getSpeed();
	void stopZombie();
	void drawZombie(int row,int col);
	void modifyHealth(int i);
	void move();
	void killZombie() override;
	int getRow();
	int getCol();
};

