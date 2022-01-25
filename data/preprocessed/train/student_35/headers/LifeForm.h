#include"Entity.h"
#include"ConsoleOutput.h"
#pragma once
class LifeForm:public Entity
{
protected:
	int viata;
	int damage;
	int range;
public:
	LifeForm();
	~LifeForm();
	virtual int getlife() { return viata; }
	virtual void setlife(int dmg) {
		viata -= dmg;
	}
	//virtual int getx() { return cx; }
	//virtual int gety() { return cy; }

};

