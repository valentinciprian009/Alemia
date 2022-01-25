#pragma once
#include "GameObject.h"
#include <chrono>

using namespace std::chrono;

class Zombie :
	public GameObject
{
protected:
	int health;
	bool slowed = false;
	int timePeriod = 1500;
public:
	time_point<steady_clock> moveTimer = steady_clock::now();
	time_point<steady_clock> slowedTimer = steady_clock::now();
	time_point<steady_clock> skillTimer;

	virtual void draw(int x, int y) = 0; // for entities on the terrain
	virtual std::string identity() = 0;
	virtual void useSkill() = 0;
	virtual GameObject* clone() = 0;

	virtual void damage(int damage = 0, bool slowed = false);
	virtual ~Zombie() {};
	bool isAlive();

	friend class Terrain;
};

