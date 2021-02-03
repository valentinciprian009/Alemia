#include "Monster.h"
Monster::Monster()
{
	;
}
void  Monster:: setLife(int newlife)
{
	health = health-newlife;
		
}
void  Monster::setSlowed()
{
	 slowed = true;
}
void  Monster::setSpeed()
{
	if(slowed)
 speed =speed/2 ;
}
void  Monster::setValue(int val)
{
	value = val;
}
int   Monster::getLife()
{
	return health;
}
int   Monster::getValue()
{
	return value;
}
COORD Monster::getcord()
{
	return pos;
}
void  Monster::setcord(int x, int y)
{
	pos.X = x;
	pos.Y = y;
}
void  Monster::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}
void  Monster::sterge(COORD num)
{

	for (int j = 0; j < 3; j++)
	{
		gotoxy(num.X, num.Y + j);
			std::cout << " ";
	}
}
void Monster::afiseaza(COORD num)
{
	for (int j = 0; j < 3; j++)
	{
		gotoxy(num.X, num.Y + j);
		std::cout << 'z';
	}
}
Monster::Monster(int x,int y)
{
	setcord(x, y);
	afiseaza(pos);

}