#pragma once
#pragma warning(push)
#pragma warning(disable : 4250)


#include "Plant.h"
#include "ConsoleOutput.h"

class Wallnut :
	public Plant
{
public:
	void print() const override;
	iPlant* clone() override;
	Wallnut(int x, int y, int pret = 100);
	~Wallnut();
	void action() override {}
};

#pragma warning(pop)