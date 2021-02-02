#include "Cherry_Bomb.h"

int Cherry_Bomb::get_order_number()
{
	return order_number;
}

int Cherry_Bomb::get_cost()
{
	return cost;
}

void Cherry_Bomb::set_cursor(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Cherry_Bomb::give_damage()
{
	return damage;
}