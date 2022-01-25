#pragma once
#include "GameObject.h"
#include <time.h>
#include <chrono>
#include <string>

using namespace std::chrono;

class Plant : public GameObject
{
protected:
	int bitesCount;
	int price;

public:
	time_point<steady_clock> skillTimer = steady_clock::now();

	int buyTimer = 0;
	virtual void draw(int x, int y) = 0;
	virtual void draw(int y) = 0;
	virtual void useSkill() = 0;
	virtual std::string identity() = 0;
	virtual void damage(int damage = 0, bool slowed = false);
	GameObject* clone() { return this; }

	void setStrength(int x);
	void setPrice(int x);
	int getPrice();
	time_point<steady_clock> getTimer();
	time_point<steady_clock> resetTimer();
	bool isAlive();
	virtual ~Plant() {};
};