#include "sun.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
void sun::aprox_coord(short &x, short &y)
{
	int init_x = 51, init_y = 4;// punctele cel mai din dreapta sus (al careului galben)
	int aux_x = x - init_x;
	int aux_y = y - init_y;
	aux_x = aux_x / 7;//latura pe x + 1(bordura)
	aux_y = aux_y / 4;// latura pe y +1(bordura
	x = init_x + aux_x * 7 + 1;// ca sa nu fie pe margine
	y = init_y + aux_y * 4 ;// 
}
void sun::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}
void sun::setcord(short x,short y)
{
	pos.X = x;
	pos.Y = y;
}
COORD sun::getcord()
{
	return pos;
}
sun::sun()
{
	COORD num;
	srand(time(NULL));
	int n = rand() % 9 + 1;
	//aprox_coord( x,  y);
	if (n == 1)
	{
		num.X = 53;
		num.Y = 5;
		afiseaza(num);
	}
	if (n == 2)
	{
		num.X = 60;
		num.Y = 5;
		afiseaza(num);
	}
	if (n == 3)
	{
		num.X = 67;
		num.Y = 5;
		afiseaza(num);
	}
	if (n == 4)
	{
		num.X = 74;
		num.Y = 5;
		afiseaza(num);
	}
	if (n == 5)
	{
		num.X = 81;
		num.Y = 5;
		afiseaza(num);
	}
	if (n == 6)
	{
		num.X = 88;
		num.Y = 5;
		afiseaza(num);
	}
	if (n == 7)
	{
		num.X = 95;
		num.Y = 5;
		afiseaza(num);
	
	}
	if (n == 8)
	{
		num.X = 102;
		num.Y = 5;
		afiseaza(num);
	}
	if (n == 9)
	{
		num.X = 109;
		num.Y = 5;
		afiseaza(num);
	}
	aprox_coord(num.X, num.Y);
	setcord(num.X, num.Y);
}

void sun::afiseaza(COORD num)
{	
	
	gotoxy(num.X + 2, num.Y);
	std::cout << "*";
	gotoxy(num.X + 1, num.Y+1);
	std::cout << "*";
	gotoxy(num.X , num.Y+1);
	std::cout << "*";
	gotoxy(num.X -1, num.Y);
	std::cout << "*";
	gotoxy(num.X , num.Y-1);
	std::cout << "*";
	gotoxy(num.X+1, num.Y - 1);
	std::cout << "*";
}
void sun::sterge(COORD num)
{
	aprox_coord(num.X, num.Y);
	for (int j = 0; j < 3; j++)
	{
		gotoxy(num.X, num.Y + j);
		for (int i = 1; i < 6; i++)
			std::cout << " ";
	}
}