#pragma once
#include "Plant.h"
#include <string>

class CherryBomb:
	public Plant
{
public:
	CherryBomb();
	~CherryBomb() {};
	void draw(int x, int y);
	void draw(int y);
	std::string identity();
	void useSkill();
};