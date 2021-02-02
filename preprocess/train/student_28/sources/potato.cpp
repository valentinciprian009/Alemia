#include "potato.h"
potato::potato(int x,int y)
{
	Plant::setcord(x, y);
	Plant::setype('w');
	afiseaza(Plant::getcord());
	setLife(-5);
}
void  potato::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}
void  potato::sterge(COORD num)
{

	for (int j = 0; j < 3; j++)
	{
		gotoxy(num.X, num.Y + j);
		std::cout << " ";
	}
}
void potato::afiseaza(COORD num)
{
	for (int j = 0; j < 3; j++)
	{
		gotoxy(num.X, num.Y + j-2);
		std::cout << 'w';
	}
}