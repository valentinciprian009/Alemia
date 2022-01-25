#pragma once
#pragma warning(push)
#pragma warning(disable : 4250)

#include <Windows.h>
#include "Plant.h"
#include "ConsoleOutput.h"
#include "iZombie.h"

class CherryBomb :
	public Plant
{
public:
	CherryBomb(int x, int y, int pret = 50);
	~CherryBomb();
	iPlant* clone() override;
	void print() const override;
	void action() override;
	void printExplosion() const;
};

#pragma warning(pop)