#include "bullet.h"
#include <iostream>
void bullet:: gotoxy(int x, int y) {
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}
bullet::bullet(int x, int y)
{
	//COORD num;
	setcord(x, y);
	
	//gotoxy(x, y);
	//afiseaza();
	//std::cout << " ";
	//setcord(x + 1, y);
	//num = getcord();
	//while (num.X < 131)
	//{
	//	gotoxy(num.X , num.Y);
	//	std::cout << " ";
	//	x++;
	//	gotoxy(x, y);
	//	afiseaza();
	//	setcord(x, y);
	//	num = getcord();
	//	if (num.X == 131)
	//		break;
	//	Sleep(60);
	//		//delete this;
	//}


}
bullet::bullet()
{
	int y = 1;
}
COORD bullet::getcord()
{
	return this-> pos;
}
void bullet::setcord(int x, int y)
{
	pos.X = x;
	pos.Y = y;
}
void bullet::afiseaza()
{

	std::cout << "x";
}
void bullet::sterge()
{
	COORD num = getcord();
	gotoxy(num.X-1 , num.Y);
	std::cout << " ";
}
void bullet::setslow()
{
	slow = true;
}
bool bullet::getslow()
{
	return slow;
}