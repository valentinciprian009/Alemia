#pragma once
#pragma warning (push)
#pragma warning (disable : 4250)

#include "PlantShooter.h"
#include "FrozenPea.h"
#include "ConsoleOutput.h"

class SnowPea :
	public PlantShooter
{
public:
	SnowPea(int x, int y, Projectile* proiectil, int pret = 200);
	SnowPea(const SnowPea& old);
	iPlant* clone() override;
	~SnowPea();
	void print() const override;
	void action() override;
};

#pragma warning (pop)

