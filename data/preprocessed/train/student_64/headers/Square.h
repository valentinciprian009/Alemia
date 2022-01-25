#pragma once
#include <Windows.h>
#include "Position.h"
#include"Entities.h"
#include "PlantTypes.h"

#define	DEFAULT_SIDE_SIZE	6

class Square
{
protected:
	Position leftCorner;
	const int sideSize;
	Entities currentEntity;
public:
	Square();
	~Square();
	void setLeftCorner(Position Lc) { leftCorner = Lc; }
	void setLeftCorner(int x, int y) { leftCorner.set_x(x), leftCorner.set_y(y); }
	Position getLeftCorner() { return leftCorner;}
	Square(Position Lc) : Square() { leftCorner = Lc; }


	PlantTypes plant_type;
	void DoASquare();

	void ChangeInteriorValue();
	void PrintInteriorValue(int value);

	Square operator=(Square other) {
		leftCorner = other.leftCorner;
		return *this;
	}

	void setEntity(Entities entity)
	{
		currentEntity = entity;
	}

	Entities getEntity()
	{
		return currentEntity;
	}
};

