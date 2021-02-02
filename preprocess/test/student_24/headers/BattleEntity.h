#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)
#include "iBattleEntity.h"
#include "Entity.h"

class BattleEntity
	: virtual public iBattleEntity, virtual public Entity
{
protected:
	int m_Health;

public:
	BattleEntity(int x, int y, int health);
	virtual ~BattleEntity();

	int getHealth() const override;
	void setHealth(const int& newHealth) override;
	virtual void action() = 0;
	virtual void print() const override = 0;
};
#pragma warning(pop)

