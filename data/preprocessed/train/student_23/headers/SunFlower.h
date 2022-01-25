#pragma once
#include "GAME.h"

using namespace chrono;

class SunFlower :public Plant
{
private:
	steady_clock::time_point trackTime;
public:
	SunFlower(int life, int price, int x, int y) : Plant(life, price, x, y) { trackTime = steady_clock::now(); };
	~SunFlower() {};
	void printInShop(int x, int y);
	void printInCadran(int x, int y);
	bool testTime(int time);
};