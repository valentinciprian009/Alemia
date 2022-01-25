#pragma once
#include "GameObject.h"

class TerrainBlock :
	public GameObject
{
public:
	void draw(int x, int y, int flag);
	void draw(int x, int y) {};
	std::string identity();
	void useSkill() {};
	GameObject* clone() { return this; };

	void damage(int x = 0, bool slowed = false) {};
};

