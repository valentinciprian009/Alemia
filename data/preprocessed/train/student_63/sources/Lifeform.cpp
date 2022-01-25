#include "Lifeform.h"



Lifeform::Lifeform(char img1, int x1, int y1, int color1,int hp):
 Entity(img1,x1,y1,color1)
{
	this->hp = hp;
}


Lifeform::~Lifeform()
{
}
