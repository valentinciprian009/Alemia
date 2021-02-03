#include "Sun.h"

void Sun::color(int color_symbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_symbol);
}

void Sun::set_cursor(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Sun::print_sun()
{
	for (auto i = vector_sun.begin(); i < vector_sun.end(); i++)
	{
		if (*i == 1)
		{
			int nr;
			nr = i - vector_sun.begin();
			switch (nr)
			{
			case 0:
				set_cursor(16, 2);
				color(color_symbol);
				cout << symbol;
				break;
			case 1:
				set_cursor(22, 2);
				color(color_symbol);
				cout << symbol;
				break;
			case 2:
				set_cursor(28, 2);
				color(color_symbol);
				cout << symbol;
				break;
			case 3:
				set_cursor(34, 2);
				color(color_symbol);
				cout << symbol;
				break;
			case 4:
				set_cursor(40, 2);
				color(color_symbol);
				cout << symbol;
				break;
			case 5:
				set_cursor(46, 2);
				color(color_symbol);
				cout << symbol;
				break;
			case 6:
				set_cursor(52, 2);
				color(color_symbol);
				cout << symbol;
				break;
			case 7:
				set_cursor(58, 2);
				color(color_symbol);
				cout << symbol;
				break;
			default:
				set_cursor(64, 2);
				color(color_symbol);
				cout << symbol;
				break;
			}
		}
	}
}

void Sun::set_sun()
{
	for (auto i = vector_sun.begin(); i < vector_sun.end(); i++)
	{
		if (*i == 0)
		{
			*i = 1;
			break;
		}
	}
}

Sun::Sun()
{
	for (int i = 0; i < 12; i++)
	{
		vector_sun.push_back(0);
	}
}