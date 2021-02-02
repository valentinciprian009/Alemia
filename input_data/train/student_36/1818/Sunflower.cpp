#include "Sunflower.h"

void Sunflower::take_damage(int x)
{
	hit_points -= 2;
}

int Sunflower::get_hp()
{
	return hit_points;
}

int Sunflower::get_order_number()
{
	return order_number;
}

int Sunflower::get_cost()
{
	return 0;
}

void Sunflower::color(int color_symbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_symbol);
}

void Sunflower::set_cursor(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Sunflower::print_on_terrain(int x, int y)
{
	set_cursor(x, y);
	color(color_symbol);
	cout << symbol;
}