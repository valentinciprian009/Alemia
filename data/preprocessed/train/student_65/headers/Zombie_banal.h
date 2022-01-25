#pragma once
#include "Zombie.h"
#include "Time.h"
#include "ConsoleOutput.h"
class Zombie_banal :
	public Zombie
{
private:
	Time t;
public:
	Zombie_banal(int x, int y) :Zombie(x,y,3,6,"Zombie_banal"){
	}
	void draw();
	void update(std::string);
	~Zombie_banal();
};

