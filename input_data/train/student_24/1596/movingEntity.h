#pragma once
#pragma warning(push)
#pragma warning( disable : 4250)
#include "iMovingEntity.h"
#include "Entity.h"

class movingEntity
	:virtual public Entity, virtual public iMovingEntity
{
protected:
	int m_Step;

public:
	virtual void print() const = 0;
	movingEntity(int x, int y, int step);
	virtual ~movingEntity();
	void move() override;
	int getStep() const override;
};
#pragma warning( pop )
