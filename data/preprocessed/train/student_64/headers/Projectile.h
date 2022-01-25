#pragma once
#include <vector>
#include <chrono>


#include "Time.h"
class Projectiles
{
private:
	std::vector<int> vector_proiectile;
	int x;
	int y;
	Time t,t1;
public:
	Projectiles();
	~Projectiles();
	Projectiles(int x,int y) : x(x),y(y){}

	void Move(std::chrono::system_clock::time_point& end1, std::chrono::system_clock::time_point& begin1);
};

