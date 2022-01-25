#pragma once
#include"SuperZombie.h"
#define MOVE_TIME 10	// milliseconds

class Pea : public Entity
{
protected:
	int damage;
	int stopPosition;
	int startPosition;
	steady_clock::time_point begin = steady_clock::now();
	
public:
	Pea() : Entity(), damage(20), stopPosition(), startPosition() { ; }
	Pea(int row_ul, int col_ul) : Entity(row_ul, col_ul), damage(20), stopPosition(), startPosition(col_ul) { Log::getInstance().write("Pea created"); }
	Pea(int row_ul, int col_ul, int stopPos) : Entity(row_ul, col_ul), damage(20), stopPosition(stopPos), startPosition(col_ul) { Log::getInstance().write("Pea created"); }
	Pea(const Pea& p) : Entity(p), damage(p.damage), stopPosition(p.stopPosition), startPosition(p.startPosition) { ; }
	void setStopPosition(int stopPos) { stopPosition = stopPos; }
	int getStopPosition() const { return stopPosition; }
	virtual void print() { consoleOut(rowUpperLeft, colUpperLeft) << "o"; }
	virtual void shoot();
	virtual void hitZombie(Zombie* zombie);
};