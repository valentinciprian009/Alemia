#pragma once
#include "IDrawable.h"
#include "Zombie.h"
#include "ConsoleOutput.h"
#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;
using namespace chrono;

class SimpleZombie :public Zombie
{
private:
	steady_clock::time_point trackTime;
public:
	SimpleZombie(int life, int x, int y) :Zombie(life, x, y) { trackTime = steady_clock::now(); };
	~SimpleZombie();
	virtual void print();
	virtual void move();
	virtual void spaceIt();
	int getLife() { return this->life; };
	int getx() { return this->x; };
	int gety() { return this->y; };
	virtual bool testTime(int time)
	{
		auto callTime = steady_clock::now();
		if (duration_cast<milliseconds>(callTime - trackTime).count() > time)
		{
			trackTime = callTime;
			return true;
		}
		return false;
	}
};