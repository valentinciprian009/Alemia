#pragma once
#pragma warning(push)
#pragma warning(disable : 4250)
#include "iPlantShooter.h"
#include "Plant.h"
#include "Projectile.h"

class PlantShooter
	:public virtual iPlantShooter, public virtual Plant
{
protected:
	int m_attackFrequency;
	iProjectile* m_Proiectil;

public:
	int getPrice() const override;
	virtual void print() const override = 0;
	int getAttackFrequency() const override;
	virtual ~PlantShooter();
	virtual void action() override;
	void setX(int x) override;
	void setY(int y) override;
	iPlant* clone() override = 0;
	PlantShooter(int x, int y, int health, int freq, Projectile* proiectil, int pret);
};

#pragma warning(pop)