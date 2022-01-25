#pragma once
#include "Lifeform.h"
class Zombie :
	public Lifeform
{
	int dDmg;
	int tDmg;


public:
	Zombie(char img1, int x1, int y1, int color1, int dDmg,int tDmg, int hp);
	~Zombie();
	void update()final override;
	void move()
	{
		Entity::setX(getX() - 1);
	}
};

