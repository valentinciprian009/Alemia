#pragma once
#include "IDrawable.h"
#include "Proiectil.h"

class Plant : public IDrawable {
public:
	int cost;
	int nrMaxMuscaturi;
	Point builtAround;
	Pea pea;
	virtual void Print(Point &pt) = 0;
	virtual void Delete(Point &pt) = 0;
};

class Peashooter : public Plant {
public:
	int cost = 100;
	int nrMaxMuscaturi = 1;
	void Print(Point &pt);
	void Draw(SegmentedContainer &c3);
	void Delete(Point &pt);
};

class SunFlower : public Plant {
public:
	int cost = 50;
	int nrMaxMuscaturi = 1;
	void Print(Point &pt);
	void Draw(SegmentedContainer &c3);
	void Delete(Point &pt);
};