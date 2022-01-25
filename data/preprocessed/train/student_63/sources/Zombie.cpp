#include "Zombie.h"



Zombie::Zombie(char img1, int x1, int y1, int color1, int dDmg,int tDmg, int hp) :
	Lifeform(img1,x1,y1,color1,hp)
{
	this->dDmg = dDmg;
	this->tDmg = tDmg;

}
void Zombie::update()
{
	move();
	Draw();
	if (getX() == 14) {
		set_finish();
		delete this;
	}
}


Zombie::~Zombie()
{
}
