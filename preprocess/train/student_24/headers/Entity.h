#pragma once
#include "iEntity.h"
#include <list>

class Entity
	: virtual public iEntity
{
protected:
	int coordX;
	int coordY;
	std::list<int> colors;

public:
	Entity(int x, int y);
	virtual ~Entity();
	virtual void print() const  override = 0;
	int getX() const override;
	int getY() const override;
	virtual void setX(int x) override;
	virtual void setY(int y) override;
	Entity& operator() (int x, int y);
};

