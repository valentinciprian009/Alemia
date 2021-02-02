#include "Peashooter.h"

void Peashooter::take_damage(int x)
{
	hit_points -= 2;
}

int Peashooter::get_hp()
{
	return hit_points;
}

int Peashooter::get_order_number()
{
	return order_number;
}

int Peashooter::get_cost()
{
	return cost;
}

void Peashooter::color(int color_symbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_symbol);
}

void Peashooter::set_cursor(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Peashooter::print_on_terrain(int x, int y)
{
	set_cursor(x, y);
	color(color_symbol);
	cout << symbol;
}