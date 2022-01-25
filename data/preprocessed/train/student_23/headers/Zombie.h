#pragma once
#include "IDrawable.h"

class Zombie :public IDrawable
{
protected:
	int life;
public:
	Zombie() {};
	Zombie(int life, int x, int y) { this->x = x; this->y = y; this->life = life; };
	Zombie(const Zombie& old) { this->x = old.x; this->y = old.y; this->life = old.life; };
	~Zombie() {};
	void getDamaged(int damage) { this->life = this->life - damage; };
	virtual void print() = 0;
	virtual void move() = 0;
	virtual void spaceIt() = 0;
	virtual bool testTime(int time) = 0;
	int getLife() { return this->life; };
	int getx() { return this->x; };
	int gety() { return this->y; };
};