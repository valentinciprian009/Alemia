#include "Frozen_Pea.h"

Frozen_Pea* Frozen_Pea::mpInstance = NULL;

Frozen_Pea& Frozen_Pea::getInstance()
{
	if (mpInstance == NULL)
	{
		mpInstance = new Frozen_Pea();
	}
	return *mpInstance;
}

int Frozen_Pea::get_damage()
{
	return damage;
}

void Frozen_Pea::color(int color_symbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_symbol);
}

void Frozen_Pea::set_cursor(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Frozen_Pea::print_on_terrain(int x, int y)
{
	set_cursor(x, y);
	color(color_symbol);
	cout << symbol;
}