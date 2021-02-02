#pragma once
#include "IDrawable.h"

class Zombie : public IDrawable {
public:
	int health=100;
	std::string stare="incepator"; //se va schimba in castigator daca trece de teren
	Point builtAround;
	void Print(Point &p);
	void Draw(SegmentedContainer &c4);
	void Delete();
};

class BucketHeadZombie : public Zombie {
public:
	int health = 100;
	void Print(Point &p);
	void Draw(SegmentedContainer &c4);
	void Delete();
};
