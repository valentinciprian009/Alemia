#include "Normal_Zombie.h"

void Normal_Zombie::take_damage(int x)
{
	hit_points -= x;
}

int Normal_Zombie::get_hp()
{
	return hit_points;
}

int Normal_Zombie::get_points()
{
	return points;
}

void Normal_Zombie::color(int color_symbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_symbol);
}

void Normal_Zombie::set_cursor(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Normal_Zombie::print_on_terrain(int x, int y)
{
	set_cursor(x, y);
	color(color_symbol);
	cout << symbol;
}