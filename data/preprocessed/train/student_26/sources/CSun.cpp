#include "CSun.h"
#include <time.h>
#include <Windows.h>
#include <vector>
#include <ctime>
#include <random>

void CSun::set_y_beg()
{
	this->y_beg = 0;
}

void CSun::set_y_end()
{
	this->y_end = 5;
}

void CSun::set_x_beg()
{
	this->x_beg = 16 + pozitie * 10;
}


void CSun::set_x_end()
{
	this->x_end = 24 + pozitie * 10;
}


void CSun::setPozitie()
{
	srand(time(NULL));
	this->pozitie = rand() % 8;

}

void CSun::deleteSun(int numar_chenar)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int x = 16 + 10 * numar_chenar;x < 25 + 10 * numar_chenar;x++)
	{
		for (int y = 0;y <= 5;y++)
		{
			conOut(y,x) << ' ';
		}
	}
}

void SetColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

void CSun::draw()
{
	


	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	// schimb la culoarea galben
	SetColor(6);

	char c = 219;

		for (int x = get_x_beg();x <= get_x_end();x++)
		{
			for (int y = 0;y <= 5;y++)
			{
				conOut(y,x) << c;
			}
		}
	

	// revin la culoarea default
	SetColor(7);
}

vector<int> CSun::spawnPositions(8, 0);
CSun::CSun(string toGetVector)
{

}
CSun::CSun()
{
	setPozitie();

	// verific daca nu cumva s a spawnat in locul ala
	while (spawnPositions[this->pozitie] == 1)
	{
		setPozitie();
	}
	spawnPositions[this->pozitie] = 1;
	set_x_beg();
	set_x_end();
	set_y_beg();
	set_y_end();

}



CSun::~CSun()
{
}
