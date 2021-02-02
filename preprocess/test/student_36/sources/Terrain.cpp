#include "Terrain.h"

Terrain* Terrain::mpInstance = NULL;

Terrain& Terrain::getInstance()
{
	if (mpInstance == NULL)
		mpInstance = new Terrain();
	return *mpInstance;
}

void Terrain::color(int color_symbol)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color_symbol);
}

void Terrain::gotoXY(int x, int y)
{
	COORD coord = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Terrain::print_on_terrain(int x, int y)
{
	char t[110];
	FILE* f;
	f = fopen("Tabla_de_joc.txt", "r");

	int nr_lines = 0;
	color(color_symbol);
	while (nr_lines!=23)
	{
		fgets(t, 110, f);
		std::cout << t;
		nr_lines++;
	}

	color(7);
	while (!feof(f))
	{
		fgets(t, 110, f);
		std::cout << t;
	}

	color(2);
	gotoXY(4, 6);
	std::cout << "Ps";

	color(6);
	gotoXY(4, 9);
	std::cout << "Sf";

	color(4);
	gotoXY(4, 12);
	std::cout << "CB";

	color(14);
	gotoXY(4, 15);
	std::cout << "Wn";

	color(1);
	gotoXY(4, 18);
	std::cout << "SP";

	color(15);
}