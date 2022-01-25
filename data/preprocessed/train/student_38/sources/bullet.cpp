#include "bullet.h"

void Bullet::Draw(int x, int y)
{
	this->x = x;
	this->y = y;
	char bullet_char = 175;
	conOut(x,y) << bullet_char;



}
