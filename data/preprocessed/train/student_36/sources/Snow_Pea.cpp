#include "Snow_Pea.h"

void Snow_Pea::take_damage(int x)
{
	hit_points -= 2;
}

int Snow_Pea::get_hp()
{
	return hit_points;
}

int Snow_Pea::get_order_number()
{
	return order_number;
}

int Snow_Pea::get_cost()
{
	return cost;
}

void Snow_Pea::print_on_terrain(int x, int y)
{
	set_cursor(x, y);
	color(color_symbol);
	cout << symbol;
}

void Snow_Pea::color(int color_symbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_symbol);
}

void Snow_Pea::set_cursor(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}