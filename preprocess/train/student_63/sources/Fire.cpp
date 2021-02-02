#include "Fire.h"

Fire::Fire()
{
	bullet_pos.X = 0;
	bullet_pos.Y = 0;
	B = '>';
	reset_bullet_pos.X = 0;
	reset_bullet_pos.Y = 0;
}

Fire::Fire(int x, int y, char c)
{
	bullet_pos.X = x;
	bullet_pos.Y = y;
	B = c;
	reset_bullet_pos.X = 0;
	reset_bullet_pos.Y = 0;
}

void Fire::print()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { bullet_pos.X + 1,bullet_pos.Y });
	std::cout << B;
}

void Fire::sterge()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 00);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bullet_pos);
	std::cout << ' ';
}


void Fire::set_bullet_pos(COORD aux)
{
	bullet_pos.X = aux.X + 1;
	bullet_pos.Y = aux.Y;
	reset_bullet_pos.X = aux.X + 1;
	reset_bullet_pos.Y = aux.Y;
}

void Fire::set_bullet_pos_from_plant(COORD aux)
{
	bullet_pos.X = aux.X + 1;
	bullet_pos.Y = aux.Y;
}

void Fire::reset_bullet_poss()
{
	bullet_pos.X = reset_bullet_pos.X;
	bullet_pos.Y = reset_bullet_pos.Y;
}


Fire::~Fire()
{
}