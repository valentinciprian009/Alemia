#include "Field.h"



Field::Field()
{
	std::string line = "- - - - - -";
	C.push_back(line);
	line = "(        )";
	for (int i = 0; i < 3; i++)
		C.push_back(line);
	line = "_ _ _ _ _";
	A.X = 5;
	A.Y = 5;
	M.X = A.X + 4;
	M.Y = A.Y + 2;

}
Field::Field(int x, int y)
{
	std::string line = "- - - - -";
	C.push_back(line);
	line = "(        )";
	for (int i = 0; i < 3; i++)
		C.push_back(line);
	line = "_ _ _ _ _";
	C.push_back(line);
	A.X = x;
	A.Y = y;
	M.X = A.X + 4;
	M.Y = A.Y + 2;
	X = x;
	Y = y;

}
void Field::print()
{
	COORD aux{ A.X,A.Y };
	for (int i = 0; i < 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { aux.X,aux.Y });
		std::cout << C[i];
		aux.Y++;
	}
}


void Field::schimba(char c)
{
	C[2][4] = c;
}


Field::~Field()
{
}
