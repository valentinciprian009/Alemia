#pragma once
#include "GAME.h"

using namespace chrono;

class FrozenPea :public Plant
{
private:
	steady_clock::time_point trackTime;
public:
	FrozenPea(int life, int price, int X, int Y) :Plant(life, price, X, Y) { trackTime = steady_clock::now(); };
	void printInShop(int x, int y);
	void printInCadran(int x, int y);
	bool testTime(int time);
};