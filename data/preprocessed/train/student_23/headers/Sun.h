#pragma once
#include "IDrawable.h"
using namespace std;

class Sun :public IDrawable
{
public:
	Sun();
	Sun(int x, int y) :IDrawable(x, y) {};
	~Sun();
	int getX() { return x; };
	int getY() { return y; };
};