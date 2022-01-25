#include "Super_Zombie.h"

void Super_Zombie::take_damage(int x)
{
	hit_points -= x;
}

int Super_Zombie::get_hp()
{
	return hit_points;
}

int Super_Zombie::get_points()
{
	return points;
}

void Super_Zombie::color(int color_symbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_symbol);
}

void Super_Zombie::set_cursor(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Super_Zombie::print_on_terrain(int x, int y)
{
	set_cursor(x, y);
	color(color_symbol);
	cout << symbol;
}

void Super_Zombie::change_jump()
{
	jump = 0;
}

int Super_Zombie::get_jump()
{
	return jump;
}
