#pragma once
#include "IDrawable.h"

class Proiectil : public IDrawable
{
public:
	Point builtAround;
};

class Pea : public Proiectil {
public:
	int firstLaunch = 1;
	Point lastProiectilPosition;
	void Print(Point &p);
	void Draw(SegmentedContainer &c);
	void Delete(Point &p);
};

