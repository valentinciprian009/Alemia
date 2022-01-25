#pragma once
#include"Zombie.h"
#define MAX_HEALTH_POLEVAULTING 450
#define MOVE_SPEED_POLEVAULTING 150

class PoleVaulting : virtual public Zombie
{
protected:
	bool jump;
public:
	PoleVaulting() : Zombie(), jump(1) { Log::getInstance().write("PoleVaulting Zombie created"); }
	PoleVaulting(int row_ul, int col_ul, int ln, int stop) : Zombie(row_ul, col_ul, ln, MAX_HEALTH_POLEVAULTING, DAMAGE, MOVE_SPEED_POLEVAULTING, stop, 3), jump(1) { Log::getInstance().write("PoleVaulting Zombie created"); }
	virtual void print();
	virtual void vault() {Log::getInstance().write("PoleVaulting Zombie jumped!");jump = 0; }
	virtual bool checkJump() { return jump; }
};