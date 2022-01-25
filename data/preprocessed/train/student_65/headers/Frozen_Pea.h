#pragma once
#include "Proiectile.h"
#include "Terrain.h"
class Frozen_Pea :
	public Proiectile
{
public:
	Frozen_Pea(int x, int y,int damage) :Proiectile(x, y,damage,"Frozen_Pea") { }
	void draw();
	void update();
	~Frozen_Pea();
};


