#pragma once
#include <chrono>

using namespace std::chrono;

class PeaProjectile
{
	int x;
	int y;
public:
	time_point<steady_clock> timer = std::chrono::steady_clock::now();
	void draw(int x, int y);

	friend class Peashooter;
};