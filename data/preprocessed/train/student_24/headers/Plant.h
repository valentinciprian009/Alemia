#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)
#include "BattleEntity.h"
#include "iPlant.h"
#include "Projectile.h"

class Plant
	: public virtual BattleEntity, public virtual iPlant
{
protected:
	int m_Price;

public:
	virtual void print() const override = 0;
	Plant(int x, int y, int health, int price);
	virtual ~Plant();
	virtual void action() override = 0; 
	iPlant* clone() override = 0;
	int getPrice() const override;
};
#pragma warning(pop)
