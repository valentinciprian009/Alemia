#pragma once
class Zombie
{

public:
	virtual int getRezistence()=0;
	virtual int getSpeed() = 0;
	virtual void drawZombie(int row,int col) = 0;
	virtual void move() = 0;
	virtual void killZombie() = 0;
};

