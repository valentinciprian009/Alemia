#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)

#include "PlantShooter.h"
#include "Pea.h"
#include "ConsoleOutput.h"

class Peashooter :
	public PlantShooter
{
public:
	Peashooter(int x, int y, Projectile* proiectil, int pret = 100);
	Peashooter(const Peashooter& old);
	iPlant* clone() override;
	~Peashooter();
	void print() const override;
	void action() override;
};

#pragma warning(pop)