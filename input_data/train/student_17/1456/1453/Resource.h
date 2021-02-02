#pragma once
#include "IDrawable.h"

class Resource : public IDrawable {
public:
	int valoare;
	int refreshRate;
	Point builtAround;
	virtual void Print(Point &p) = 0;
};

class Sun : public Resource {
public:
	int valoare = 50;
	int refreshRate = 2500;
	void Print(Point &p);
	void Draw(SegmentedContainer &c2);
	void Delete();
};
