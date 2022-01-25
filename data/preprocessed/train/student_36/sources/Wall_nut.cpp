#include "Wall_nut.h"

void Wall_nut::take_damage(int x)
{
	hit_points -= 2;
}

int Wall_nut::get_hp()
{
	return hit_points;
}

int Wall_nut::get_order_number()
{
	return order_number;
}

int Wall_nut::get_cost()
{
	return cost;
}

void Wall_nut::color(int color_symbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_symbol);
}

void Wall_nut::set_cursor(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Wall_nut::print_on_terrain(int x, int y)
{
	set_cursor(x, y);
	color(color_symbol);
	cout << symbol;
}