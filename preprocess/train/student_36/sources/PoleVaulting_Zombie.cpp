#include "PoleVaulting_Zombie.h"

void PoleVaulting_Zombie::take_damage(int x)
{
	hit_points -= x;
}

int PoleVaulting_Zombie::get_hp()
{
	return hit_points;
}

int PoleVaulting_Zombie::get_points()
{
	return points;
}

void PoleVaulting_Zombie::color(int color_symbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_symbol);
}

void PoleVaulting_Zombie::set_cursor(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void PoleVaulting_Zombie::print_on_terrain(int x, int y)
{
	set_cursor(x, y);
	color(color_symbol);
	cout << symbol;
}

void PoleVaulting_Zombie::change_jump()
{
	jump = 0;
}

int PoleVaulting_Zombie::get_jump()
{
	return jump;
}
