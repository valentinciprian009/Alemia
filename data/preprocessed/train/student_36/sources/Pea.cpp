#include "Pea.h"

Pea* Pea::mpInstance = NULL;

Pea& Pea::getInstance()
{
	if (mpInstance == NULL)
	{
		mpInstance = new Pea();
	}
	return *mpInstance;
}

int Pea::get_damage()
{
	return damage;
}

void Pea::color(int color_symbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_symbol);
}

void Pea::set_cursor(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Pea::print_on_terrain(int x, int y)
{
	set_cursor(x, y);
	color(color_symbol);
	cout << symbol;
}