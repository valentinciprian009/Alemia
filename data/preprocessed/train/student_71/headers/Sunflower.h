#pragma once
#include "Plant.h"
#include "Terrain.h"
#include <string>
#include <chrono>

using namespace std::chrono;

class Sunflower :
	public Plant
{
public:
	Sunflower();
	void draw(int x, int y);
	void draw(int y);
	std::string identity();
	void useSkill();

	~Sunflower(){};
};

