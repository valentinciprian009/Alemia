#pragma once
#include "Proiectile.h"
class Pea :
	public Proiectile
{
private:
	int damage;
	int x, y;
public:
	Pea(int x, int y) :Proiectile(x, y) {}
	void draw();
	void update();
	~Pea();

};

