#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)
#include "iProjectile.h"
#include "movingEntity.h"

class Projectile
	: public virtual iProjectile, public virtual movingEntity
{
protected:
	int m_Damage;

public:
	virtual void print() const override = 0;
	int getDamage() const override;
	virtual void hit(iBattleEntity& injured);
	Projectile(int x, int y, int step, int m_Damage);
	~Projectile();
};

#pragma warning(pop)